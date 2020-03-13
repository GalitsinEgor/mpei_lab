#pragma once
#include <string>

namespace utils
{
	struct Point
	{
		double x;
		double y;
	};

	#ifndef _UTILS_H_
	#define _UTILS_H_
	template<typename T>
	T waitForInput(std::string valueName)
	{
		std::cout << "Input " << valueName << std::endl;
		T res;
		std::cin >> res;
		return res;
	}

	std::string waitForStringInput();
	#endif

	Point waitForPointInput();
	int CountSetw(int strLength, int displayWidth);
	int GetRandomInt(int a, int b);
	
}



