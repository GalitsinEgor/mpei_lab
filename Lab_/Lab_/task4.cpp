#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"
#include <cmath>


namespace task4
{
	using namespace std;

	void cycling1()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		bool minus = false;
		int am = 0;
		int bm = 0;
		if (a < 0 && b >= 0)
		{
			bm = abs((int)a);
			am = b;
			minus = true;
		}
		else if (b < 0 && a >= 0)
		{
			bm = abs((int)b);
			am = a;
			minus = true;
		}
		else
		{
			am = abs((int)a);
			bm = abs((int)b);
		}

		int res = 0;
		for (int i = 0; i < bm; i++)
		{
			if (minus)
			{
				res -= am;
			}
			else{
				res += am;
			}
		}

		std::cout << res << endl;
	}

	void cycling2()
	{
		int n = utils::waitForInput<int>("N");
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			res += i;
		}

		std::cout << res << endl;
	}
	void cycling3()
	{
		int n = utils::waitForInput<int>("N");
		for (int i = 1; i <= n; i++)
		{
			std::cout << i << " ";
		}
	}
	void cycling4()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		for (size_t i = a; i <= b; i++)
		{
			std::cout << pow(i,2) << " ";
		}
	}
	void cycling5()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");

		int res = 0;
		for (size_t i = a; i <= b; i++)
		{
			res += pow(i, 2);
		}

		std::cout << res << endl;
	}
	void cycling6()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int n = utils::waitForInput<int>("N");

		for (size_t i = 0; i < n; i++)
		{
			std::cout << utils::GetRandomInt(a, b+1) << " ";
		}
	}
	void cycling7()
	{
		int n = utils::waitForInput<int>("N");

		string strN = std::to_string(n);
		int res = 0;
		for (size_t i = 0; i < strN.length(); i++)
		{
			int intVal = std::stoi(string(1, strN[i]), nullptr, 0);
			res += intVal;
		}

		std::cout << res << endl;
	}
	void cycling8()
	{
		int sum = 0;
		int mul = 0;
		while (true)
		{
			int v = utils::waitForInput<int>("input number or zero");
			if (v == 0)
			{
				std::cout << "sum: " << sum << endl;
				std::cout << "mul: " << mul << endl;
				break;
			}
			else
			{
				sum += v;
				if (mul == 0)
				{
					mul = v;
				}
				else{
					mul = mul * v;
				}
			}
		}

		return;

		/*int n = 0;
		string strN = std::to_string(n);
		int res = 0;
		int mul = 0;
		for (size_t i = 0; i < strN.length(); i++)
		{
			int intVal = std::stoi(string(1, strN[i]), nullptr, 0);
			res += intVal;
			if (i == 0)
			{
				mul = intVal;
			}
			else
			{
				mul = mul * intVal;
			}
		}

		std::cout << "sum: " << res << endl;
		std::cout << "mul: " << mul << endl;*/
	}
	void cycling9()
	{
		int max = 0;
		int min = INT_MAX;
		while (true)
		{
			int n = utils::waitForInput<int>("input number or zero");
			if (n == 0)
			{
				std::cout << "max: " << max << endl;
				std::cout << "min: " << min << endl;
				break;
			}
			else
			{
				if (max < n)
					max = n;

				if (min > n)
					min = n;
			}
		}
	}
	void cycling10()
	{
		int n = utils::waitForInput<int>("N");
		int res = 1;
		for (size_t i = 1; i <= n; i++)
		{
			res = res * i;
		}

		std::cout << "res: " << res << endl;
	}
}