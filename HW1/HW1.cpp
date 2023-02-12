/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    cout << "Question1" <<endl;
	int day;
	double price,rate;
	//printf("Please enter the rate(%%):");
	cout << "Please enter the rate(%):";
	cin >> rate;
	//printf("Please enter the term(day):");
	cout << "Please enter the term(day):";
	cin >> day;
	price = 100000 - (100000 * double(rate/100) * double(day/365) );
	cout << "the price of $100,000 commercial paper is " << price << "\n";


	cout << "Question2"<<endl;
	printf("First program");
    system("pause");
    return 0;
}
