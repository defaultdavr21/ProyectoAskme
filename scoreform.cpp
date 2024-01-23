#include "scoreform.h"
#include "ui_scoreform.h"

ScoreForm::ScoreForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreForm){
    ui->setupUi(this);

}

ScoreForm::~ScoreForm(){
    delete ui;
}

void ScoreForm::setDatos(Cuestionario *cuestionario){

    if (cuestionario){
        m_cuestionario = cuestionario;
        resultado();
    }
    else{

    }
}

void ScoreForm::resultado(){

    float score = m_cuestionario->score();
    QString tema = m_cuestionario->nombreTema();
    QString asig= m_cuestionario->asignatura();
    QString porcentaje = QString::number(score, 'f', 2) + "%";

    ui->labelscore->setText(porcentaje);
    ui->labeltema->setText(tema);
    ui->labelasignatura->setText(asig);


    QList<Pregunta *> preguntas = m_cuestionario->preguntas();

    ui->tableRes->setRowCount(preguntas.size());
    ui->tableRes->setColumnCount(2);

    ui->tableRes->setHorizontalHeaderLabels({"Término", "Respuesta"});
    ui->tableRes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableRes->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < preguntas.size(); ++i){
    QTableWidgetItem *terminoItem = new QTableWidgetItem(preguntas[i]->apunte()->termino());
    QTableWidgetItem *correctoItem = new QTableWidgetItem(preguntas[i]->correcta() ? "Correcta" : "Incorrecta");

    ui->tableRes->setItem(i, 0, terminoItem);
    ui->tableRes->setItem(i, 1, correctoItem);
    }

}


void ScoreForm::on_btcerrar_released(){
    try {
    qDebug() << "Cerrando la ventana...";
    this->parentWidget()->close();
    } catch (const std::exception &e) {
    qDebug() << "Excepción al cerrar la ventana:" << e.what();
    } catch (...) {
    qDebug() << "Excepción desconocida al cerrar la ventana.";
    }
}
