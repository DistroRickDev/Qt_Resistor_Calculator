#include "resistorcalc.h"

ResistorCalc::ResistorCalc()
{

}

QString ResistorCalc::calculateFinal(int fr, int sr, int tr, float tol)
{
    int final = fr * pow(10, tr) + sr * (pow(10, tr)/10) ;
    qDebug()<< "First Ring: "<<fr <<"Second Ring: "<< sr <<"Third Ring: "<< tr << "Tolerance:  " << tol;
    QString realFinal = QString::number(final);
    realFinal.append("Ω ± ");
    realFinal.append(QString::number(tol));
    realFinal.append("%");
    //qDebug() << "Real Final Value is: "<< realFinal;
    return realFinal;
}
