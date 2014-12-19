
#ifndef PIDCont_h
#define PIDCont_h

#include "Arduino.h"

class PIDCont
{
public:
PIDCont();
void ChangeParameters(double mKp, double mKi, double mKd, double mLval, double mHval);
double Compute(double mError);
double Compute(double mError,double dError,double setP);
void resetI();

private:
double kp;
double ki;
double kd;
double pError;
double Ip;
double Lval;
double Hval;
unsigned long tp;
};

#endif
