#include "pregunta.h"

bool Pregunta::corecta() const
{
    return m_corecta;
}

void Pregunta::setCorecta(bool newCorecta)
{
    m_corecta = newCorecta;
}

bool Pregunta::respondida() const
{
    return m_respondida;
}

void Pregunta::setRespondida(bool newRespondida)
{
    m_respondida = newRespondida;
}

Apunte *Pregunta::apunte() const
{
    return m_apunte;
}

void Pregunta::setApunte(Apunte *newApunte)
{
    m_apunte = newApunte;
}

const QString Pregunta::toString() const{

    QString str= m_apunte->toString();
    str += ", correcta: " + QString::number(m_corecta) + ", ";
    str += "respondida: " + QString::number(m_respondida) + "\n ";
    return str;


}

void Pregunta::responder(QString termino){

    m_corecta= (termino == apunte()->termino());
    m_respondida=true;
}

Pregunta::Pregunta(Apunte *apunte): m_apunte(apunte){

    m_corecta=false;
    m_respondida=true;

}

