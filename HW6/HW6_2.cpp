
#include<iostream>
#include<cmath>

using namespace std;


double logab(double a, double b){
    return log(b) / log(a);
}

int main()
{
 
    cout << logab(5, 10) << endl;

system("pause");
return 0;
}

