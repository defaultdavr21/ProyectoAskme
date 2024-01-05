#include "cuestionario.h"
Cuestionario::Cuestionario(){

}
const QStringList &Cuestionario::terminos() const{
    return m_terminos;
}

Cuestionario::Cuestionario(Tema *tema) : m_tema(tema){

    foreach(Apunte *a,m_tema->apuntes()){
        m_preguntas.append(new Pregunta(a));
        m_terminos.append(a->termino());
    }
}

Pregunta *Cuestionario::siguiente(){

    foreach(Pregunta *p,m_preguntas){
        if (!p->respondida()){
            return p;
        }
    }
    return nullptr;

}
