#include <iostream>
#include <stdio.h>
#include <math.h>
double Standard_Normal_Distribution(double d)
{
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

int main()
{
    float V0,D,T,r,sigma,C, tau, alpha;
    printf("輸入V0:");
    scanf("%f",&V0);
    printf("輸入D:");
    scanf("%f",&D);
    printf("輸入T:");
    scanf("%f",&T);
    printf("輸入r:");
    scanf("%f",&r);
    printf("輸入sigma:");
    scanf("%f",&sigma);
    printf("輸入C:");
    scanf("%f",&C);
    printf("輸入tau:");
    scanf("%f",&tau);
    printf("輸入alpha:");
    scanf("%f",&alpha);
    double Vc = D+(1-tau)*C*D*T;
    double DT = D + C*D*T;
    double b=1/exp(r*T);
    double d1=(log(V0/(Vc*b))+sigma*sigma*T/2)/(sigma*sqrt(T));
    double d2=d1-sigma*sqrt(T);
    double E0=V0*Standard_Normal_Distribution(d1)-Vc*b*Standard_Normal_Distribution(d2);
    double V_left = V0*Standard_Normal_Distribution(-d1);
    double D0=DT*b*Standard_Normal_Distribution(d2)+V_left*(1-alpha);
    double BC = alpha * V_left;
    double TB = tau*C*D*T*b*Standard_Normal_Distribution(d2);
    double Va = V0;
    printf("1.E0 value=%lf\n",E0);
    printf("2.D0 value=%lf\n",D0);
    printf("3.TB=%lf\n",TB);
    printf("4.BC=%lf\n",BC);
    printf("Vl=E0+D0=%lf\n",E0+D0);
    printf("Vl=V0+TB-BC=%lf\n",Va+TB-BC);
    return 0;
}