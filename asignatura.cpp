#include "asignatura.h"

const QString &Asignatura::nombre() const{
    return m_nombre;
}

const QList<Tema *> &Asignatura::temas() const{
    return m_temas;
}


Asignatura::Asignatura(const QString &nombre) : m_nombre(nombre){

}

void Asignatura::agregarTemas(Tema *tema){

}
const QString Asignatura::toString() const{

    QString str= "Asignatura: " + m_nombre+" \n";
    foreach(Tema *t, m_temas){
        str += "\t " + t->toString() +"\n";
    }
    return str;

}
