#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm)
{
    ui->setupUi(this);
    connect(ui->Tblcreditos, SIGNAL(itemSelectionChanged()), this, SLOT(onItemSelectionChanged()));

    // Llama a CreditosCargados aquí para cargar la información en la tabla
    CreditosCargados();
}

CreditosForm::~CreditosForm()
{
    delete ui;
}

void CreditosForm::CreditosCargados()
{
    ui->Tblcreditos->clearContents();
    ui->Tblcreditos->setRowCount(0);

    int rowCount = 0;

    // Configurar información en las celdas del QTableWidget según tus necesidades
    ui->Tblcreditos->setItem(rowCount, 0, new QTableWidgetItem("Autor 1"));
    ui->Tblcreditos->setItem(rowCount, 1, new QTableWidgetItem("Coautor 1"));
    rowCount++;

    ui->Tblcreditos->setItem(rowCount, 0, new QTableWidgetItem("Profesión"));
        ui->Tblcreditos->setSpan(rowCount, 0, 1, 2);
    rowCount++;

    ui->Tblcreditos->setItem(rowCount, 0, new QTableWidgetItem("http://www.ejemplo.com"));
    ui->Tblcreditos->setSpan(rowCount, 0, 1, 2);
    rowCount++;

    ui->Tblcreditos->setItem(rowCount, 0, new QTableWidgetItem("correo@example.com"));
    ui->Tblcreditos->setSpan(rowCount, 0, 1, 2);

    // Configurar las cabeceras de las columnas
    ui->Tblcreditos->setHorizontalHeaderLabels({"Autor", "Coautor"});

    // Ajustar el tamaño de las columnas para que se expandan
    ui->Tblcreditos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void CreditosForm::onItemSelectionChanged()
{
    // Puedes implementar lógica adicional aquí si es necesario
}
