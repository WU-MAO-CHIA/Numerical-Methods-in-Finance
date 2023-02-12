
#ifndef WRITEHEADER_HW03_H
#define WRITEHEADER_HW03_H
#include <math.h>
#endif //WRITEHEADER_HW03_H

double Standard_Normal_Distribution(double d){
    int flag=0;   //Flag =1 if d<0
    if(d<0)
    {
        flag=1;
        d=fabs(d);
    }
    double rr=0.2316419;
    double a1=0.31938153;
    double a2=-0.356563782;
    double a3=1.781477937;
    double a4=-1.821255978;
    double a5=1.330274429;
    double k=1/(1+d*rr);
    double PI=3.14159265359;
    double value=1-exp(d*d/(-2))*(a1*k+a2*pow(k,2)+a3*pow(k,3)+a4*pow(k,4)
                                  +a5*pow(k,5))/sqrt(2*PI);
    if(flag) return 1-value;
    else return value;
}
