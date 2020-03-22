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
#include "hanoiTowers.h"
#include <iomanip>


void pauseConsole()
{
	char c;
	std::cin >> c;
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

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

	pauseConsole();
	return 0;
}

