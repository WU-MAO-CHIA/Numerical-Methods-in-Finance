#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float low = 0, high = 1;
    float c, r, n, x, fv;
    cout << "please type the cash flow:";
    cin >> c;
    cout << "please type the interest:";
    cin >> r;
    cout << "please type the first invest dollars:";
    cin >> x;
    cout << "please type the n:";
    cin >> n;

    fv = 0;
    for(int i= 1; i <= n; i++){
        fv += c * pow(1 + r, n - i);
    }
    cout << fv <<endl;

    while(high - low >= 0.0001){

        float middle = (low + high) / 2;
        float value = 0;
        cout << "yield rate: " << middle << endl;
        value = x * pow(1 + middle, n);
        if(value > fv){
            high = middle;
        }
        else{
            low = middle;
        }
    }
    cout << "yield rate: " << high << endl;
    system("pause");
    return 0;
}
