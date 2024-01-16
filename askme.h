#ifndef ASKME_H
#define ASKME_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QFile>
#include <QTextStream>
#include <QDir>

#include "apunteform.h"
#include "quizform.h"
#include "asignatura.h"
#include "listaform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Askme; }
QT_END_NAMESPACE

class Askme : public QMainWindow
{
    Q_OBJECT

public:
    Askme(QWidget *parent = nullptr);
    ~Askme();

public slots:
    void on_apunteTomado(Apunte *apunte);

private slots:
    void on_actionNuevo_triggered();

    void on_actionLista_triggered();


    void on_actionGenerar_triggered();

private:
    Ui::Askme *ui;
    void cargarSubVentana(QWidget *ventana);
    void cargarLista(QWidget *lista);
    void cargarDatos();
    void guardar();
    void agregartabla();


    QList<Asignatura*> m_asignaturas;

};
#endif // ASKME_H
