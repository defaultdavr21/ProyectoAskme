#ifndef QUIZFORM_H
#define QUIZFORM_H

#include <QWidget>
#include <asignatura.h>
#include <cuestionario.h>

namespace Ui {
class QuizForm;
}

class QuizForm : public QWidget
{
    Q_OBJECT

public:
    explicit QuizForm(QWidget *parent = nullptr);
    void cargarAsignaturas();
    ~QuizForm();

    void setUi(Ui::QuizForm *newUi);
    void setAsignaturas(QList<Asignatura *> &newAsignaturas);
private slots:

    void on_cmbasignaturas_currentIndexChanged(int index);
    void on_buttonBox_accepted();

private:
    Ui::QuizForm *ui;
    QList<Asignatura*> *m_asignaturas;
    QList<Cuestionario> m_cuestionario;


};

#endif // QUIZFORM_H
