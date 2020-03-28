#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <bitset>
#include "utils.h"
#include <string>
#include <functional>

namespace matrices
{
	using namespace std;

	class Matrix
	{
	private:
		const int INIITIAL_VALUE = 0;

		int lines;
		int columns;

		int** arrPtr = nullptr;

		void create2dArray()
		{
			arrPtr = new int* [lines];
			for (int i = 0; i < lines; i++)
			{
				int* colPtr = new int[columns];
				arrPtr[i] = colPtr;
				for (int j = 0; j < columns; j++)
				{
					colPtr[j] = INIITIAL_VALUE;
				}
			}
		}

	public:
		Matrix(int _lines, int _columns)
		{
			if (_lines == 0 || _columns == 0)
				throw - 2;

			lines = _lines;
			columns = _columns;

			create2dArray();
		}

		~Matrix()
		{
			for (int i = 0; i < lines; i++)
			{
				delete[] arrPtr[i];
			}

			delete[] arrPtr;
		}

		bool checkIfSquare()
		{
			return lines == columns;
		}

		bool checkIfSymmetric()
		{
			bool result = true;
			forEachAboveMainDiagonal([this, &result](int value, int lineId, int colId)
			{
				result = getElement(colId, lineId) == value;
				return result;
			});
			return result;
		}

