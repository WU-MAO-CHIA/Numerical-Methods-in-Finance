#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double Standard_Normal_Distribution(double d)
{
   int flag=0;   //Flag =1 if d<0
   if(d<0)
     {
      flag=1;
      d=fabs(d);
     }
   double rr=0.2316419;
   double a1=0.31938153;
   double a2=-0.356563782;
   double a3=1.781477937;
   double a4=-1.821255978;
   double a5=1.330274429;
   double k=1/(1+d*rr);
   double PI=3.14159265359;
   double value=1-exp(d*d/(-2))*(a1*k+a2*pow(k,2)+a3*pow(k,3)+a4*pow(k,4)
                  +a5*pow(k,5))/sqrt(2*PI);
   if(flag) return 1-value;
    else return value;
}
double BS_Call(double S, double r, double T, double X, double V, double q)
{
    double b=1/exp(r*T);
   double d1=(log(S/(X*b))-q+V*V*T/2)/(V*sqrt(T));
   double d2=d1-V*sqrt(T);
   double CallValue=S*Standard_Normal_Distribution(d1)-X*b*Standard_Normal_Distribution(d2);
  return CallValue;
}

double BS_Put(double S, double r, double T, double X, double V, double q)
{
   double b=1/exp(r*T);
   double d1=(log(S/(X*b))-q+V*V*T/2)/(V*sqrt(T));
   double d2=d1-V*sqrt(T);
   double Value=X * b * Standard_Normal_Distribution (-d2) - S *  Standard_Normal_Distribution(-d1);//���v
   return Value;
}
double DownAndInCall(double S, double T, double X, double H, double r, double q, double Sigma)
{
  double OptionValue;
double lambda = (r-q+0.5*Sigma*Sigma)/(Sigma*Sigma);
  double y = log((H*H)/(S*X))/(Sigma*sqrt(T)) + lambda* Sigma*sqrt(T);
OptionValue = S * pow((H/S),2*lambda) * Standard_Normal_Distribution(y) / exp(q*T) - X * pow((H/S),(2*lambda-2)) * Standard_Normal_Distribution(y- Sigma*sqrt(T)) / exp(r*T) ;
 return OptionValue;
}

double UpAndInPut(double S, double T, double X, double H, double r, double q, double Sigma)
{
  double OptionValue;
double lambda = (r-q+0.5*Sigma*Sigma)/(Sigma*Sigma);
  double y = log((H*H)/(S*X))/(Sigma*sqrt(T)) + lambda* Sigma*sqrt(T);
OptionValue = X * pow((H/S),(2*lambda-2)) * Standard_Normal_Distribution(-y+Sigma*sqrt(T)) / exp(r*T) - S * pow((H/S),2*lambda) * Standard_Normal_Distribution(-y) / exp(q*T) ;
 return OptionValue;
}


///////////////////////////////////////////////////////////////////////
///  Bivariate normal distribution
//Compute the cumulative probability in Bivariate Normal Distribution
//Check J. Hull Option, Futeures and other Derivatives 5th ed., Appendix 12-c (p266)
double Sign(double a)
{
  if(a>=0) return 1;
  return -1;
}

double APrime, BPrime;
inline double f(double x, double y,double rho)
{
  return exp(APrime*(2*x-APrime)+BPrime*(2*y-BPrime)+2*rho*(x-APrime)*(y-BPrime));
}

double M(double a, double b, double rho)
{ //Called by BiNormalDistribution
  double A[4]={0.3253030,0.4211071,0.1334425,0.006374323};
  double B[4]={0.1337764,0.6243247,1.3425378,2.2626645};
  double PI=3.14159265359;
  APrime=a/sqrt(2*(1-rho*rho));
  BPrime=b/sqrt(2*(1-rho*rho));
  double Result=0;
  for(int i=0;i<=3;i++)  
   for(int j=0;j<=3;j++)
    Result+=A[i]*A[j]*f(B[i],B[j],rho);
  Result*=sqrt(1-rho*rho)/PI;  
 return Result;
}

