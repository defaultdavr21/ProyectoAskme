#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm){
    ui->setupUi(this);
    //connect(ui->Tblcreditos, SIGNAL(itemSelectionChanged()), this, SLOT(onItemSelectionChanged()));
    CreditosCargados();
}

CreditosForm::~CreditosForm(){
    delete ui;
}
void CreditosForm::CreditosCargados(){

    /*ui->Tblcreditos->setRowCount(2);
    ui->Tblcreditos->setColumnCount(2);

    QStringList header;
    header << "Autor" << "Coautor";
    ui->Tblcreditos->setHorizontalHeaderLabels(header);

    QStringList datos;
    datos << "Rodrigo Tufiño" << "David Ramos";
    datos << "Ingeniero " << "Estudiante";
    datos << " " << "Estudiante";

    for (int row = 0; row < ui->Tblcreditos->rowCount(); ++row) {
        for (int col = 0; col < ui->Tblcreditos->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(datos[col]);
            ui->Tblcreditos->setItem(row, col, item);
        }
    }*/
}
void CreditosForm::onItemSelectionChanged(){

}
