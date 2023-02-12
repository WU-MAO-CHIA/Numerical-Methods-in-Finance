#include<cmath>
#include<iostream>

using namespace std;

double Max(double a,double b){
  if(a > b)  return a;
  else return b;
}
int main()
{
  float S, T, X, r, Sigma; 
  int n;           
  printf("輸入標的物價格:");
  scanf("%f",&S);
  printf("輸入到期日:");
  scanf("%f",&T);
  printf("輸入履約價格:");
  scanf("%f",&X);
  printf("輸入無風險利率:");
  scanf("%f",&r);
  printf("輸入標的物價格波動率:");
  scanf("%f",&Sigma);
  printf("輸入期數:");
  scanf("%d",&n);
  
  double U, D, Pu, Pd, DeltaT;
  DeltaT = T / n;
  U = exp(Sigma * sqrt(DeltaT));
  D = exp(-Sigma * sqrt(DeltaT));
  Pu = (exp(r * DeltaT) - D) / (U - D);
  Pd = 1 - Pu;
  
  double CurrentS, CurrentProb, c = log(1);
  double OptionValue = 0;

  for(int i= 0; i<= n; i= i + 1){
    CurrentS = S * exp((n - i) * log(U) + i * log(D));
    CurrentProb = exp(c + (n- i) * log(Pu) + i * log(Pd));
    OptionValue = OptionValue + exp(-r * T) * CurrentProb * Max(CurrentS - X, 0);
    c = c+ log(n - i) - log(i + 1);
    //cout << OptionValue << "\t";
  }
  cout << endl;
  
  printf("選擇權價格=%f\n",OptionValue);

  system("pause");
  return 0;
}
