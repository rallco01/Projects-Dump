#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <fstream>

int generateRandomNumber(int min, int max)
{
	std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}
int generateRandomNumber(int range)
{
	std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, range);
	return distr(eng);
}

