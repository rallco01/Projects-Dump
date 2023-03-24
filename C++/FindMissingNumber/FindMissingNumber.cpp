#include "UsefulMethods.h"
#include "containerOverloading.h"
#include "ANSITextCodes.h"

using std::cout;
using std::endl;

const int size = 100;
int arr[size];
int completeTotal;
int actualTotal;

void initialise()
{
	for(int i = 0; i<size; i++)
	{
		arr[i] = i+1;
	}
	arr[generateRandomNumber(size-1)] = 0;
	
	cout<<arr<<endl;
}
void calculate()
{
	for(int i = 0; i<size; i++)
	{
		completeTotal += i+1;
		actualTotal += arr[i];
	}
}
void findMissing()
{
	cout<<"Missing Number: "<<red(false, false, std::to_string(completeTotal - actualTotal))<<endl;
}

int main()
{
	initialise();
	calculate();
	findMissing();
	
	return 0;
}