double MM(double a, double b, double rho)
{// Use to handle the case a*b*rho>0
 if((a<=0)&&(b<=0)&&(rho<=0))
	return M(a,b,rho);
  else if ((a<=0)&&(b>=0)&&(rho>=0))
    return Standard_Normal_Distribution(a)-M(a,-b,-rho);
  else if ((a>=0)&&(b<=0)&&(rho>=0))
    return Standard_Normal_Distribution(b)-M(-a,b,-rho);
  else if ((a>=0)&&(b>=0)&&(rho<=0))
    return Standard_Normal_Distribution(a)+Standard_Normal_Distribution(b)-1+M(-a,-b,rho);
 return -1;
}
double Two_Dimension_Normal(double a, double b, double rho)
{//Compute the cumulative probability in Bivariate Normal Distribution
 //Check J. Hull Option, Futeures and other Derivatives 5th ed., Appendix 12-c (p266)
 if((a<=0)&&(b<=0)&&(rho<=0))
	return M(a,b,rho);
  else if ((a<=0)&&(b>=0)&&(rho>=0))
    return Standard_Normal_Distribution(a)-M(a,-b,-rho);
  else if ((a>=0)&&(b<=0)&&(rho>=0))
    return Standard_Normal_Distribution(b)-M(-a,b,-rho);
  else if ((a>=0)&&(b>=0)&&(rho<=0))
    return Standard_Normal_Distribution(a)+Standard_Normal_Distribution(b)-1+M(-a,-b,rho);
  else
  {
   double rho1,rho2,delta;
   rho1=(rho*a-b)*Sign(a)/sqrt(a*a-2*rho*a*b+b*b);
   rho2=(rho*b-a)*Sign(b)/sqrt(a*a-2*rho*a*b+b*b);
   delta=(1-Sign(a)*Sign(b))/4.0;
     return MM(a,0,rho1)+MM(b,0,rho2)-delta;   
  }
  return -1;
}

//////////////// Functions for pricing Other Exotic Options
double ForwardStartCall(double S, double T_1, double T, double r, double q, double Sigma)
{
  double OptionValue;
  double D_1 = (r-q+(Sigma*Sigma)/2.0)*sqrt(T-T_1)/Sigma;
  double D_2 = D_1 - Sigma*sqrt(T-T_1);
OptionValue = S*Standard_Normal_Distribution(D_1)/exp(q*T) -
		S*Standard_Normal_Distribution(D_2)/exp(r*(T-T_1)+q*T_1);
return OptionValue;
}
////  Subroutine for Compound options//////////////////////
//Use bisection method to get S^*
double FindCallS(double call, double X, double r, double q, double T, double V)
{	
	double fa,fb,fc,a,b,c,tol,error_bound;
	tol=0.00001; 
	a=0;	b=10*X;	//initial
	error_bound = (b - a)/2.0;  
	c = (a+b)/2.0;
    fa = call-BS_Call( a, r,T, X, V, q); 
	fb = call-BS_Call( b, r,T, X, V, q);
	fc = call-BS_Call( c, r,T, X, V, q);
	while (error_bound > tol)
    {	
		if (fa * fc < 0.0) {
			b = c;
			fb = fc;
			c = (a+c)/2.0;}
		else {
			a = c;
			fa = fc;
			c = (b+c)/2.0;}
		fc = call-BS_Call(c, r, T, X, V, q);
		error_bound = 0.5*(b - a);
    }
	return c;
}
double FindPutS(double put, double X, double r, double q, double T, double V)
{	
	double fa,fb,fc,a,b,c,tol,error_bound;
	tol=0.00001; 
	a=0;	b=10*X;	//initial
	error_bound = (b - a)/2.0;  
	c = (a+b)/2.0;
    fa = put-BS_Put( a, r,T, X, V, q); 
	fb = put-BS_Put( b, r,T, X, V, q);
	fc = put-BS_Put( c, r,T, X, V, q);
	while (error_bound > tol)
    {	
		if (fa * fc < 0.0) {
			b = c;
			fb = fc;
			c = (a+c)/2.0;}
		else {
			a = c;
			fa = fc;
			c = (b+c)/2.0;}
		fc = put-BS_Put(c, r, T, X, V, q);
		error_bound = 0.5*(b - a);
    }
	return c;
}

