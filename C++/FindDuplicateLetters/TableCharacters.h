#include <iostream>
#include <string>
//--------+=====Normal Table Characters=====+--------//{
const char *topLeft = u8"\u250c";
const char *surface = u8"\u2500";
const char *surfaceUp = u8"\u2534";
const char *surfaceDown = u8"\u252c";
const char *topRight = u8"\u2510";
const char *side = u8"\u2502";
const char *sideLeft = u8"\u251c";
const char *sideRight = u8"\u2524";
const char *bottomLeft = u8"\u2514";
const char *bottomRight = u8"\u2518";
const char *cross = u8"\u253c";
//}
//--------+=====Thick Table Characters=====+--------//{
const char *thickTopLeft = u8"\u250f";
const char *thickSurface = u8"\u2501";
const char *thickSurfaceUp = u8"\u253b";
const char *thickSurfaceDown = u8"\u2533";
const char *thickTopRight = u8"\u2513";
const char *thickside = u8"\u2503";
const char *thicksideLeft = u8"\u2523";
const char *thicksideRight = u8"\u252b";
const char *thickBottomLeft = u8"\u2517";
const char *thickBottomRight = u8"\u251b";
const char *thickCross = u8"\u254b";
//}
//--------+=====Double Table Characters=====+--------//{
const char *doubleTopLeft = u8"\u2554";
const char *doubleSurface = u8"\u2550";
const char *doubleSurfaceUp = u8"\u2569";
const char *doubleSurfaceDown = u8"\u2566";
const char *doubleTopRight = u8"\u2557";
const char *doubleside = u8"\u2551";
const char *doublesideLeft = u8"\u2560";
const char *doublesideRight = u8"\u2563";
const char *doubleBottomLeft = u8"\u255a";
const char *doubleBottomRight = u8"\u255d";
const char *doubleCross = u8"\u256c";
//}

std::string normalSurround(std::string toSurround)
{
	int length = toSurround.length();
	std::string finalString = "";
	finalString += topLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += surface;
	}
	finalString += topRight;
	finalString += '\n';
	finalString += side + toSurround + side + '\n';
	finalString += bottomLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += surface;
	}
	finalString += bottomRight;
	finalString += '\n';
	return finalString;
}

std::string thickSurround(std::string toSurround)
{
	int length = toSurround.length();
	std::string finalString = "";
	finalString += thickTopLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += thickSurface;
	}
	finalString += thickTopRight;
	finalString += '\n';
	finalString += thickside + toSurround + thickside + '\n';
	finalString += thickBottomLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += thickSurface;
	}
	finalString += thickBottomRight;
	finalString += '\n';
	return finalString;
}

std::string doubleSurround(std::string toSurround)
{
	int length = toSurround.length();
	std::string finalString = "";
	finalString += doubleTopLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += doubleSurface;
	}
	finalString += doubleTopRight;
	finalString += '\n';
	finalString += doubleside + toSurround + doubleside + '\n';
	finalString += doubleBottomLeft;
	for(int i = 0; i<length; i++)
	{
		finalString += doubleSurface;
	}
	finalString += doubleBottomRight;
	finalString += '\n';
	return finalString;
}


void TestTableCharacters()
{
	std::cout<<topLeft<<surface<<surfaceDown<<surface<<topRight<<std::endl;
	std::cout<<side<<" "<<side<<" "<<side<<topLeft;
	for(int i = 0; i<23; i++)
	{
		std::cout<<surface;
	}
	std::cout<<topRight<<std::endl;
	std::cout<<sideLeft<<surface<<cross<<surface<<sideRight<<side<<"Normal Table Characters"<<side<<"Use code: 'normalSurround(string toSurround)'"<<std::endl;
	std::cout<<side<<" "<<side<<" "<<side<<bottomLeft;
	for(int i = 0; i<23; i++)
	{
		std::cout<<surface;
	}
	std::cout<<bottomRight<<std::endl;
	std::cout<<bottomLeft<<surface<<surfaceUp<<surface<<bottomRight<<std::endl;
	
	std::cout<<thickTopLeft<<thickSurface<<thickSurfaceDown<<thickSurface<<thickTopRight<<std::endl;
	std::cout<<thickside<<" "<<thickside<<" "<<thickside<<thickTopLeft;
	for(int i = 0; i<22; i++)
	{
		std::cout<<thickSurface;
	}
	std::cout<<thickTopRight<<std::endl;
	std::cout<<thicksideLeft<<thickSurface<<thickCross<<thickSurface<<thicksideRight<<thickside<<"Thick Table Characters"<<thickside<<"Use code: 'thickSurround(string toSurround)'"<<std::endl;
	std::cout<<thickside<<" "<<thickside<<" "<<thickside<<thickBottomLeft;
	for(int i = 0; i<22; i++)
	{
		std::cout<<thickSurface;
	}
	std::cout<<thickBottomRight<<std::endl;
	std::cout<<thickBottomLeft<<thickSurface<<thickSurfaceUp<<thickSurface<<thickBottomRight<<std::endl;
	
	std::cout<<doubleTopLeft<<doubleSurface<<doubleSurfaceDown<<doubleSurface<<doubleTopRight<<std::endl;
	std::cout<<doubleside<<" "<<doubleside<<" "<<doubleside<<doubleTopLeft;
	for(int i = 0; i<23; i++)
	{
		std::cout<<doubleSurface;
	}
	std::cout<<doubleTopRight<<std::endl;
	std::cout<<doublesideLeft<<doubleSurface<<doubleCross<<doubleSurface<<doublesideRight<<doubleside<<"Double Table Characters"<<doubleside<<"Use code: 'doubleSurround(string toSurround)'"<<std::endl;
	std::cout<<doubleside<<" "<<doubleside<<" "<<doubleside<<doubleBottomLeft;
	for(int i = 0; i<23; i++)
	{
		std::cout<<doubleSurface;
	}
	std::cout<<doubleBottomRight<<std::endl;
	std::cout<<doubleBottomLeft<<doubleSurface<<doubleSurfaceUp<<doubleSurface<<doubleBottomRight<<std::endl;
}