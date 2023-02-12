#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float coupon[5], r, value;
    int fv = 100;
    for(int i = 0; i < 5; i++){
        cout << "please type the coupon:";
        cin >> coupon[i];
    }

    cout << "please type the discount rate:";
    cin >> r;

    for(int i = 0; i < 5; i++){
        value += coupon[i] / pow((1 + r), i + 1);
    }
    value += fv / pow((1 + r), 5);
    cout << "Bond value: " << value;


    return 0;
}