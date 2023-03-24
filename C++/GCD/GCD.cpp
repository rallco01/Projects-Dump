#include<iostream>
#include "ANSITextCodes.h"

using std::cout;
using std::endl;

int GCD(int a, int b);

int main(int argv, char* argc[])
{
	//error checking:
	//check number of inputs: has to be 2
	//check type of inputs: has to be digits
	//find the greates common divisor:
	int gcd = GCD(atoi(argc[1]), atoi(argc[2]));
	
	cout<<"GCD of "<<green(false, false, std::to_string(atoi(argc[1])))<<" and "<<green(false, false, std::to_string(atoi(argc[2])))<<": "<<cyan(true, false, std::to_string(gcd))<<endl;
	cout<<blue(true, false, std::to_string(atoi(argc[1])/gcd))<<" times in: "<<green(false, false, std::to_string(atoi(argc[1])))<<endl;
	cout<<blue(true, false, std::to_string(atoi(argc[2])/gcd))<<" times in: "<<green(false, false, std::to_string(atoi(argc[2])))<<endl;
	return 0;
}


int GCD(int a, int b)
{
	if(a == 0 || b == 0)
		return 0;
	
	if(a == b)
		return a;
	
	if(a > b)
		return GCD(a - b, b);
	return GCD(a, b - a);
}