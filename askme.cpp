#include "askme.h"
#include "ui_askme.h"

Askme::Askme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Askme)
{
    ui->setupUi(this);
    cargarDatos();
}

Askme::~Askme()
{
    delete ui;
}

void Askme::on_apunteTomado(Apunte *apunte){

    guardar();

}

void Askme::on_cuestionarioCreado(Cuestionario *cuestionario)
{
    PreguntaForm *w = new PreguntaForm(this);
    w->setCuestionario(cuestionario);
    connect(w, SIGNAL(PreguntaCreada(Cuestionario*)), this, SLOT(on_PreguntaCreada(Cuestionario*)));
    cargarSubVentana(w);
}

void Askme::on_PreguntaCreada(Cuestionario *cuestionario)
{
    cuestionario->terminar();
    ScoreForm *w = new ScoreForm(this);
    w->setDatos(cuestionario);
    cargarSubVentana(w);

    qDebug() << "Preguntas contestadas. Abriendo ResultadosForm...";
}

void Askme::cargarSubVentana(QWidget *ventana)
{
    auto sub = ui->mdiArea->addSubWindow(ventana);
    sub->show();
}
void Askme::guardar(){
    QFile file("apuntes.csv");
    qDebug() << "Intentando abrir el archivo para escribir...";
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Archivo abierto correctamente.";
        QTextStream salida(&file);
        salida << "Asignatura\tTema\tTermino\tConcepto\n";
        foreach(Asignatura *a, m_asignaturas)
        {
            QString nombreAsignatura = a->nombre();
            foreach(Tema *t, a->temas())
            {
                QString nombreTema = t->nombre();
                foreach (Apunte *ap, t->apuntes())
                {
                    QString termino = ap->termino();
                    QString concepto = ap->concepto();

                    salida << nombreAsignatura << "\t" << nombreTema << "\t" << termino << "\t" << concepto << "\n";
                }
            }
        }
        file.close();
        qDebug() << "Archivo cerrado correctamente.";
    }
    else
    {
        QMessageBox::critical(this, "Agregar apunte", "No se pudieron guardar los datos");
        qDebug() << "Error al abrir el archivo para escribir.";
    }
}

void Askme::cargarDatos(){


   QFile file("apuntes.csv");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream entrada(&file);
        entrada.readLine();
        while(!entrada.atEnd())
        {
            QString linea = entrada.readLine();
            QStringList datos = linea.split("\t");
            if(datos.size() >= 4)
            {
                QString nombreAsignatura = datos[0].trimmed();
                QString nombreTema = datos[1].trimmed();
                QString termino = datos[2].trimmed();
                QString concepto = datos[3].trimmed();
                Asignatura *asignatura = nullptr;
                Tema *tema = nullptr;


                foreach(Asignatura *a, m_asignaturas)
                {
                    if(a->nombre() == nombreAsignatura)
                    {
                        asignatura = a;
                        foreach(Tema *t, a->temas())
                        {
                            if(t->nombre() == nombreTema)
                            {
                                tema = t;
                                break;
                            }
                        }
                        break;
                    }
                }
                if (!asignatura)
                {
                    asignatura = new Asignatura(nombreAsignatura);
                    m_asignaturas.append(asignatura);
                }
                if (!tema)
                {
                    tema = new Tema(nombreTema);
                    asignatura->agregarTema(tema);
                }
                Apunte *apunte = new Apunte(termino, concepto);
                tema->agregarApunte(apunte);
            }
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Cargar datos", "No se pudieron cargar los datos");
    }
}

void Askme::on_actionNuevo_triggered()
{
    ApunteForm *w = new ApunteForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();

    connect(w, SIGNAL(apunteTomado(Apunte*)), this, SLOT(on_apunteTomado(Apunte*)));

    cargarSubVentana(w);
}


void Askme::on_actionGenerar_triggered(){
    CuestionarioForm *w = new CuestionarioForm(this);
    w->setAsignaturas(m_asignaturas);
    w->cargarAsignaturas();
    connect(w, SIGNAL(cuestionarioCreado(Cuestionario*)), this, SLOT(on_cuestionarioCreado(Cuestionario*)));
    cargarSubVentana(w);

}
void Askme::on_actionLista_triggered(){

    ListaForm *a = new ListaForm(this);
    a->setAsignaturas(m_asignaturas);
    a->cargarAsignaturas();
    connect(a, SIGNAL(apunteTomado(Apunte*)), this, SLOT(on_apunteTomado(Apunte*)));
    cargarSubVentana(a);
    guardar();

}
void Askme::on_actionCreditos_triggered()
{
    CreditosForm *w = new CreditosForm(this);
    cargarSubVentana(w);
}
void Askme::on_actionSalir_triggered() {
    QMessageBox::StandardButton respuesta = QMessageBox::question(this, "Confirmar salida",
                                                                   "¿Estás seguro de que deseas salir?",
                                                                   QMessageBox::Yes | QMessageBox::Cancel);

    if (respuesta == QMessageBox::Yes) {
        this->parentWidget()->close();
    } else {

    }
}
