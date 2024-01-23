#ifndef PREGUNTAFORM_H
#define PREGUNTAFORM_H

#include <QWidget>
#include <QDebug>

#include "cuestionario.h"
#include "scoreform.h"

namespace Ui {
class PreguntaForm;
}

class PreguntaForm : public QWidget
{
    Q_OBJECT

public:
    explicit PreguntaForm(QWidget *parent = nullptr);
    ~PreguntaForm();


    void setCuestionario(Cuestionario *newCuestionario);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();
signals:
    void PreguntaCreada(Cuestionario *cuestionario);

private:
    Ui::PreguntaForm *ui;
    Cuestionario *m_cuestionario;
    Pregunta *m_pregunta;

    void cargarDatos();
    void siguiente();
    void obtenerPregunta();
};

#endif // PREGUNTAFORM_H
