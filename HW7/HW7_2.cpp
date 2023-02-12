#include <iostream>
#include <cmath>

using namespace std;

double standard_nornml_distribution(double d){
    int flag = 0;
    if(d < 0 ){
        flag = 1;
        d = fabs(d);
    }
    double rr = 0.2316419;
    double a1 = 0.31938153;
    double a2 = -0.356563782;
    double a3 = 1.781477937;
    double a4 = -1.821255978;
    double a5 = 1.330274429;
    double k = 1 / (1 + d * rr);
    double pi = 3.14159265359;
    double value = 1 - exp( d * d / (-2)) * (a1 * k + a2 * pow(k, 2) + a3 * pow(k, 3) + a4 * pow(k, 4) + a5 * pow(k, 5)) / sqrt(2 * pi);
    //   double value=1-exp(d*d/(-2))*(a1*k+a2*pow(k,2)+a3*pow(k,3)+a4*pow(k,4)+a5*pow(k,5))/sqrt(2*pi);
    if(flag){
        return 1 - value;
    }
    else{
        return value;
    }
}

int main(){
    double v0, d, t, r, sigma, c;
    cout << "company assets : ";
    cin >> v0;
    cout << "debt face value : ";
    cin >> d;
    cout << "expire date : ";
    cin >> t;
    cout << "risk free rate : ";
    cin >> r;
    cout << "sigma : ";
    cin >> sigma;
    cout << "debt coupon rate : ";
    cin >> c;
    // set the bond pay coupon annual
    double d_f = (d * c) * (1 / r) * (pow(1 + r, t- 1) - 1) + d;
    double b = exp(-r * t);
    double d1 = (log(v0 / d_f) + (r + 0.5 * pow(sigma, 2)) * t) / (sigma * sqrt(t));
    double d2 = d1 - sigma * sqrt(t);
    double E0 = v0 * standard_nornml_distribution(d1) - d_f * b * standard_nornml_distribution(d2);
    double put = d_f * b * standard_nornml_distribution(-d2) - v0 * standard_nornml_distribution(-d1);
    double D0 = d_f * b - put;
    cout << "asset value = " << v0 << endl;
    cout << "Equity value = " << E0 << endl;
    cout << "Debt value = " << D0 << endl;
    cout << "E0 + V0 = " << E0 + D0 << endl;

    system ("pause");
    return 0;
}