		void forEach(function<bool(int, int, int)> elementLineIdColIdProcessor)
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (!elementLineIdColIdProcessor(arrPtr[i][j], i, j))
						return;
				}
			}
		}

		void forEachLine(function<bool(int*, int)> linePtrlineIdProcessor)
		{
			for (int i = 0; i < lines; i++)
			{
				if (!linePtrlineIdProcessor(arrPtr[i], i))
					return;
			}
		}

		void forEachColumn(function<bool(int*, int)> colPtrColIdProcessor)
		{
			for (int j = 0; j < columns; j++)
			{
				int* columnPtr = new int[lines];
				writeColumnTo(columnPtr, j);
				bool _continue = colPtrColIdProcessor(columnPtr, j);
				delete[] columnPtr;
				if (!_continue)
					return;
			}
		}

		void forEachAboveMainDiagonal(function<bool(int, int, int)> elementLineIdColIdProcessor)
		{
			if (!checkIfSquare())
				throw -1;

			for (int i = 0; i < lines; i++)
			{
				int colId = i + 1;
				for (int j = colId; j < columns; j++)
				{
					if (!elementLineIdColIdProcessor(arrPtr[i][j], i, j))
					{
						return;
					}
				}
			}
		}

		void printMatrix()
		{
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					cout << arrPtr[i][j] << " ";
				}
				cout << endl;
			}
		}

		string elementToString(int lineId, int colId)
		{
			string res = "";
			res += "coords: [" + to_string(1 + lineId) + "-" + to_string(1 + colId) + "], value: " + to_string(arrPtr[lineId][colId]);
			return res;
		}

		void setElement(int value, int lineId, int colId)
		{
			arrPtr[lineId][colId] = value;
		}

		void setLine(int* valueArrPtr, int lineId)
		{
			for (int i = 0; i < columns; i++)
			{
				arrPtr[lineId][i] = valueArrPtr[i];
			}
		}

		int getLines()
		{
			return lines;
		}

		int getColumns()
		{
			return columns;
		}

		int getElement(int lineId, int colId)
		{
			return arrPtr[lineId][colId];
		}

		int getMaxElement()
		{
			int outLineId=0;
			int outColId=0;
			return getMaxElement(&outLineId, &outColId);
		}

		int getMaxElement(int* outLineId, int* outColId)
		{
			int max = arrPtr[0][0];
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (max < arrPtr[i][j])
					{
						max = arrPtr[i][j];
						*outLineId = i;
						*outColId = j;
					}
				}
			}
			return max;
		}

		int getMinElement(int* outLineId, int* outColId)
		{
			int min = arrPtr[0][0];
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (min > arrPtr[i][j])
					{
						min = arrPtr[i][j];
						*outLineId = i;
						*outColId = j;
					}
				}
			}
			return min;
		}

		int getElementSum()
		{
			int sum = 0;
			forEach([&sum](int elem, int lineId, int colId)
			{
				sum += elem;
				return true;
			});
			return sum;
		}

		void writeColumnTo(int* columnArrPtr, int colId)
		{
			for (int i = 0; i < lines; i++)
			{
				columnArrPtr[i] = arrPtr[i][colId];
			}
		}

		void writeLineTo(int* lineArrPtr, int lineId)
		{
			for (int i = 0; i < columns; i++)
			{
				lineArrPtr[i] = arrPtr[lineId][i];
			}
		}
	};

	Matrix* createSquareMatrixFormKeyboard()
	{
		int size = utils::waitForInput<int>("matrinx size");
		cin.ignore();

		Matrix* matrixPtr = new Matrix(size, size);
		for (int i = 0; i < size; i++)
		{
			int arrSize = 0;
			int* arrPtr = utils::waitForIntArrayInput(&arrSize);
			if (arrSize == 0 || arrSize < size)
			{
				cout << "wrong format" << endl;
				return nullptr;
			}
			matrixPtr->setLine(arrPtr, i);
			delete[] arrPtr;
		}
		cout << endl;
		return matrixPtr;
	}

	Matrix* createMatrixFormKeyboard()
	{
		int lines = utils::waitForInput<int>("lines");
		int columns = utils::waitForInput<int>("columns");
		cin.ignore();

		Matrix* matrixPtr = new Matrix(lines, columns);
		for (int i = 0; i < lines; i++)
		{
			int arrSize = 0;
			int* arrPtr = utils::waitForIntArrayInput(&arrSize);
			if (arrSize == 0 || arrSize < columns)
			{
				cout << "wrong format" << endl;
				return nullptr;
			}
			matrixPtr->setLine(arrPtr, i);
			delete[] arrPtr;
		}
		cout << endl;
		return matrixPtr;
	}

	void nullAllAboveMainDiagonal()
	{
		try
		{
			Matrix* matrixPtr = createSquareMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;

			matrixPtr->forEachAboveMainDiagonal([matrixPtr](int elem, int lineId, int colId)
			{
				matrixPtr->setElement(0, lineId, colId);
				return true;
			});

			matrixPtr->printMatrix();
		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void checkIfSymmetric()
	{
		try
		{
			Matrix* matrixPtr = createSquareMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;

			bool result = matrixPtr->checkIfSymmetric();
			if (result)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
			delete matrixPtr;
		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void printColumnsContainMaxValue()
	{
		try
		{
			Matrix* matrixPtr = createMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;
			
			int max = matrixPtr->getMaxElement();
			int length = matrixPtr->getLines();
			matrixPtr->forEachColumn([length, max](int* colPtr, int colId)
			{
				string strToPrint = "";
				bool print = false;

				for (int i = 0; i < length; i++)
				{
					if (colPtr[i] == max)
						print = true;

					strToPrint += (to_string(colPtr[i]) + " ");
				}

				if (print)
					cout << strToPrint << endl;

				return true;
			});

			delete matrixPtr;
		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void printLinesWithMinSum()
	{
		try
		{
			Matrix* matrixPtr = createMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;

			int length = matrixPtr->getColumns();
			int minSum = INT_MAX;
			int minLineId = 0;

			matrixPtr->forEachLine([length, &minSum, &minLineId](int* linePtr, int lineId)
			{
				int sum = 0;
				for (int i = 0; i < length; i++)
				{
					sum += linePtr[i];
				}
				if (minSum > sum)
				{
					minSum = sum;
					minLineId = lineId;
				}
				return true;
			});

			int* minLine = new int[length];
			matrixPtr->writeLineTo(minLine, minLineId);
			utils::printArray(minLine, length);
			delete[] minLine;

			delete matrixPtr;
		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void printElement(Matrix* matrixPtr, string name, function<int(int*, int*)> lineIdColIdAction)
	{
		int lineId = 0;
		int colId = 0;
		int min = lineIdColIdAction(&lineId, &colId);
		cout << name << endl;
		cout << matrixPtr->elementToString(lineId, colId) << endl;
	}
	void printMinMax()
	{
		try
		{
			Matrix* matrixPtr = createMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;

			printElement(matrixPtr, "MIN", [matrixPtr](int* lineId, int* colId)
			{
				return matrixPtr->getMinElement(lineId, colId);
			});

			printElement(matrixPtr, "MAX", [matrixPtr](int* lineId, int* colId)
			{
				return matrixPtr->getMaxElement(lineId, colId);
			});

			delete matrixPtr;

		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void countDeterminedElement()
	{
		try
		{
			Matrix* matrixPtr = createMatrixFormKeyboard();
			int detElem = utils::waitForInput<int>("K element");

			if (matrixPtr == nullptr)
				return;

			int detElemCounter = 0;
			matrixPtr->forEach([detElem, &detElemCounter](int elem, int lineId, int colId)
			{
				if (elem == detElem)
					detElemCounter++;

				return true;
			});

			cout << detElemCounter << endl;
			delete matrixPtr;

		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}

	void countMatrixSum()
	{
		try
		{
			Matrix* matrixPtr = createMatrixFormKeyboard();
			if (matrixPtr == nullptr)
				return;

			int sum = matrixPtr->getElementSum();

			cout << sum << endl;
			delete matrixPtr;

		}
		catch (int errCode)
		{
			cout << "error code: " << errCode << endl;
		}
	}
}