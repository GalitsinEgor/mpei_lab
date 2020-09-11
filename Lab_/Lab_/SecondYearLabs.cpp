#include "stdafx.h"
#include <iostream>
#include "SecondYearLabs.h"
#include "utils.h"

SecondYearLabs::DataRead_0 SecondYearLabs::ReadData_0(){

	float z = utils::waitForInput<float>("january average salary");
	float s = utils::waitForInput<float>("basket");

	float p = utils::waitForInput<float>("salary percent");
	float q = utils::waitForInput<float>("basket percent");

	DataRead_0 res = DataRead_0
	{
		z,s,p,q
	};

	return res;
}

void SecondYearLabs::Task_1_3_1_6() {
	DataRead_0 data = ReadData_0();

	for (size_t i = 0; i < 12; i++)
	{
		if (i > 0)
		{
			data.z = data.z + ((data.z / 100) * data.p);
			data.s = data.s + ((data.s / 100) * data.q);
		}
		
		std::cout << "month" << i + 1 << "delta: " << data.z - data.s << std::endl;
	}
}

void SecondYearLabs::Task_1_3_2_6() {
	DataRead_0 data = ReadData_0();

	for (size_t i = 0; i < 12; i++)
	{
		if (i > 0) {
			data.z = data.z + ((data.z / 100) * data.p);

			if (i > 1) {
				data.s = data.s + ((data.s / 100) * data.q);
			}
			else {
				data.q = data.q / 2;
				data.s = data.s + ((data.s / 100) * data.q);
			}
		}
		
		std::cout << "month" << i + 1 << "delta: " << data.z - data.s << std::endl;

		
	}
}

void SecondYearLabs::Task_1_3_3_6() {
	float s = utils::waitForInput<float>("basket");
	float p = utils::waitForInput<float>("basket percent");

	float avarage = s;
	int div = 1;
	for (size_t i = 0; i < 11; i++)
	{
		float tmpQ = p + (i / 10);
		s = s + ((s / 100) * tmpQ);

		avarage += s;
		div++;
	}

	std::cout << "month basket:" << avarage / div << std::endl;
}

