#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H

#include <tema.h>
#include <pregunta.h>
#include <asignatura.h>

class Cuestionario
{
public:
    Cuestionario();
    Cuestionario(Tema *tema);

    Pregunta *siguiente();
    void terminar();
    const QStringList &terminos() const;

    float score() const;

    const QList<Pregunta *> &preguntas() const;
    const QString nombreTema() const;
    const QString nombreAsig() const;
    int totalPreguntas();
    bool hayMasPreguntas();

    int mostradas() const;

private:
    float m_score;
    Tema *m_tema;
    Asignatura *m_asignatura;
    QList<Pregunta*> m_preguntas;
    QStringList m_terminos;
    int m_mostradas;
};

#endif // CUESTIONARIO_H
