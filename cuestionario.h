#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H
#include "tema.h"
#include "pregunta.h"

#include <QList>

class Cuestionario{

private:

    Tema *m_tema;
    QList<Pregunta*> m_preguntas;
    QStringList m_terminos;
    float score;

public:
    Cuestionario();
    Cuestionario(Tema *tema);
    Pregunta* siguiente();
    const QStringList &terminos() const;
};

#endif // CUESTIONARIO_H
