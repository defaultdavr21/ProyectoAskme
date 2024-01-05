#ifndef APUNTE_H
#define APUNTE_H

#include <QString>

class Apunte{

private:
    QString m_termino;
    QString m_concepto;

public:
    Apunte();
    Apunte(const QString &termino, const QString &concepto);

    const QString &termino() const;
    const QString &concepto() const;
    const QString toString() const;

};

#endif // APUNTE_H
