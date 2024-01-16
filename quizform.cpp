#include "quizform.h"
#include "ui_quizform.h"

QuizForm::QuizForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuizForm){
    ui->setupUi(this);
}

QuizForm::~QuizForm(){
    delete ui;
}

void QuizForm::setUi(Ui::QuizForm *newUi)
{
    ui = newUi;
}

void QuizForm::setAsignaturas(QList<Asignatura *> &Asignaturas)
{
    m_asignaturas = &Asignaturas;
}
void QuizForm::cargarAsignaturas()
{
    ui->cmbasignaturaQ->clear();
    foreach(Asignatura *a, *m_asignaturas){
        ui->cmbasignaturaQ->addItem(a->nombre());
    }
}

void QuizForm::on_cmbasignaturas_currentIndexChanged(int index){
    ui->cmbtemas->clear();
    if (index >= 0 && index < m_asignaturas->size()){
        Asignatura *q = m_asignaturas->at(index);
        foreach(Tema *t, q->temas()){
            ui->cmbtemas->addItem(t->nombre());
        }
    }
}

void QuizForm::on_buttonBox_accepted(){

    int indexAsignatura= ui->cmbasignaturaQ->currentIndex();
    int indextema= ui->cmbtemas->currentIndex();
    Tema *t= m_asignaturas->at(indexAsignatura)->temas().at(indextema);
    //m_cuestionario = new Cuestionario(t);

}

