#ifndef CREDITOSFORM_H
#define CREDITOSFORM_H


#include <QWidget>
#include <QDebug>
#include <QInputDialog>
#include <QAbstractButton>
#include <QMessageBox>

#include <cuestionario.h>

namespace Ui {
class CreditosForm;
}

class CreditosForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreditosForm(QWidget *parent = nullptr);
    ~CreditosForm();
    void CreditosCargados();
private slots:
    void onItemSelectionChanged();
private:
    Ui::CreditosForm *ui;
};

#endif // CREDITOSFORM_H
