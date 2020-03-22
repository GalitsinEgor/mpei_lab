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
#include <unordered_map> 

namespace sorts
{
	using namespace std;

	void printArray(int* arr, int length)
	{
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	bool checkAllRange(int* arr, int startIndex, int length, function<bool(int)> compareAction)
	{
		for (int i = startIndex; i < length; i++)
		{
			if (compareAction(arr[i]))
			{
				return false;
			}
		}
		return true;
	}

	bool checkAllBigger(int* arr, int startIndex, int length, int valueToCompare)
	{
		return checkAllRange(arr, startIndex, length,
			[valueToCompare](int val) {return (val < valueToCompare || val == valueToCompare); });
	}
	bool checkAllSmaller(int* arr, int startIndex, int length, int valueToCompare)
	{
		return checkAllRange(arr, startIndex, length,
			[valueToCompare](int val) {return (val > valueToCompare || val == valueToCompare); });
	}

	void bubbleSortInner(int* arr, int length, bool printAfterSwap, function<bool(int, int, int)> compareAction)
	{
		bool sorted = false;
		int lastId = length - 1;
		int iterCount = 0;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < lastId; i++)
			{
				int nextId = i + 1;
				if (compareAction(arr[i], arr[nextId], iterCount))
				{
					utils::swap(arr, i, nextId);
					if (printAfterSwap)
					{
						printArray(arr, length);
					}
					sorted = false;
				}
			}
			iterCount++;
		}
	}

	void bubbleSort(int* arr, int length, function<bool(int, int)> compareAction)
	{
		bubbleSortInner(arr, length, false, [compareAction](int x, int y, int iterCount)
		{
			return compareAction(x, y);
		});
	}

	void bubbleSortOdd(int* arr, int length)
	{
		bool sorted = false;
		int lastId = length - 2;
		int iterCount = 0;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < lastId; i += 2)
			{
				int nextId = i + 2;
				if (arr[i] > arr[nextId])
				{
					utils::swap(arr, i, nextId);
					sorted = false;
				}
			}
			iterCount++;
		}
	}

	int* readArray(int* resultLength)
	{
		string str = utils::waitForStringInput();
		list<string> strList = utils::splitStringInternal(str, " ");
		*resultLength = strList.size();
		int* result = new int[*resultLength];

		int index = 0;
		for each (string tmpStr in strList)
		{
			result[index++] = (int)std::stoi(tmpStr, nullptr, 10);
		}
		
		return result;
	}

	int findMinElementId(int* arr, int rangeStartId, int rangeLength)
	{
		int minElementId = rangeStartId;
		int cycleStartId = rangeStartId + 1;
		for (int i = cycleStartId; i < rangeLength; i++)
		{
			if (arr[i] < arr[minElementId])
			{
				minElementId = i;
			}
		}

		return minElementId;
	}

	void moveElementDownToPosition(int* arr, int elementId, int positionId)
	{
		int currentId = elementId;
		while (currentId != positionId)
		{
			utils::swap(arr, currentId, currentId - 1);
			currentId--;
		}
	}

	void sortFirstSeveral(int* arr, int length, int sortedElementsCount)
	{
		for (int i = 0; i < sortedElementsCount; i++)
		{
			int id = findMinElementId(arr, i, length);
			moveElementDownToPosition(arr, id, i);
		}
	}

	void task1()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		bubbleSort(arrPtr, length, [](int x, int y)
		{
			return x % 10 > y % 10;
		});
		printArray(arrPtr, length);
	}

	void task2()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		sortFirstSeveral(arrPtr, length, 3);
		printArray(arrPtr, length);
	}

	void task3()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		

		int* knownValues = new int[length];
		knownValues[0] = arrPtr[0];
		int knownValuesLength = 1;

		bubbleSort(arrPtr, length, [knownValues, &knownValuesLength](int x, int y)
		{
			bool addKnownValue = true;
			for (int i = 0; i < knownValuesLength; i++)
			{
				if (knownValues[i] == y)
				{
					addKnownValue = false;
				}
			}
			if (addKnownValue)
			{
				knownValues[knownValuesLength] = y;
				knownValuesLength++;
			}	
			
			return x > y;
		});
		printArray(arrPtr, length);
		cout << knownValuesLength << endl;
	}
	struct valueCount
	{
		int value;
		int count;
	};

	void task4()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		int kValue = utils::waitForInput<int>("K value");

		unordered_map<int, int> umap;
		umap[arrPtr[0]] = 1;
		bubbleSortInner(arrPtr, length, false, [&umap](int x, int y, int iterCount)
		{
			if (iterCount == 0)
			{
				umap[y] += 1;
			}
			return x > y;
		});

		printArray(arrPtr, length);

		for each (auto var in umap)
		{
			if (var.second == kValue)
			{
				cout << var.first << " ";
			}
		}

		cout << endl;
		
	}

	void task5()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		bubbleSortInner(arrPtr, length, true, [](int x, int y, int iterCounter)
		{
			return x > y;
		});
	}

	void task6()
	{
		int length = 0;
		int* arrPtr = readArray(&length);

		unordered_map<int, int> umap;
		for (int i = 0; i < length; i++)
		{
			umap[arrPtr[i]] += 1;
		}
	
		int maxRepeatedElem = -1;
		for each (auto var in umap)
		{
			if (var.second > 1 && var.first > maxRepeatedElem)
			{
				maxRepeatedElem = var.first;
			}
		}

		cout << maxRepeatedElem << endl;
	}
	
	void task7()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		bubbleSort(arrPtr, length, [](int x, int y)
		{
			int newX = utils::sumByPlaces(x);
			int newY = utils::sumByPlaces(y);

			return newX < newY;
		});
		printArray(arrPtr, length);
	}
	void task8()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		bubbleSortInner(arrPtr, length, true, [](int x, int y, int ignr)
		{
			return x > y;
		});
		//printArray(arrPtr, length);
	}
	void task9()
	{
		int length = 0;
		int* arrPtr = readArray(&length);
		bubbleSort(arrPtr, length / 2, [](int x, int y)
		{
			return x > y;
		});
		int* secondPartPtr = &arrPtr[length / 2];
		bubbleSort(secondPartPtr, length / 2, [](int x, int y)
		{
			return x < y;
		});
		printArray(arrPtr, length);
	}

	void task10()
	{
		int length = 0;
		int* arrPtr = readArray(&length);

		int midId = length / 2;

		int step = 1;
		int action = 1;
		bool found = false;
		while (midId < length && midId > 0)
		{
			int midVal = arrPtr[midId];
			//right && left 
			if (checkAllBigger(arrPtr, midId + 1, length, midVal)
				&& checkAllSmaller(arrPtr, 0, midId, midVal))
			{
				found = true;
				break;
			}
			//left && right
			if (checkAllBigger(arrPtr, 0, midId, midVal)
				&& checkAllSmaller(arrPtr, midId + 1, length, midVal))
			{
				found = true;
				break;
			}
			
			midId = midId + (step * action);
			step++;
			action = action * -1;
		}

		if (found) {

			cout << arrPtr[midId] << endl;
		}
		else {
			cout << "NO RESULT" << endl;
		}
		

	}

	void task11()
	{
		int length = 0;
		int* arrPtr = readArray(&length);

		bubbleSortOdd(arrPtr, length);

		printArray(arrPtr, length);
	}



}