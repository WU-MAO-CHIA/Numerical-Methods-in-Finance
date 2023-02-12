#include <iostream>
#include <cmath>

using namespace std;

double Max(double a, double b){
    if(a > b) return a;
    else return b;
}


int main(){
    int i;
    float S, T, X, r, sigma;
    int n;
    cout << "輸入標的物價格:";
    cin >> S ;
    cout << "輸入到期日:";
    cin >> T;
    cout << "輸入履約價格:";
    cin >> X;
    cout << "輸入無風險利率:";
    cin >> r;
    cout << "輸入標的物價格波動率:";
    cin >> sigma;
    cout << "輸入期數:";
    cin >> n;

    double U, D, Pu, Pd, deltaT;
    deltaT= T / n;
    U = exp(sigma * sqrt(deltaT));
    D = exp(-sigma * sqrt(deltaT));
    Pu = (exp(r * deltaT) - D) / (U - D);
    Pd = 1 - Pu;

    double array[500];
    double currentS = S * pow(U, n);
    
    for(int i=0; i<= n; i++){
        array[i] = Max(currentS - X, 0);
        currentS = currentS * pow(D, 2);
    }

    for(i= n-1; i >= 0; i--){
        currentS = S * pow(U, n);
        for(int j= 0; j<= i; j++){
            
            array[j] = Max(currentS - X, exp(-r * deltaT) * (array[j] * Pu + array[j + 1] * Pd));
            currentS *= pow(D, 2);
        }
    }

    cout << "選擇權價格= " << array[0] << endl;

system("pause");
return 0;
}