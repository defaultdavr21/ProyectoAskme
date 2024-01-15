#include "listaform.h"
#include "ui_listaform.h"

ListaForm::ListaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaForm){
    ui->setupUi(this);
    connect(ui->cmbasignaturas, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbasignaturas_currentIndexChanged(int)));
    QList<Asignatura *> newAsignaturas;
    setAsignaturas(newAsignaturas);
    cargarAsignaturas();
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

    qDebug() << "Número de asignaturas en el combo box: " << ui->cmbasignaturas->count();
}

void ListaForm::on_cmbasignaturas_currentIndexChanged(int index){
    ui->cmbtemas->clear();
    if (index >= 0 && index < m_asignaturas->size()){
        Asignatura *q = m_asignaturas->at(index);
        foreach(Tema *t, q->temas()){
            ui->cmbtemas->addItem(t->nombre());
        }
    }
    cargarAsignaturas();
}

