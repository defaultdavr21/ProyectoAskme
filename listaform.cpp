#include "listaform.h"
#include "ui_listaform.h"

ListaForm::ListaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaForm){
    ui->setupUi(this);
    ui->tableCargar->setColumnCount(1);
    ui->tableCargarCopt->setColumnCount(1);
    connect(ui->cmbtemas, SIGNAL(currentIndexChanged(int)), this, SLOT(cargarTablaT()));
    connect(ui->cmbtemas, SIGNAL(currentIndexChanged(int)), this, SLOT(cargarTablaC()));

}
ListaForm::~ListaForm(){

    delete ui;
}

void ListaForm::setAsignaturas(QList<Asignatura *> &asignaturas)
{
    m_asignaturas = &asignaturas;
}


void ListaForm::cargarAsignaturas(){
    ui->cmbasignaturas->clear();
    foreach(Asignatura *w, *m_asignaturas){
        ui->cmbasignaturas->addItem(w->nombre());
    }


}

void ListaForm::on_cmbasignaturas_currentIndexChanged(int index){
    ui->cmbtemas->clear();
    if (index >= 0 && index < m_asignaturas->size()){
        Asignatura *q = m_asignaturas->at(index);
        foreach(Tema *t, q->temas()){
            ui->cmbtemas->addItem(t->nombre());
        }
    }
    cargarTablaT();
    cargarTablaC();
}
void ListaForm::cargarTablaT(){

    ui->tableCargar->clearContents();
    ui->tableCargar->setRowCount(0);

    int rowCount = 0;

    int asignaturaIndex = ui->cmbasignaturas->currentIndex();
    if (asignaturaIndex >= 0 && asignaturaIndex < m_asignaturas->size()){
        Asignatura* asignatura = m_asignaturas->at(asignaturaIndex);

        int temaIndex = ui->cmbtemas->currentIndex();
        if (temaIndex >= 0 && temaIndex < asignatura->temas().size()){
            Tema* tema = asignatura->temas().at(temaIndex);

            ui->tableCargar->setColumnCount(1);
            ui->tableCargar->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            foreach (Apunte* apunte, tema->apuntes()){
                int rowPosition = ui->tableCargar->rowCount();
                ui->tableCargar->insertRow(rowCount);
                QTableWidgetItem* itemTermino = new QTableWidgetItem(apunte->termino());
                ui->tableCargar->setItem(rowCount, 0, itemTermino);
            }
        }
    }

}
void ListaForm::cargarTablaC(){

    ui->tableCargarCopt->clearContents();
    ui->tableCargarCopt->setRowCount(0);

    int rowCount = 0;

    int asignaturaIndex = ui->cmbasignaturas->currentIndex();
    if (asignaturaIndex >= 0 && asignaturaIndex < m_asignaturas->size())
    {
        Asignatura* asignatura = m_asignaturas->at(asignaturaIndex);

        int temaIndex = ui->cmbtemas->currentIndex();
        if (temaIndex >= 0 && temaIndex < asignatura->temas().size())
        {
            Tema* tema = asignatura->temas().at(temaIndex);

            ui->tableCargarCopt->setColumnCount(1);
            ui->tableCargarCopt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            foreach (Apunte* apunte, tema->apuntes()){

                int rowPosition = ui->tableCargarCopt->rowCount();
                ui->tableCargarCopt->insertRow(rowCount);

                QTableWidgetItem* itemConcepto = new QTableWidgetItem(apunte->concepto());
                ui->tableCargarCopt->setItem(rowCount, 0, itemConcepto);

            }
        }
    }


}
