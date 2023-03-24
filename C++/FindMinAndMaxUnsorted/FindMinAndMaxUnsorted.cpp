#include <limits>
#include "UsefulMethods.h"
#include "ContainerOverloading.h"
#include "ANSITextCodes.h"

using std::cout;
using std::endl;

//change this to change size of array to search through
const int arraySize = 30;

int arr[arraySize];
int min = INT8_MAX;
int max = INT8_MIN;

void initialize()
{
	for(int i = 0; i < arraySize; i++)
	{
		arr[i] = generateRandomNumber(1000);
	}
}

void findMinMax()
{
	for(auto& i : arr)
	{
		if(i < min)
			min = i;
		if(i > max)
			max = i;
	}
	
	cout<<"Smallest value in array: "<<cyan(false, false, std::to_string(min))<<" | Largest value in array: "<<green(false, false, std::to_string(max))<<endl;
}

int main()
{
	initialize();
	cout<<"Array: "<<arr<<endl;
	findMinMax();
	
	return 0;
}