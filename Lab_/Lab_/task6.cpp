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


namespace task6
{
	using namespace std;

	string getSubstring(string str, int startId, int length)
	{
		length = startId + length;
		if (length > str.length())
		{
			return "";
		}
		string res;
		for (int i = startId; i < length; i++)
		{
			res += str[i];
		}
		return res;
	}

	void replaceSubstring(string* str, string replacable, string replacement, int* substrings)
	{
		int replacableLength = replacable.length();
		int length = str->length();
		for (int i = 0; i < length; i++)
		{
			string res = getSubstring(*str, i, replacableLength);
			if (res == replacable)
			{
				str->erase(i, replacable.length());
				str->insert(i, replacement);
				length = str->length();
				*substrings = *substrings + 1;
			}
		}
	}

	void replaceCharInner(char* replacable, char* replacement, int length)
	{
		string str = utils::waitForStringInput();
		int replacementCounter = 0;

		for (unsigned int i = 0; i < str.length(); i++)
		{
			for (unsigned int j = 0; j < length; j++)
			{
				if (str[i] == replacable[j])
				{
					replacementCounter++;
					str[i] = replacement[j];
				}
			}
		}

		cout << str << endl;
		cout << replacementCounter << " chars have been replaced" << endl;
	}

	string removeCharInner(string initial, char* removable, int length)
	{
		string res = "";
		for (int i = 0; i < initial.length(); i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (initial[i] != removable[j])
				{
					res += initial[i];
				}
			}
		}

