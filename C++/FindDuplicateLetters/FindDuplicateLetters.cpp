#include "ANSITextCodes.h"
#include "ContainerOverloading.h"
#include "TableCharacters.h"
#include "UsefulMethods.h"
#include <string>
#include <cmath>
#include <iomanip>

int letterCount[26] = {0};

void findDuplicateLetters(std::string s);
void displayCount();

int main(int argv, char* argc[])
{
	std::string stringToAnalyse = argc[1];
	
	findDuplicateLetters(stringToAnalyse);
	displayCount();
	
	return 0;
}

void findDuplicateLetters(std::string s)
{
	for(auto& c : s)
	{
		switch(c)
		{
			case 'A': case 'a':
				letterCount[0]++;
				break;
			case 'B': case 'b':
				letterCount[1]++;
				break;
			case 'C': case 'c':
				letterCount[2]++;
				break;
			case 'D': case 'd':
				letterCount[3]++;
				break;
			case 'E': case 'e':
				letterCount[4]++;
				break;
			case 'F': case 'f':
				letterCount[5]++;
				break;
			case 'G': case 'g':
				letterCount[6]++;
				break;
			case 'H': case 'h':
				letterCount[7]++;
				break;
			case 'I': case 'i':
				letterCount[8]++;
				break;
			case 'J': case 'j':
				letterCount[9]++;
				break;
			case 'K': case 'k':
				letterCount[10]++;
				break;
			case 'L': case 'l':
				letterCount[11]++;
				break;
			case 'M': case 'm':
				letterCount[12]++;
				break;
			case 'N': case 'n':
				letterCount[13]++;
				break;
			case 'O': case 'o':
				letterCount[14]++;
				break;
			case 'P': case 'p':
				letterCount[15]++;
				break;
			case 'Q': case 'q':
				letterCount[16]++;
				break;
			case 'R': case 'r':
				letterCount[17]++;
				break;
			case 'S': case 's':
				letterCount[18]++;
				break;
			case 'T': case 't':
				letterCount[19]++;
				break;
			case 'U': case 'u':
				letterCount[20]++;
				break;
			case 'V': case 'v':
				letterCount[21]++;
				break;
			case 'W': case 'w':
				letterCount[22]++;
				break;
			case 'X': case 'x':
				letterCount[23]++;
				break;
			case 'Y': case 'y':
				letterCount[24]++;
				break;
			case 'Z': case 'z':
				letterCount[25]++;
				break;
		}
	}
}

void displayCount()
{
	int max = INT8_MIN;
	for(auto& i : letterCount)
	{
		if(i>max)
			max = i;
	}
	int maxDigits = log10(max) + 1;
	std::cout<<red(false, false, std::to_string(maxDigits))<<std::endl;
	
	std::cout<<yellow(true, false)<<std::flush;
	std::cout<<doubleSurround("Count of all letters");
	std::cout<<reset();
	
	int iterator = 0;
	std::cout<<thickTopLeft<<thickSurface<<thickSurfaceDown;
	while(iterator<maxDigits)
	{
		std::cout<<thickSurface;
		iterator++;
	}
	iterator = 0;
	std::cout<<thickTopRight<<std::endl;
	
	for(int i = 0; i < 26; i++)
	{
		if(letterCount[i]>0)
		{
			
			int iterator = 0;
			if(i != 0)
			{
				std::cout<<thicksideLeft<<thickSurface<<thickCross;
				while(iterator<maxDigits)
				{
					std::cout<<thickSurface;
					iterator++;
				}
				iterator = 0;
				std::cout<<thicksideRight<<std::endl;
			}
			switch(i)
			{
				case 0:
					std::cout<<thickside<<green(true, false, "A")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 1:
					std::cout<<thickside<<green(true, false, "B")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 2:
					std::cout<<thickside<<green(true, false, "C")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 3:
					std::cout<<thickside<<green(true, false, "D")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 4:
					std::cout<<thickside<<green(true, false, "E")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 5:
					std::cout<<thickside<<green(true, false, "F")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 6:
					std::cout<<thickside<<green(true, false, "G")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 7:
					std::cout<<thickside<<green(true, false, "H")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 8:
					std::cout<<thickside<<green(true, false, "I")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 9:
					std::cout<<thickside<<green(true, false, "J")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 10:
					std::cout<<thickside<<green(true, false, "K")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 11:
					std::cout<<thickside<<green(true, false, "L")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 12:
					std::cout<<thickside<<green(true, false, "M")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 13:
					std::cout<<thickside<<green(true, false, "N")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 14:
					std::cout<<thickside<<green(true, false, "O")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 15:
					std::cout<<thickside<<green(true, false, "P")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 16:
					std::cout<<thickside<<green(true, false, "Q")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 17:
					std::cout<<thickside<<green(true, false, "R")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 18:
					std::cout<<thickside<<green(true, false, "S")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 19:
					std::cout<<thickside<<green(true, false, "T")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 20:
					std::cout<<thickside<<green(true, false, "U")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 21:
					std::cout<<thickside<<green(true, false, "V")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 22:
					std::cout<<thickside<<green(true, false, "W")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 23:
					std::cout<<thickside<<green(true, false, "X")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 24:
					std::cout<<thickside<<green(true, false, "Y")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				case 25:
					std::cout<<thickside<<green(true, false, "Z")<<thickside<<cyan(true, false)<<std::setw(maxDigits)<<std::to_string(letterCount[i])<<reset()<<thickside<<std::endl;
					break;
				
			}
		}
	}
	std::cout<<thickBottomLeft<<thickSurface<<thickSurfaceUp;
	while(iterator<maxDigits)
	{
		std::cout<<thickSurface;
		iterator++;
	}
	iterator = 0;
	std::cout<<thickBottomRight<<std::endl;
}

