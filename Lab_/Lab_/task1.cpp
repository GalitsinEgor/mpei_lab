#include "stdafx.h"
#include "task1.h"
#include<string>
#include <iostream>
#include <iomanip>

namespace task1
{
	using namespace std;

	void stairCase()
	{
		string tab = "   ";
		std::cout << "Student, " << std::endl;
		std::cout << tab << "give your" << std::endl;
		std::cout << tab << tab << "papers " << std::endl;
	}

	void drawBuilding(bool drawSecond)
	{
		string building[] =
		{
			"   A   ","  AMA  "," AMMMA ","AMMMMMA"," MMMMM "," ZZ ZZ "," MMMMM "
		};

		string tab = "     ";
		for (int i = 0; i < 7; i++)
		{
			std::cout << building[i] << setw(10);
			if (drawSecond)
			{
				std::cout << tab << building[i];
			}

			std::cout << "" << std::endl;
		}
	}

	void drawBuildingManuallyLine(string str, bool drawSecond)
	{
		int indent = 3;
		int width = 7;

		int strLength = str.length();
		int delta = width - strLength;
		int hDelta = delta / 2;
		int setwParam = hDelta + strLength;

		str.length();

		std::cout << setw(setwParam) << str;
		if (drawSecond)
		{
			std::cout << setw(hDelta + setwParam + indent) << str;
		}

		std::cout << endl;
	}
	
	void drawBuildingManually(bool drawSecond)
	{
		drawBuildingManuallyLine("A", drawSecond);
		drawBuildingManuallyLine("AMA", drawSecond);
		drawBuildingManuallyLine("AMMMA", drawSecond);
		drawBuildingManuallyLine("AMMMMMA", drawSecond);
		drawBuildingManuallyLine("MMMMM", drawSecond);
		drawBuildingManuallyLine("II II", drawSecond);
		drawBuildingManuallyLine("MMMMM", drawSecond);
	}

	void calc()
	{
		//what ?

		int a = 4;
		int b = 2;

		std::cout << b << "+" << a << "=" << a + b << std::endl;
		std::cout << "Z(" << a << ")=F(" << b << ")" << std::endl;
		std::cout << "a=" << a << ";" << "b=" << b << std::endl;
		std::cout << "Result:(" << a << ";" << b << ")" << std::endl;
	}
}
