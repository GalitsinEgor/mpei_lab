
#include "stdafx.h"
#include  <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <iomanip>
#include "utils.h"

namespace hanoiTowers
{
	using namespace std;

	class Towers
	{
		list<int> firstTower = {};
		list<int> secondTower = {};
		list<int> thirdTower = {};
		int disks=0;

	public:

		Towers(int diskAmount)
		{
			disks = diskAmount;
			int value = 1;
			for (size_t i = 0; i < diskAmount; i++)
			{
				firstTower.push_back(value);
				value += 2;
			}
			drawAll();
		}

		void moveFromTo(int source, int dist)
		{
			list<int>* st = determineTower(source);
			list<int>* dt = determineTower(dist);

			int diskId = st->front();
			st->pop_front();
			dt->push_front(diskId);

			drawAll();
		}

		list<int>* determineTower(int id)
		{
			switch (id)
			{
			case 1:
				return &firstTower;
			case 2:
				return &secondTower;
			case 3:
				return &thirdTower;
			default:
				return nullptr;
			}
		}

		void drawTower(std::list<int>* lst, int towerNumber)
		{
			cout << "towerNumber: " << towerNumber << endl;

			list<int>::iterator it;
			for (it = lst->begin(); it != lst->end(); ++it)
			{
				int value = *it;
				int charNumber = value;
				string str = string(charNumber, '#');
				cout << setw(utils::CountSetw(charNumber, 8)) << str << endl;
			}
		}

		string getDiskString(std::list<int>* tower, int id)
		{
			if (tower->size() <= id)
				return "";

			std::list<int>::iterator it = tower->begin();
			std::advance(it, id);
			string str = string(*it, '#');
			return str;
		}

		void drawAll()
		{
			cout << "STEP" << endl;
			drawTower(&firstTower, 1);
			drawTower(&secondTower, 2);
			drawTower(&thirdTower, 3);
		}
		

	};


	void move(int height, int source, int dist, hanoiTowers::Towers* towers)
	{
		if (height == 1)
		{
			towers->moveFromTo(source, dist);
			//std::cout << "Move the disk " << height << " from " << source << " to " << dist << std::endl;
			return;
		}

		int tmpStorage = 6 - dist - source;
		int newHeight = height - 1;

		move(newHeight, source, tmpStorage, towers);
		towers->moveFromTo(source, dist);

		//std::cout << "Move the disk " << height << " from " << source << " to " << dist << std::endl;
		move(newHeight, tmpStorage, dist, towers);
	}
	
	void start()
	{
		Towers* t = new Towers(3);
		move(3, 1, 2, t);
	}

	

	
}

