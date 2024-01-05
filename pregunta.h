#ifndef PREGUNTA_H
#define PREGUNTA_H
#include "apunte.h"

class Pregunta{
private:

    bool m_corecta;
    bool m_respondida;
    Apunte *m_apunte;

public:
    Pregunta(Apunte *apunte);
    Pregunta(bool corecta, bool respondida);


    bool corecta() const;
    void setCorecta(bool newCorecta);
    bool respondida() const;
    void setRespondida(bool newRespondida);
    Apunte *apunte() const;
    void setApunte(Apunte *newApunte);
    const QString toString() const;
    void responder(QString termino);

};

#endif // PREGUNTA_H
