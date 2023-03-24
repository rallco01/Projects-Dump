#include "ANSITextCodes.h"
#include "UsefulMethods.h"

using std::cout;
using std::endl;

int main(int argv, char* argc[])
{
	//error checking:
	//check num inputs is exactly 2
	//check input tyes are numbers
	
	for(int i = 0; i < atoi(argc[1]); i++)
	{
		for(int j = 0; j < atoi(argc[2]); j++)
		{
			if(generateRandomNumber(1))
				cout<<u8"\u2571";
			else
				cout<<u8"\u2572";
		}
		cout<<endl;
	}
}