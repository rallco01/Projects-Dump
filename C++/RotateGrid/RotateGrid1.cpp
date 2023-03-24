#include "ANSITextCodes.h"
#include "TableCharacters.h"
#include "ContainerOverloading.h"
#include <vector>

using namespace std;

//these determine how big the grid is, and how many rotation cycles to go through, respectively
const int size = 10;
int maxCycles = 4;

//these are mainly for display, as well as to keep track of the current cycle
int maxNum = size*size;
int digits = std::to_string(maxNum).length();
int cycle = 0;

//initialise methods, because I am mainly a Java developer and cant break the old habits of writing main before everything else
template<size_t sizeX, size_t sizeY>
void rotateMatrix(int (&mat)[sizeX][sizeY]);
template<size_t sizeX, size_t sizeY>
void displayMatrix(int (&mat)[sizeX][sizeY]);

int main()
{
	int mat[size][size];
	int count = 1;
	for(int i = 0; i <size; i++)
	{
		for(int j = 0; j <size; j++)
		{
			mat[i][j] = count;
			count++;
		}
	}
	
	displayMatrix(mat);
	rotateMatrix(mat);
}
template<size_t sizeX, size_t sizeY>
void rotateMatrix(int (&mat)[sizeX][sizeY])
{
	//checking if the current cycle will extend past the max number of cycles (break point for recursive method)
	if(cycle < maxCycles)
	{
		for(int i = 0; i < size/2; i++)
		{
			for(int j = i; j < size - i - 1; j++)
			{
				//store current cell to access later
				int temp = mat[i][j];
				
				//move values from right to top
				mat[i][j] = mat[j][size-1-i];
				
				//move values from bottom to right
				mat[j][size-1-i] = mat[size-1-i][size-1-j];
				
				//move values from left to bottom
				mat[size-1-i][size-1-j] = mat[size-1-j][i];
				
				//put temp value into left
				mat[size-1-j][i] = temp;
			}
		}
		//display rotated matrix
		displayMatrix(mat);
		//iterate cycle
		cycle++;
		//repeat until current cycle is no longer less than max cycles
		rotateMatrix(mat);
	}
}
template<size_t sizeX, size_t sizeY>
void displayMatrix(int (&mat)[sizeX][sizeY])
{
	for(int i = 0; i <size; i++)
	{
		for(int j = 0; j <size; j++)
		{
			cout<<std::setw(digits)<<mat[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
}