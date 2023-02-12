#include <iostream>

using namespace std;

int main()
{
    float rate1, rate2, rate3, a;
    double payoff;
    cout<< "please type rate1, rate2, rate3" <<endl;
    cin >> rate1 >> rate2 >> rate3;
    a = (rate1 > 0.01) + (rate2 > 0.01) + (rate3 >0.01);

    if(a >= 2){
        payoff = (a/2) * 100.5;
    }
    else{
        payoff = 70;
    }
    cout << payoff << endl;

    system("pause");
    return 0;
}
