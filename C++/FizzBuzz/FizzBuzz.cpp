#pragma once
#include "ANSITextCodes.h"

using std::string;
using std::stoi;
using std::cerr;
using std::endl;
using std::cout;
using std::to_string;

bool checkDigit(string toCheck);
string outputString(int number);

int main(int argv, char* argc[])
{
	int max = 100; 							//setting the max to count to, to be used if the user doesn't input anything
		if(argv > 2)							//check if the user input more than one thing
		{
			cerr<<yellow(false, false, "User Input Error")<<" Please make sure that only "<<red(false, false, "1 integer")<<" is input."<<endl;
			return 1;
		}
		if(argv == 2)							//check if the user input something that isn't an int
		{
			string input = argc[1];
			if(checkDigit(input))
				max = stoi(input);			//change the max to what the user input
			else
			{
				cerr<<yellow(false, false, "User Input Error")<<" Please make sure that the input is in "<<red(false, false, "integer")<<" format."<<endl;
				return 1;
			}
		}
	
	for(int i = 1; i <= max; i++)			//loop through all numbers
	{
		cout<<outputString(i)<<endl;		//display what the output method returns
	}
	
	return 0;
}

bool checkDigit(string toCheck)			//checking if input is in int format, retrun true if it is
{
	for(auto& c : toCheck)
	{
		if(!isdigit(c))
			return false;
	}
	
	return true;
}

string outputString(int number)			//checking the number, if it is divisible by 3, retrun fizz, if 5, return buz, if both, return both, but if none, return the number in a string data type
{
	string output = "";
	if(number % 3 == 0)
		output += blue(true, false, "Fizz");
	if(number % 5 == 0)
		output += cyan(true, false, "Buzz");
	if(output.length() == 0)
		output = green(false, false, to_string(number));
	
	return output;
}