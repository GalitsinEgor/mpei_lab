#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "utils.h"

namespace utils
{
	Point waitForPointInput()
	{
		Point point;
		std::cout << "Input X" << std::endl;
		std::cin >> point.x;

		std::cout << "Input Y" << std::endl;
		std::cin >> point.y;

		return point;
	}

	int GetRandomInt(int a, int b)
	{
		int res = a + rand() % static_cast<unsigned int>(b - a);
		return res;
	}
	int CountSetw(int strLength, int displayWidth)
	{
		int result = displayWidth / 2 + strLength / 2;
		return result;
	}
	std::string waitForStringInput()
	{
		std::string str;
		std::cout << "Input a string" << std::endl;;
		std::getline(std::cin, str);
		return str;
	}

}

