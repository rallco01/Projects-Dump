#include "ANSITextCodes.h"
#include "ContainerOverloading.h"
#include "TableCharacters.h"
#include "UsefulMethods.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

vector<int> range;
int rangeMin;
int rangeMax;
int startingPoint;
long result = 0;
long countChecks = 0;

void initialise(int min, int max);
bool checkMultiple(int check);

int main()
{
	
	cout<<yellow(false, false, "Please enter the minimum value in the range: ");
	cin>>rangeMin;
	
	cout<<yellow(false, false, "Please enter the maximum value in the range: ");
	cin>>rangeMax;
	
	
	
	initialise(rangeMin, rangeMax);
	
	startingPoint = rangeMax;
	
	for(long i = startingPoint; ; i+=rangeMax)
	{
		countChecks++;
		if(checkMultiple(i))
		{
			result = i;
			break;
		}
	}
	
	cout<<cyan(true, false, "Result: " + std::to_string(result))<<green(true, false, " found in " + std::to_string(countChecks) + " checks.")<<endl;
	
	return 1;
}

void initialise(int min, int max)
{
	for(int i = min; i<=max; i++)
	{
		range.push_back(i);
	}
}

bool checkMultiple(int check)
{
	for(auto& i : range)
	{
		if(check%i)
			return false;
	}
	return true;
}