#include "stdafx.h"
#include <iostream>
#include "utils.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "sorts.h"
#include "matrices.h"
#include "hanoiTowers.h"
#include "SecondYearLabs.h"
#include <iomanip>

using namespace std;

void pauseConsole()
{
	char c;
	std::cin >> c;
}

void lab1()
{
	int number = utils::waitForInput<int>("Task number");
	std::cin.ignore();
	switch (number)
	{
	case 1:
		sorts::task1();
		break;
	case 2:
		sorts::task2();
		break;
	case 3:
		sorts::task3();
		break;
	case 4:
		sorts::task4();
		break;
	case 5:
		sorts::task5();
		break;
	case 6:
		sorts::task6();
		break;
	case 7:
		sorts::task7();
		break;
	case 8:
		sorts::task8();
		break;
	case 9:
		sorts::task9();
		break;
	case 10:
		sorts::task10();
		break;
	case 11:
		sorts::task11();
		break;

	default:
		std::cout << "wrong number" << std::endl;
		break;
	}

}

void lab2()
{
	int number = utils::waitForInput<int>("Task number");
	std::cin.ignore();
	switch (number)
	{
	case 1:
		matrices::countMatrixSum();
		break;
	case 2:
		matrices::countDeterminedElement();
		break;
	case 3:
		matrices::printMinMax();
		break;
	case 4:
		matrices::printLinesWithMinSum();
		break;
	case 5:
		matrices::printColumnsContainMaxValue();
		break;
	case 6:
		matrices::nullAllAboveMainDiagonal();
		break;
	case 7:
		matrices::checkIfSymmetric();
		break;

	default:
		std::cout << "wrong number" << std::endl;
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	SecondYearLabs* labs = new SecondYearLabs();
	labs->Task_1_3_3_6();

	pauseConsole();
	return 0;
}

int _tmain2(int argc, _TCHAR* argv[])
{
	srand(time(0));

	cout << 1 << "- sorts" << endl;
	cout << 2 << "- matrices" << endl;

	int labId = utils::waitForInput<int>("lab id");

	switch (labId)
	{
	case 1:
		lab1();
		break;
	case 2:
		lab2();
		break;
	default:
		cout << "unknown" << endl;
		break;
	}

	pauseConsole();
	return 0;
}

