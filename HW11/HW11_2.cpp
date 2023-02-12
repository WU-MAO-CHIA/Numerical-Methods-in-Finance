#include<cmath>
#include<iostream>

using namespace std;

double Max(double a,double b){
  if(a>b)  return a;
  else return b;
}


int main(){
  int i, j;
  //輸入資料
  float S, T, X, r, Sigma, H, X2; 
  int n;  //期數            
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
  cout << "輸入重設邊界:";
  cin >> H;
  cout << "輸入重設履約價格:";
  cin >> X2;

  //計算CRR二元樹的相關參數
  double U, D, Pu, Pd, DeltaT;
  int q = 0;
  DeltaT = T / n;
  U = exp(Sigma * sqrt(DeltaT));
  D = exp(-Sigma * sqrt(DeltaT));
  Pu = (exp(r * DeltaT) - D) / (U - D);
  Pd = 1 - Pu;
  //計算payoff的折現期望值
  double Array[500][2];
  double Sprice;
  double CurrentS = S * pow(U, n);
  for(i= 0; i<= n; i++){
   Array[i][0] = Max(CurrentS - X, 0);
   Array[i][1] = Max(CurrentS - X2, 0);
   CurrentS = CurrentS * pow(D, 2);
  }
  //Backward Induction
  for(i= n- 1; i>= 0; i--){
    for(j= 0; j<= i; j++){
      Array[j][0] = exp(-r * DeltaT) * (Array[j][0] * Pu + Array[j+1][0] * Pd);
      Array[j][1] = exp(-r * DeltaT) * (Array[j][1] * Pu + Array[j+1][1] * Pd); 
    //cout << Array[j][0] <<' ';
    }
  cout << endl;  
  }

  for(i= n; i>= 0; i--){
    for(j= 0; j<= i; j++){
        Sprice = S * pow(U, i- j) * pow(D, j);
        cout << Sprice << "\t";
      }
      if(Sprice <= H){
        q = 1;
        break;   
      }
    cout << endl;   
  }
  //輸出評價結果
  printf("選擇權價格=%f\n",Array[0][q]);
  
  system("pause");
  return 0;
}
