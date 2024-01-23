#ifndef SCOREFORM_H
#define SCOREFORM_H

#include <QWidget>
#include <QString>
#include <QDebug>

#include <cuestionario.h>
#include <preguntaform.h>

namespace Ui {
class ScoreForm;
}

class ScoreForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreForm(QWidget *parent = nullptr);
    ~ScoreForm();
    void setDatos(Cuestionario *cuestionario);
    void resultado();

private slots:
    void on_btcerrar_released();

private:
    Ui::ScoreForm *ui;
    Cuestionario *m_cuestionario;


};

#endif // SCOREFORM_H