		return res;
	}


	void determinePalindromeInternal(string str)
	{
		string palindrome = str;
		reverse(palindrome.begin(), palindrome.end());

		if (str == palindrome)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	void replaceChar1()
	{
		char replacable[] = { 'c' };
		char replacement[] = { 'v' };

		replaceCharInner(replacable, replacement, 1);
	}

	void replaceChar2()
	{
		char replacable[] = { 'c', 'C' };
		char replacement[] = { 'z', 'Z' };

		replaceCharInner(replacable, replacement, 2);
	}

	void replaceChar3()
	{
		char replacable[] = { 'a', 'A', 'b', 'B'  };
		char replacement[] = { 'b', 'B', 'a', 'A' };

		replaceCharInner(replacable, replacement, 4);
	}

	void findWord()
	{
		string str = utils::waitForStringInput();
		string newStr = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				newStr += str[i];
			}
			else 
			{
				break;
			}
		}

		cout << newStr << endl;
	}

	void findLastWord()
	{
		string str = utils::waitForStringInput();
		string newStr = "";
		string finalStr = "";
		int length = str.length() - 1;
		for (int i = 0; i <= length; i++)
		{
			if (str[i] != ' ')
			{
				newStr += str[i];
			}
			else 
			{
				newStr = "";
			}

			if (newStr != "")
			{
				finalStr = newStr;
			}
		}

		cout << finalStr << endl;
	}

	void findLongestWord()
	{
		string str = utils::waitForStringInput();
		string longestStr = "";
		string newStr = "";
		int length = str.length() - 1;
		for (int i = 0; i <= length; i++)
		{
			if (str[i] != ' ')
			{
				newStr += str[i];
				continue;
			}
			if(str[i] == ' ' || i == length)
			{
				if (longestStr.length() < newStr.length())
				{
					longestStr = newStr;
				}
				newStr = "";
			}
		}
		cout << longestStr << endl;
	}

	void countWords()
	{
		string str = utils::waitForStringInput();
		string newStr = "";
		int length = str.length() - 1;
		int wordCounter = 0;
		for (int i = 0; i <= length; i++)
		{
			if (str[i] != ' ')
			{
				newStr += str[i];
			}
			if(str[i] == ' ' || i == length)
			{
				if (newStr != "")
				{
					wordCounter++;
				}
				newStr = "";
			}
		}

		cout << wordCounter << endl;
	}

	void determinePalindrome()
	{
		string str = utils::waitForStringInput();
		determinePalindromeInternal(str);
	}

	void determineSpacedPalindrome()
	{
		char removable[] = { ' ' };

		string str = utils::waitForStringInput();
		string cleanStr = removeCharInner(str, removable, 1);
		determinePalindromeInternal(cleanStr);
	}

	void splitFileName()
	{
		string fileName = utils::waitForStringInput();
		list<string> strings = utils::splitStringInternal(fileName, "\\");
		for each (string var in strings)
		{
			cout << var << endl;
		}
	}

	void shortName1()
	{
		string name = utils::waitForStringInput();
		list<string> strings = utils::splitStringInternal(name, " ");
		int id = 0;
		for each (string var in strings)
		{
			if (id == 0)
			{
				cout << var << " ";
			}
			else 
			{
				char in = var[0];
				cout << in << ".";
			}
			id++;
		}
	}

	void shortName2()
	{
		string name = utils::waitForStringInput();
		list<string> strings = utils::splitStringInternal(name, " ");
		int id = 2;
		string result[3];
		char in;
		string shortName;
		for each (string var in strings)
		{
			switch (id)
			{
			case 0:
			case 1:
				in = var[0];
				shortName = in;
				shortName += ".";
				result[id] = shortName;
				break;
			case 2:
				shortName = " ";
				shortName += var;
				result[id] = shortName;
				break;
			}
			id--;
		}
		for (int i = 0; i < 3; i++)
		{
			cout << result[i];
		}
	}

	void replaceSubstring()
	{
		string str = utils::waitForStringInput();
		string replacable = utils::waitForStringInput();
		string replacement = utils::waitForStringInput();

		int tmp = 0;
		replaceSubstring(&str, replacable, replacement, &tmp);
		cout << str << endl;
	}
	void countSubstrings()
	{
		string str = utils::waitForStringInput();
		string replacable = utils::waitForStringInput();
		string replacement = " ";

		int tmp = 0;
		replaceSubstring(&str, replacable, replacement, &tmp);
		cout << tmp << endl;
	}
	void replaceExtension()
	{
		string fileName = utils::waitForStringInput();
		string replacement = utils::waitForStringInput();

		list<string> strings = utils::splitStringInternal(fileName, ".");

		auto l_front = strings.begin();
		std::advance(l_front, 0);
		string firstString = *l_front;

		string result = firstString + "." + replacement;
		cout << result << endl;
	}

	void formatText()
	{
		int width = utils::waitForInput<int>("text width");
		cin.ignore();
		string text = utils::waitForStringInput();
		list<string> strings = utils::splitStringInternal(text, " ");

		int strLength = 0;
		for each (string var in strings)
		{
			if ((strLength + var.length() + 1) >= width)
			{
				cout << endl;
				strLength = 0;
			}

			cout << var << " ";
			strLength += var.length() + 1;
		}
	}

	void removeDoubleSpaces()
	{
		string str = utils::waitForStringInput();
		int tmp = 0;
		replaceSubstring(&str, "  ", " ", &tmp);
		cout << str << endl;
	}

	void binToDec()
	{
		string binary = utils::waitForInput<string>("binary");
		std::cout << std::stoi(binary, nullptr, 2) << endl;
	}

	bool checkDateFormatInsternal(string dateStr)
	{
		list<string> strings = utils::splitStringInternal(dateStr, ".");
		int size = strings.size();
		if (size < 3 || size > 3)
			return false;

		int id = 0;
		for each (string var in strings)
		{
			switch (id)
			{
				case 0:
				{
					int day = std::stoi(var, nullptr, 10);
					if (day < 1 || day > 31)
						return false;

					break;
				}
				case 1:
				{
					int month = std::stoi(var, nullptr, 10);
					if (month < 1 || month > 12)
						return false;

					break;
				}
				case 2:
				{
					int year = std::stoi(var, nullptr, 10);
					if (year < 1000)
						return false;

					break;
				}
			}
			id++;
		}

		return true;
	}
	void checkDateFormat()
	{
		string dateStr = utils::waitForStringInput();
		if (checkDateFormatInsternal(dateStr))
		{
			cout << "YES" << endl;
		}
		else 
		{
			cout << "NO" << endl;
		}
			
	}

	void simpleCalc()
	{
		string exp = utils::waitForStringInput();
		string currentValue = "";
		int action = 1;
		int result = 0;
		int lastNumber = 0;
		int length = exp.length() - 1;
		for (int i = 0; i <= length; i++)
		{
			if (exp[i] != '+' && exp[i] != '-')
			{
				currentValue += exp[i];
				if (i != length)
				{
					continue;
				}
			}

			lastNumber = std::stoi(currentValue, nullptr, 10);
			currentValue = "";
			result += lastNumber * action;

			if (exp[i] == '+')
			{
				action = 1;
			}
			else if (exp[i] == '-')
			{
				action = -1;
			}
		}

		cout << result << endl;
	}
	
}