#pragma once
#include <string>
#include <list>

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

	template<typename T>
	T getElementAt(std::list<T> lst, int index)
	{
		auto l_front = lst.begin();
		std::advance(l_front, index);
		T res = *l_front;
		return res;
	}

	std::string waitForStringInput();
	std::list<std::string> splitStringInternal(std::string str, std::string divider);
	#endif

	Point waitForPointInput();
	int CountSetw(int strLength, int displayWidth);
	int GetRandomInt(int a, int b);
	
}



