#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

int main()
{
    int i, j, k;
    float ZeroRate[5];
    float Yield[5];
    float C;
    printf("請輸入債息:");
    scanf("%f",&C);
    for(i=0;i< 5;i= i+ 1)
    {                                 //輸入殖利率
        printf("輸入第 %d 期Yield rate:",i+ 1);
        scanf("%f", &Yield[i]);
    }
    ZeroRate[0] = Yield[0];          //第一期的零息利率等於第一期的殖利率
    for(i=1;i<= 4;i++)             //計算第i+1期zero rate

    {
        float BondValue = 0;
        for(j= 0;j<= i;j= j+1)     //計算債券價格Bi+1
        {
            float Discount=1;
            Discount /= pow((1 + Yield[i]), j + 1);
            BondValue = BondValue + Discount*C;
            if(j == i)
            {
                BondValue = BondValue + Discount * 100;
            }
        }
        for(j= 0;j< i;j= j+ 1)
        {
            float PV = C;
            PV /= pow((1 + ZeroRate[j]), j + 1);
            BondValue = BondValue - PV;
        }
        ZeroRate[i] = pow(1.0 * (C + 100) / BondValue,1.0 / (i + 1)) - 1;
    }
    for(i= 0;i<= 4;i++)   //列印零息利率
    {
        printf("第%d期zero rate=%f\n",i+ 1,ZeroRate[i]);
    }

    system("pause");
    return 0;
}
