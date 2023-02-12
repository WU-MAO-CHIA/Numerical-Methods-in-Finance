#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double Max(double a,double b)
{
 if(a>b) return a;
 else return b;
}
double Normal()
{
     double N=0;
	 for(int j=0;j<12;j++)
	 {
	   N=N+double(rand())/RAND_MAX;
	 }
     N=N-6;
	return N;
}
int main()
{  
  
  double S=100,T=10,X=85,r=0.03,Sigma=0.05; 
  double n=10000;

   srand( (unsigned)time( NULL ) );
   double OptionValue_c = 0;
   double OptionValue_p = 0;
   double SquareSum_c = 0;
   double SquareSum_p = 0;
   double AverageS = 0;
   for(int i=0;i<n;i++)
   {
	double N = Normal();
	double ST = S * exp((r - Sigma * Sigma / 2) * T + Sigma * sqrt(T) * N);
	AverageS = AverageS + ST;
	double Payoff_c = exp(-r * T) * Max(ST - X, 0);
	double Payoff_p = exp(-r * T) * Max(X - ST, 0);
	OptionValue_c = OptionValue_c + Payoff_c;
	OptionValue_p = OptionValue_p + Payoff_p;
	SquareSum_c = SquareSum_c + pow(Payoff_c, 2);
	SquareSum_p = SquareSum_p + pow(Payoff_p, 2);
   }
   OptionValue_c = OptionValue_c / n;
   OptionValue_p = OptionValue_p / n;
   AverageS = AverageS / n;
   double AverageS0 = exp(-r * T) * AverageS;
   double error = OptionValue_c - OptionValue_p - AverageS0 + exp(-r * T) * X;
   double error_b = error * 1000000000;
   double STDERR_c = sqrt((SquareSum_c / n - pow(OptionValue_c, 2)) / (n - 1));
   double STDERR_p = sqrt((SquareSum_p / n - pow(OptionValue_p, 2)) / (n - 1));
   printf("Call Value =%f, Call Standard Err~%f\n", OptionValue_c, STDERR_c);
   printf("Put  Value =%f, Put  Standard Err~%f\n", OptionValue_p, STDERR_p);
   printf("Error =%f\n", error);
   printf("¤Q»õ­¿Error =%f\n", error_b);




   system("pause");
   return 0;
}
