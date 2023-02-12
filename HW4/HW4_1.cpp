#include <iostream>
using namespace std;

// check nine month need 複利幾次

int main() {
    float fix_rate[7], tmp;
    tmp = 1;
    for(int i=0; i<= 7; i++){
        fix_rate[i] = 0.01;
    }

    cout << "nine month fixed interest rate: " << 1 * (1 + (fix_rate[3]/4)) * (1 + (fix_rate[3]/(4 * 3 ))) << endl;

    for(int i=0; i< 4; i++){
        tmp *= (1 + fix_rate[5]/2);
    }
    cout << "two year fixed interest rate: " << tmp << endl;

    tmp = 1;
    for(int i=0; i< 6; i++){
        tmp *= (1 + fix_rate[6]/2);
    }
    cout << "three year fixed interest rate: " << tmp << endl;

    return 0;
}