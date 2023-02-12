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
    float s, r, t, k, v;
    cout << " asset value : ";
    cin >> s;
    cout << "risk free rate : ";
    cin >> r;
    cout << "expiry date : ";
    cin >> t;
    cout << "strike price : ";
    cin >> k;
    cout << "volatility : ";
    cin >> v;
    double b = exp(-r * t);
    double d1 = (log(s / k) + (r + 0.5 * pow(v, 2)) * t) / (v * sqrt(t));
    double d2 = d1 - v * sqrt(t);
    double value = k * b * standard_nornml_distribution(-d2) - s * standard_nornml_distribution(-d1);
    //cout << "N(d1) : " << standard_nornml_distribution(d1) << "\tN(d2) : " <<standard_nornml_distribution(d2) << endl;
    cout << "Put value = " << value << endl;

    system("pause");
    return 0;
}