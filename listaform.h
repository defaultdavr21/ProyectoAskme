#ifndef LISTAFORM_H
#define LISTAFORM_H

#include <QWidget>
#include <QDebug>
#include <QInputDialog>
#include <QAbstractButton>
#include <QMessageBox>

#include<asignatura.h>

namespace Ui {
class ListaForm;
}

class ListaForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListaForm(QWidget *parent = nullptr);
    void setAsignaturas(QList<Asignatura *> &newAsignaturas);
    void cargarAsignaturas();
    void cargarTabla();
    ~ListaForm();


private slots:
    void on_cmbasignaturas_currentIndexChanged(int index);

private:
    Ui::ListaForm *ui;
    QList<Asignatura *> *m_asignaturas;
};

#endif // LISTAFORM_H
