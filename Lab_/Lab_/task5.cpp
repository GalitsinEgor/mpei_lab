#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"
#include <cmath>


namespace task5
{
	using namespace std;

	void procedureC1(int a)
	{
		int div = 10;
		int mlp = 1;
		while (true)
		{
			int res = a % div;
			res = res / mlp;
			cout << res << endl;

			if (a % div == a)
			{
				break;
			}

			div = div * 10;
			mlp = mlp * 10;

			
		}
	}

	void procedure1(int a)
	{
		string strA = std::to_string(a);
		int length = strA.length() - 1;
		for (int i = length; i >= 0; i--)
		{
			cout << strA[i] << endl;
		}
	}
	void procedure2(int a)
	{
		string strA = std::to_string(a);
		int length = strA.length();
		for (int i = 0; i < length; i++)
		{
			cout << strA[i] << endl;
		}
	}
	void procedure3(int a)
	{
		for (int i = a; i > 0; i--)
		{
			int res = a % i;
			if (res == 0)
			{
				cout << i << " ";
			}
		}
	}
	void procedure4(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "-";
		}
	}
	void procedure5(int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	void procedure6(int a)
	{
		bool simple = true;
		for (int i = a; i > 0; i--)
		{
			int res = a % i;
			if (res == 0)
			{
				if (i != 1 && i != a)
				{
					simple = false;
					break;
				}
			}
		}

		if (simple)
		{
			cout << a << " is simple" << endl;
		}
		else
		{
			cout << a << " is NOT simple" << endl;
		}

		
	}

	template<typename T>
	T getMax(T a, T b)
	{
		T fMax = b;
		if (a > b)
		{
			fMax = a;
		}

		return fMax;
	}

	template<typename T>
	T getMin(T a, T b)
	{
		T min = b;
		if (a < b)
		{
			min = a;
		}
		return min;
	}

	template<typename T>
	T func1(T a, T b, T c)
	{
		T fMax = getMax<T>(a, b);
		T max = getMax<T>(fMax, c);
		return max;
	}

	template<typename T>
	T* func2(T a, T b, T c)
	{
		T fMin = getMin<T>(a, b);
		T min = getMin<T>(fMin, c);
		T max = func1<T>(a, b, c);

		return new T[2]{min,max};
	}

	int func3(int a)
	{
		string strN = std::to_string(a);
		return strN.length();
	}

	int func4(int a, int b)
	{
		int min = getMin<int>(a,b);
		
		for (int i = min; i > 0; i--)
		{
			int aRes = a % i;
			int bRes = b % i;
			if (aRes == 0 && bRes == 0)
			{
				return i;
			}
		}

		return 1;
	}

	int func5(int a, int b)
	{
		int max = getMax<int>(a, b);
		int res = max;
		while (true)
		{
			if (res % a == 0 && res % b == 0)
			{
				return res;
			}
			res++;
		}
	}

	int func6(int n)
	{
		int res = 1;
		for (int i = n; i > 0; i--)
		{
			res = res * i;
		}
		return res;
	}

	void procedureTest1()
	{
		int a = utils::waitForInput<int>("a");
		procedure1(a);
	}
	void procedureTestC1()
	{
		int a = utils::waitForInput<int>("a");
		procedureC1(a);
	}

	void procedureTest2()
	{
		int a = utils::waitForInput<int>("a");
		procedure2(a);
	}
	void procedureTest3()
	{
		int a = utils::waitForInput<int>("a");
		procedure3(a);
	}
	void procedureTest4()
	{
		int n = utils::waitForInput<int>("N");
		procedure4(n);
	}
	void procedureTest5()
	{
		int n = utils::waitForInput<int>("N");
		procedure5(n);
	}
	void procedureTest6()
	{
		int n = utils::waitForInput<int>("a");
		procedure6(n);
	}

	void funcTest1()
	{
		double a = utils::waitForInput<double>("a");
		double b = utils::waitForInput<double>("b");
		double c = utils::waitForInput<double>("c");
		double res = func1<double>(a,b,c);
		cout << "res: " << res << endl;
	}

	void funcTest2()
	{
		double a = utils::waitForInput<double>("a");
		double b = utils::waitForInput<double>("b");
		double c = utils::waitForInput<double>("c");
		double* res = func2<double>(a, b, c);
		cout << "min: " << res[0] << endl;
		cout << "max: " << res[1] << endl;
	}
	void funcTest3()
	{
		int a = utils::waitForInput<int>("N");
		int res = func3(a);
		cout << "res: " << res << endl;
	}
	void funcTest4()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int res = func4(a, b);
		cout << "max: " << res << endl;
	}
	void funcTest5()
	{
		int a = utils::waitForInput<int>("a");
		int b = utils::waitForInput<int>("b");
		int res = func5(a, b);
		cout << "res: " << res << endl;
	}
	void funcTest6()
	{
		int a = utils::waitForInput<int>("N");
		int res = func6(a);
		cout << "res: " << res << endl;
	}
	
}