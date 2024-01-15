#include "listaform.h"
#include "ui_listaform.h"

ListaForm::ListaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaForm){
    ui->setupUi(this);

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
    cargarTabla();
}
void ListaForm::cargarTabla(){

    ui->tableCargar->clearContents();
        ui->tableCargar->setRowCount(0);

        int rowCount = 0;

        int asignaturaIndex = ui->cmbasignaturas->currentIndex();
        if (asignaturaIndex >= 0 && asignaturaIndex < m_asignaturas->size())
        {
            Asignatura* asignatura = m_asignaturas->at(asignaturaIndex);

            int temaIndex = ui->cmbtemas->currentIndex();
            if (temaIndex >= 0 && temaIndex < asignatura->temas().size())
            {
                Tema* tema = asignatura->temas().at(temaIndex);

                foreach (Apunte* apunte, tema->apuntes())
                {
                    // Insertar nueva fila en la tabla
                    ui->tableCargar->insertRow(rowCount);

                    // Rellenar celdas con datos
                    QTableWidgetItem* itemTermino = new QTableWidgetItem(apunte->termino());
                    ui->tableCargar->setItem(rowCount, 0, itemTermino);

                    QTableWidgetItem* itemConcepto = new QTableWidgetItem(apunte->concepto());
                    ui->tableCargar->setItem(rowCount, 1, itemConcepto);

                    // Incrementar el contador de filas
                    rowCount++;
                }
            }
        }
    }

