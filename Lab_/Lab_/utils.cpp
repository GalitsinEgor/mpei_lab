#include "stdafx.h"
#include <iostream>
#include <iomanip>v
#include <list>
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

	int sumByPlaces(int value)
	{
		int sum = 0;
		while (value > 0)
		{
			sum += value % 10;
			value = value / 10;
		}
		return sum;
	}

	std::list<std::string> splitStringInternal(std::string str, std::string divider)
	{
		std::list<std::string> strings;
		std::string resStr = "";
		std::string tmpStr = "";

		int dividerId = 0;
		int dividerLength = divider.length();

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == divider[dividerId])
			{
				tmpStr += str[i];
				dividerId++;
				if (dividerId >= dividerLength)
				{
					dividerId = 0;
					tmpStr = "";
					strings.insert(strings.cend(), resStr);
					resStr = "";
				}
			}
			else
			{
				if (tmpStr != "")
				{
					resStr += tmpStr;
					dividerId = 0;
					tmpStr = "";
				}
				resStr += str[i];
			}
		}

		if (tmpStr != "")
		{
			resStr += tmpStr;
		}
		if (resStr != "")
		{
			strings.insert(strings.cend(), resStr);
		}
		return strings;
	}

	int* waitForIntArrayInput(int* resultLength)
	{
		std::string str = utils::waitForStringInput();
		std::list<std::string> strList = utils::splitStringInternal(str, " ");
		*resultLength = strList.size();
		int* result = new int[*resultLength];

		int index = 0;
		for each (std::string tmpStr in strList)
		{
			result[index++] = (int)std::stoi(tmpStr, nullptr, 10);
		}

		return result;
	}
}

