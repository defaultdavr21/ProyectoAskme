#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <QString>
#include <QList>
#include "tema.h"

class Asignatura{

private:
    QString m_nombre;
    QList<Tema*> m_temas;

public:
    Asignatura();
    Asignatura(const QString &nombre);
    void agregarTemas(Tema* tema);
    const QString &nombre() const;
    const QList<Tema *> &temas() const;
    const QString toString() const;

};

#endif // ASIGNATURA_H