double CallOnCall(double S, double T_1, double T_2, double X_1, double X_2, double r, double q, double Sigma)
{
  double OptionValue;
  double SStar=FindCallS(X_1,X_2,r,q,T_2-T_1,Sigma);
  double A_1 = (log(S/SStar)+( r-q+(Sigma*Sigma)*0.5)*T_1)/(Sigma*sqrt(T_1));
  double B_1 = (log(S/X_2)+( r-q+(Sigma*Sigma)*0.5)*T_2)/(Sigma*sqrt(T_2));
  double A_2 = A_1 - Sigma*sqrt(T_1);
  double B_2 = B_1 - Sigma*sqrt(T_2);
  OptionValue=
S*Two_Dimension_Normal(A_1,B_1,sqrt(T_1/T_2))/exp(q*T_2) -
X_2*Two_Dimension_Normal(A_2,B_2,sqrt(T_1/T_2))/exp(r*T_2) -
X_1*Standard_Normal_Distribution(A_2)/ exp(r*T_1);
 return OptionValue;
}
double PutOnCall(double S, double T_1, double T_2, double X_1, double X_2, double r, double q, double Sigma)
{
  double OptionValue;
  double SStar=FindCallS(X_1,X_2,r,q,T_2-T_1,Sigma);
  double A_1 = (log(S/SStar)+( r-q+(Sigma*Sigma)*0.5)*T_1)/(Sigma*sqrt(T_1));
  double B_1 = (log(S/X_2)+( r-q+(Sigma*Sigma)*0.5)*T_2)/(Sigma*sqrt(T_2));
  double A_2 = A_1 - Sigma*sqrt(T_1);
  double B_2 = B_1 - Sigma*sqrt(T_2);
  OptionValue=
X_2*Two_Dimension_Normal(-A_2,B_2,-sqrt(T_1/T_2))/exp(r*T_2) -
S*Two_Dimension_Normal(-A_1,B_1,-sqrt(T_1/T_2))/exp(q*T_2) +
X_1*Standard_Normal_Distribution(-A_2)/ exp(r*T_1);
 return OptionValue;
}
double CallOnPut(double S, double T_1, double T_2, double X_1, double X_2, double r, double q, double Sigma)
{
  double OptionValue;
  double SStar=FindPutS(X_1,X_2,r,q,T_2-T_1,Sigma);
  double A_1 = (log(S/SStar)+( r-q+(Sigma*Sigma)*0.5)*T_1)/(Sigma*sqrt(T_1));
  double B_1 = (log(S/X_2)+( r-q+(Sigma*Sigma)*0.5)*T_2)/(Sigma*sqrt(T_2));
  double A_2 = A_1 - Sigma*sqrt(T_1);
  double B_2 = B_1 - Sigma*sqrt(T_2);
  OptionValue=
X_2*Two_Dimension_Normal(-A_2,-B_2,sqrt(T_1/T_2))/exp(r*T_2) -
S*Two_Dimension_Normal(-A_1,-B_1,sqrt(T_1/T_2))/exp(q*T_2) -
X_1*Standard_Normal_Distribution(-A_2)/ exp(r*T_1);
 return OptionValue;
}
double PutOnPut(double S, double T_1, double T_2, double X_1, double X_2, double r, double q, double Sigma)
{
  double OptionValue;
  double SStar=FindPutS(X_1,X_2,r,q,T_2-T_1,Sigma);
  double A_1 = (log(S/SStar)+( r-q+(Sigma*Sigma)*0.5)*T_1)/(Sigma*sqrt(T_1));
  double B_1 = (log(S/X_2)+( r-q+(Sigma*Sigma)*0.5)*T_2)/(Sigma*sqrt(T_2));
  double A_2 = A_1 - Sigma*sqrt(T_1);
  double B_2 = B_1 - Sigma*sqrt(T_2);
  OptionValue=
S*Two_Dimension_Normal(A_1,-B_1,-sqrt(T_1/T_2))/exp(q*T_2) -
X_2*Two_Dimension_Normal(A_2,-B_2,-sqrt(T_1/T_2))/exp(r*T_2)+
X_1*Standard_Normal_Distribution(A_2)/ exp(r*T_1);
 return OptionValue;
}
double LookbackCall(double S, double T, double Smin, double r, double q, double Sigma)
{
  double OptionValue;
  double D_1 = (log(S/Smin)+( r-q+(Sigma*Sigma)*0.5)*T)/(Sigma*sqrt(T));
  double D_2 = (log(S/Smin)+( q-r+(Sigma*Sigma)*0.5)*T)/(Sigma*sqrt(T));
double y = -2.0*log(S/Smin)*( r-q-(Sigma*Sigma)*0.5)/ (Sigma*Sigma);
  OptionValue=
S*Standard_Normal_Distribution(D_1)/exp(q*T) -
S*Standard_Normal_Distribution(-D_1) *
((Sigma*Sigma)/(2.0*(r-q)))/exp(q*T) -
Smin*(Standard_Normal_Distribution(D_1- Sigma*sqrt(T)) - (Sigma*Sigma)/(2.0*(r-q))*exp(y)* Standard_Normal_Distribution(-D_2))/exp(r*T);
return OptionValue;
}

