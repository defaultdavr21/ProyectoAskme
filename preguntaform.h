#ifndef PREGUNTAFORM_H
#define PREGUNTAFORM_H

#include <QWidget>

namespace Ui {
class PreguntaForm;
}

class PreguntaForm : public QWidget
{
    Q_OBJECT

public:
    explicit PreguntaForm(QWidget *parent = nullptr);
    ~PreguntaForm();

private:
    Ui::PreguntaForm *ui;
};

#endif // PREGUNTAFORM_H
