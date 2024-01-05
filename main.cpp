#include "askme.h"

#include <QApplication>
#include <QDebug>

#include "tema.h"
#include "asignatura.h"
#include "cuestionario.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Askme w;
    w.show();

    Apunte *ap1 = new Apunte ("Función", "Una función de dependencia entre A y B");
    Apunte *ap2 = new Apunte ("Derivada", "Correspondencia entre el signo y el crecimiento o decrecimiento de una la función original");

    Tema t1("Ecuaciones de primer grado");
    t1.agregarApunte(ap1);
    t1.agregarApunte(ap2);



    Tema *t2= new Tema("Electromagnetismo");
    t2->agregarApunte (new Apunte ("Campo electrico","Campos que ejersen fuerza"));
    t2->agregarApunte (new Apunte ("Electricidad","Fuerza que ejerce el atomo"));

    //qDebug().noquote()<<t2->toString();

    Tema *t3= new Tema ("Optica");
    t3->agregarApunte (new Apunte ("Reflaccion","Angulo de refraccion"));

    //qDebug().noquote()<<t3->toString();


    Asignatura a1("Fisica");
    a1.agregarTemas(t2);
    a1.agregarTemas(t3);

    //qDebug().noquote()<<a1.toString();

    //Creo el cuestionario
    Cuestionario quiz(t2);

    qDebug().noquote()<< quiz.terminos();

    Pregunta *p =quiz.siguiente();
    qDebug().noquote()<< p->toString();
    p->responder("DWA");
    qDebug().noquote()<< p->toString();

    p= quiz.siguiente();
    qDebug().noquote()<< p->toString();




    return a.exec();
}
