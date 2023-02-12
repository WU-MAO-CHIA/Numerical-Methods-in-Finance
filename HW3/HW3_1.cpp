#include <iostream>
#include <cmath>

using namespace std;
int main() {
    float D, c, r, tmp, p;
    int n, F, i;
    cout << "please type the n:";
    cin >> n;
    cout << "please type the coupon:";
    cin >> c;
    cout << "please type the interest:";
    cin >> r;
    p = 0;
    tmp = 0;
    for(int i= 1; i <= n; i++){
        tmp += c / pow(1 + r, i);
    }
    p = tmp + (100 / pow(1 + r, n));
    cout << " Bond price is : " << p <<endl;

    for(int i= 1; i<= n; i++){
        D += c / pow(1 + r, i);
    }
    D += (n * 100) / pow(1 + r, n);
    D /= p;
    cout << "Macaulay Duration: " << D <<endl;

    return 0;
}
