#ifndef RESISTORCALC_H
#define RESISTORCALC_H
#include <QString>
#include <QDebug>
#include <math.h>


class ResistorCalc
{
public:
    ResistorCalc();
    QString calculateFinal(int fr, int sr, int tr, float tol);
};

#endif // RESISTORCALC_H
