#include "stdafx.h"
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES

#include <math.h>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"

namespace task2
{
	using namespace std;
	using namespace utils;

	void calc1()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int c = utils::waitForInput<int>("c");

		std::cout << "sum" << a + b + c << std::endl;
		std::cout << "mid" << (a + b + c) / 3 << std::endl;
	}

	void calc2()
	{
		Point a = waitForPointInput();
		Point b = waitForPointInput();

		double length = pow((b.x - a.x), 2) + pow((b.y - a.y), 2);
		length = sqrt(length);

		cout << "section length is " << length << endl;
	}

	void calc3()
	{
		int seed = utils::GetRandomInt(100, 999);

		cout << "Initial value: " << seed << endl;

		int d3 = seed / 100;
		seed = seed % 100;

		int d2 = seed / 10;
		seed = seed % 10;

		int d1 = seed;

		cout << "hundreds:" << d3 << ", decimal: " << d2 << ", units: " << d1 << endl;
	}

	void calc4()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		int c = a;
		a = b;
		b = c;

		cout << "a=" << a << " b=" <<  b << endl;
	}

	void calc5()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		swap(a, b);

		cout << "a=" << a << " b=" << b << endl;
	}

	void calc6()
	{
		int x = utils::waitForInput<int>("x");
		std::cout << std::bitset<32>(x)<<endl;
	}

	void calc7()
	{
		string binary = utils::waitForInput<string>("binary");
		std::cout << std::stoi(binary, nullptr, 2) << endl;
	}

	void calc8()
	{
		double x = utils::waitForInput<double>("x");
		double y = utils::waitForInput<double>("y");

		std::cout << pow(x,y) << endl;
	}

	void calc9()
	{
		double a = utils::waitForInput<double>("a");

		double b = a * a;	
		a = b * b;
		a = a * a * b;		

		std::cout << "res: " << a << endl;
	}

	void calc10()
	{
		int n = utils::waitForInput<double>("N");
		int res = utils::GetRandomInt(2, n + 1);
		std::cout << "on duty dude: " << res << endl;
	}

	void calc11()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		int res = utils::GetRandomInt(a, b);
		int res1 = utils::GetRandomInt(a, b);
		int res2 = utils::GetRandomInt(a, b);

		std::cout << "res0=" << res << std::endl;
		std::cout << "res1=" << res1 << std::endl;
		std::cout << "res2=" << res2 << std::endl;
	}

	void calc12()
	{
		int accuracy = 1000;

		double a = utils::waitForInput<double>("a");
		double b = utils::waitForInput<double>("b");

		int dif = static_cast<unsigned int>(b - a);
		if (dif == 0)
			dif++;

		double res = a + (rand() % (dif * accuracy) / (double)accuracy);
		std::cout << "res=" << std::setprecision(accuracy)<< res << std::endl;
	}

	void calc13()
	{
		Point a = waitForPointInput();
		Point b = waitForPointInput();
		Point c = waitForPointInput();

		double matrixRes = (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
		double res = abs(matrixRes/(double)2);

		std::cout << "S=" << res << std::endl;
	}

	void calc14()
	{
		double r = utils::waitForInput<double>("R");

		double s = M_PI * pow(r, 2);
		double l = 2 * M_PI * r;

		std::cout << "S=" << s << std::endl;
		std::cout << "C=" << l << std::endl;

	}

	void calc15Cycle()
	{
		double weight = utils::waitForInput<double>("weight");
		int days = 30;
		int percent = 1;

		for (int i = 0; i < days; i++)
		{
			weight -= (weight / (double)100) * percent;
		};

		std::cout << "Result=" << weight << std::endl;
	}

	void calc15Formula()
	{
		double weight = utils::waitForInput<double>("weight");
		int days = 30;
		int percent = 1;

		double res = weight * ((double)pow(100 - percent, days) / (double)pow(100, days));
		std::cout << "Result=" << res << std::endl;
	}
}