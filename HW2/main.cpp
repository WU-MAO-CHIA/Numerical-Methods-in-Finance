#include <iostream>

int main() {
//hw1
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
//hw2
    int grade;
    float d,e,f,r,s;
    printf("輸入信用評等:");
    scanf("%d",&grade);
    printf("輸入第一期現金流:");
    scanf("%f",&d);
    printf("輸入第二期現金流:");
    scanf("%f",&e);
    printf("輸入利率:");
    scanf("%f",&r);
    printf("輸入風險貼水:");
    scanf("%f",&s);
    if(grade>=60) {
        f = d / (1 + r + s);
        f = f + e / ((1 + r + s) * (1 + r + s));
    }
    else{
        if(grade < 50) {
            f = d / (1 + r + 3 * s);
            f = f + e / ((1 + r + 3 * s) * (1 + r + 3 * s));
        }
        else{
            f=d/(1+r+2*s);
            f=f+e/((1+r+2*s)*(1+r+2*s));
        }
    }
    printf("Present value=%f\n",f);


    return 0;
}