double LookbackPut(double S, double T, double Smax, double r, double q, double Sigma)
{
  double OptionValue;
  double D_1 = (log(Smax/S)+( q-r+(Sigma*Sigma)*0.5)*T)/(Sigma*sqrt(T));
  double D_2 = (log(Smax/S)+( r-q-(Sigma*Sigma)*0.5)*T)/(Sigma*sqrt(T));
  double y = 2.0*log(Smax/S)*( r-q-(Sigma*Sigma)*0.5)/(Sigma*Sigma);
  OptionValue=
    Smax*(Standard_Normal_Distribution(D_1) - (Sigma*Sigma)/(2.0*(r-q))*exp(y)* Standard_Normal_Distribution(-D_2))/exp(r*T) +
    S*Standard_Normal_Distribution(-D_1+ Sigma*sqrt(T)) *
    ((Sigma*Sigma)/(2.0*(r-q)))/exp(q*T) -
    S*Standard_Normal_Distribution(D_1- Sigma*sqrt(T))/exp(q*T);
  return OptionValue;
}

double ChooserOption(double S, double X, double T, double t, double r, double q, double Sigma)
{
   double OptionValue=0;
   OptionValue+=BS_Call(S,r,T,X,Sigma,q);
   OptionValue=OptionValue+exp(-q*(T-t))*BS_Put(S,r,t,X*exp(-(r-q)*(T-t)),Sigma,q);
   return OptionValue;
}
double GeometricCall(double S, double T, double X, double r, double Sigma)
{
  double OptionValue;
  double D_Start = (r-(Sigma*Sigma)/6.0)/2.0*T;
  double D = (log(S/X)+(r+(Sigma*Sigma)/6.0)/2.0*T)/(Sigma*sqrt(T/3.0));
  OptionValue = exp(D_Start)*S*Standard_Normal_Distribution(D)-
			  X*Standard_Normal_Distribution(D-Sigma*sqrt(T/3.0));
  double Discounted = exp(r*T);
  OptionValue/=Discounted;
 return OptionValue;
}

int main(int argc, char *argv[]) {
  double s, T, X, H, r, q, sigma;
  s = 100;
  X = 100;
  T = 1;
  r = 0.1;
  sigma = 0.3;
  H = 90;
  q = 0;
  cout <<DownAndInCall(s, T, X, H, r, q, sigma) << endl;
	system("pause");
	return 0;
}
