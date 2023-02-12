#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>

using namespace std;

const int MATRIX_SIZE=3;

int main()
{
   int i,j;
//////////////////////////計算投資組合的變異度
  /////投資組合輸入
   
   double X[MATRIX_SIZE], S[MATRIX_SIZE][MATRIX_SIZE], y[MATRIX_SIZE], var, VaR;
   printf("輸入資產配置\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
	printf("第%d個資產:",i+1);
    scanf("%lf",&X[i]);
  }
  ///共變異數矩陣
  printf("輸入共變異數矩陣\n");
  for(i= 0;i< MATRIX_SIZE; i++)
  {
    for(j= 0; j<= i; j++)
	{
	  printf("第%d和第%d個資產的共變異度=",i+1,j+1);
	  scanf("%lf",&S[i][j]);
	  S[j][i] = S[i][j];
	}
  }
  
  for(i= 0; i< MATRIX_SIZE; i++){
      y[i] = 0;
      for(j= 0; j< MATRIX_SIZE; j++){
          y[i] += X[j] * S[j][i];
      }
  }
  
  for(i= 0; i< MATRIX_SIZE; i++){
      var = X[i] * y[i];
  }
  
  VaR = -1.645 * var;
  
  cout << "資產報酬率的變異度" << var << endl;
  cout << "95%信心水準下的VaR" << VaR << endl; 
  
system("pause");
return 0;
}

