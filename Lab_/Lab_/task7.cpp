#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"
#include <cmath>
#include <string>
#include <list>
#include <functional>

namespace task7
{
	using namespace std;

	void fillArrayInternal(int size, int firstVal, bool print, std::function<int(int)> action)
	{
		int* myArray = new int[size];
		for (int i = 0; i < size; i++)
		{
			myArray[i] = action(firstVal);
			firstVal++;
			if (print)
			{
				cout << myArray[i] << " ";
			}
		}
	}

	void fillArray()
	{
		int size = utils::waitForInput<int>("array size");
		fillArrayInternal(size, 1, true, [](int x) { return x; });
	}

	void fillArray2()
	{
		string rawParams = utils::waitForStringInput();
		list<string> params = utils::splitStringInternal(rawParams, " ");

		int firstValue = std::stoi(utils::getElementAt<string>(params, 0), nullptr, 10);
		int length = std::stoi(utils::getElementAt<string>(params, 1), nullptr, 10);

		fillArrayInternal(length, firstValue, true, [](int x) { return x; });
	}

	void fillArraySquares()
	{
		int size = utils::waitForInput<int>("array size");
		fillArrayInternal(size, 1, true, [](int x) { return x * x; });
	}

	void fillArrayReversed()
	{
		int size = utils::waitForInput<int>("array size");
		fillArrayInternal(size, 0, true, [size](int x) { return size - x; });
	}
}