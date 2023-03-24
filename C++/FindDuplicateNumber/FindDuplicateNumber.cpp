#include <algorithm>
#include "UsefulMethods.h"
#include "ContainerOverloading.h"
#include "ANSITextCodes.h"

using std::cout;
using std::endl;

const int size = 101;
int arr[size];

void initialise()
{
	for(int i = 0; i<100; i++)
	{
		arr[i] = i+1;
	}
	arr[100] = generateRandomNumber(1, 100);
	
		
	cout<<arr<<endl;
}
void findDuplicate()
{
	int duplicateNumber = 0;
	for(int i = 0; i<size-1; i++)
	{
		if(arr[i] == arr[i+1])
		{
			duplicateNumber = i+1;
			break;
		}
	}
	if(duplicateNumber != 0)
		cout<<"The duplicate number is: "<<red(false, false, std::to_string(duplicateNumber))<<endl;
	else
		cout<<yellow(false, false, "Unable to find a duplicate number")<<endl;
}

int main()
{
	initialise();
	std::sort(arr, arr+size);
	findDuplicate();
	
	return 0;
}