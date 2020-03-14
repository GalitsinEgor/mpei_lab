#include "stdafx.h"
#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
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

	task6::simpleCalc();

	//hanoiTowers::start();

	//task5::procedureTest1();


	//task4::cycling1();

	/*task1::calc();
	task1::drawBuildingManually(false);
	task1::drawBuildingManually(true);
	task1::stairCase();*/

	//task2::calc1();
	//task2::calc2();
	//task2::calc3();
	//task2::calc4();
	//task2::calc5();
	//task2::calc6();
	//task2::calc7();
	//task2::calc8();
	//task2::calc9();
	//task2::calc10();
	//task2::calc11();
	//task2::calc12();
	//task2::calc13();
	//task2::calc14();
	//task2::calc15Cycle();
	//task2::calc15Formula();


	pauseConsole();
	return 0;
}

