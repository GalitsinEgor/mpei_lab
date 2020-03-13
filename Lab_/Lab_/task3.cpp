#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"


namespace task3
{
	using namespace std;

	void branching1()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		if (a < b)
		{
			cout << "min value: " << a << endl;
		}
		else if (a == b)
		{
			cout << "values are equal" << endl;
		}
		else
		{
			cout << "min value: " << b << endl;
		}
	}
	void branching2()
	{
		int a = utils::waitForInput<int>("a");
		if (a == 0)
		{
			cout << a << " is zero" << endl;
		}
		else if (a < 0)
		{
			cout << a << " is negative" << endl;
		}
		else
		{
			cout << a << " is positive" << endl;
		}
	}
	void branching3()
	{
		int a = utils::waitForInput<int>("a");
		if (a % 2 != 0)
		{
			cout << a << " is odd" << endl;
		}
		else
		{
			cout << a << " is even" << endl;
		}
			
	}
	void branching4()
	{
		long number = utils::waitForInput<int>("number");
		string strNumberInitital = to_string(number);
		string strNumberReversed = strNumberInitital;
		std::reverse(strNumberReversed.begin(), strNumberReversed.end());

		if (strNumberInitital == strNumberReversed)
		{
			cout << "true " << strNumberInitital << "==" << strNumberReversed <<endl;
		}
		else
		{
			cout << "false " << strNumberInitital << "!=" << strNumberReversed << endl;
		}

	}
	void branching5()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int c = utils::waitForInput<int>("c");

		bool res = false;

		if (a < 0 || b < 0 || c < 0)
		{
			res = true;
		}

		cout << "res " << res << endl;
	}
	void branching6()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int c = utils::waitForInput<int>("c");

		bool res = false;

		if ((a / 10 > 0) && (b / 10 > 0) && (c / 10 > 0))
		{
			res = true;
		}

		cout << "res " << res << endl;
	}
	void branching7()
	{
		int minLengthRequired = 30;

		bool res = false;

		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int c = utils::waitForInput<int>("c");

		if ((a + b == minLengthRequired) || (a + c == minLengthRequired) || (b + c == minLengthRequired))
		{
			res = true;
		}
		
		cout << "res " << res << endl;
	}
	void branching8()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int x = utils::waitForInput<int>("x");
		int y = utils::waitForInput<int>("y");

		if (x >= a && x <= b)
		{
			cout << "x belongs to [a;b]" << endl;
		}
		else
		{
			cout << "x doesn't belong to [a;b]" << endl;
		}

		if (x >= 0 && y >= 0)
		{
			cout << "x and y are positiv" << endl;
		}
		else if (x < 0 && y < 0)
		{
			cout << "x and y are negative" << endl;
		}

	}
	void branching9()
	{
		int x = utils::waitForInput<int>("x");
		int y = utils::waitForInput<int>("y");

		bool xPositive = x >= 0;
		bool yPositive = y >= 0;

		if ((xPositive && !yPositive) || (!xPositive && yPositive))
		{
			cout << "x and y have different signs" << endl;
		}

		if (x == 0 || y == 0)
		{
			cout << "x or y is zero" << endl;
		}

		bool xIsZero = x == 0;
		bool yIsZero = y == 0;

		if ((xIsZero && !yIsZero) || (!xIsZero && yIsZero))
		{
			cout << "only x or y is zero" << endl;
		}

	}
	void branching10()
	{
		int month = utils::waitForInput<int>("month");

		if (month == 1 || month == 2 || month == 12)
		{
			cout << "it's winter" << endl;
		}
		else if (month == 3 || month == 4 || month == 5)
		{
			cout << "it's spring" << endl;
		}
		else if (month == 6 || month == 7 || month == 8)
		{
			cout << "it's summer" << endl;
		}
		else if (month == 9 || month == 10 || month == 11)
		{
			cout << "it's autumn" << endl;
		}
		else
		{
			cout << "it's not on our planet!" << endl;
		}
	}
	void branching11()
	{
		int month = utils::waitForInput<int>("month");
		switch (month)
		{
			case 1:
			case 2:
			case 12:
				cout << "it's winter" << endl;
				break;
			case 3:
			case 4:
			case 5:
				cout << "it's spring" << endl;
				break;
			case 6:
			case 7:
			case 8:
				cout << "it's summer" << endl;
				break;
			case 9:
			case 10:
			case 11:
				cout << "it's autumn" << endl;
				break;
			default:
				cout << "it's not on our planet!" << endl;
				break;
		}
	}
	void branching12()
	{
		utils::Point a = utils::waitForPointInput();
		if (a.y < 2)
		{
			cout << "Point is inside" << endl;
		}
		else
		{
			cout << "Point is outside" << endl;
		}
	}
	void branching13()
	{
		utils::Point a = utils::waitForPointInput();
		if ((a.x < 0 && a.y < 0) || (a.x < 0 && a.x < a.y) || (a.x > 0 && a.y < a.x))
		{
			cout << "Point is inside" << endl;
		}
		else
		{
			cout << "Point is outside" << endl;
		}
	}
	void branching14()
	{
		double r = 2;
		utils::Point a = utils::waitForPointInput();

		int res = sqrt(a.x*a.x + a.y*a.y);
		if (res > r)
		{
			cout << "Point is outside" << endl;
		}
		else
		{
			cout << "Point is inside" << endl;
		}
	}
	void branching15()
	{
		double r = 2;
		utils::Point a = utils::waitForPointInput();

		double res = sqrt(a.x*a.x + a.y*a.y);
		if ((res >= r) && (a.x >= 0 && a.y >= 0) && (a.x <= r) && (a.y <= r) && (a.x >= a.y))
		{
			cout << "Point is inside" << endl;
		}
		else
		{
			cout << "Point is outside" << endl;
		}
	}

	
}