#include<iostream>
#include <cmath>

using namespace std;

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

int main(){
    double v0, D, T, r, sigma, c, tau, alpha;
    cout << "please type the v0 : ";
    cin >> v0;
    cout << "please type the D : ";
    cin >> D;
    cout << "please type the T : ";
    cin >> T;
    cout << "please type the r : ";
    cin >> r;
    cout << 'please type the sigma';
    cin >> sigma;
    cout << "please type the tau : ";
    cin >> tau;
    cout << "please type the alpha : ";
    cin >> alpha;

    double vc = D + (1 - tau) * C * D * T;
    double DT = D + C * D * T;
    double b = 1/exp(r * T);
    double d1 = (log(v0 / (vc * b)) + pow(sigma, 2) * T / 2) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    double E0 = v0 * Standard_Normal_Distribution(d1) - vc * b * Standard_Normal_Distribution(d2);
    double V_left = v0 * Standard_Normal_Distribution(-d1);
    double D0 = DT * b * Standard_Normal_Distribution(d2) + V_left *(1 - alpha);
    double BC = alpha * V_left;
    double TB = tau * C * D * T * b * Standard_Normal_Distribution(d2);
    double Va = v0;
    
    cout << "1.E0 value= " << E0 << endl;
    cout << "2.D0 value= " << D0 << endl;
    cout << "3.TB=  " << TB << endl;
    cout << "4. BC= " << BC << endl;
    cout << "v1=E0+D0" << E0 + D0 << endl;
    cout << "V1 = V0 + TB - BC" << Va + TB - BC;
    system("puase");
    retun 0;
}