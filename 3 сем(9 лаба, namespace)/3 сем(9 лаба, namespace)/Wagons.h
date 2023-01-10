#pragma once
#include <iostream>
using namespace std;

namespace grover
{
	class Wagons
	{
	private:
		int countWagons;
	public:
		Wagons();
		Wagons(int countWagons);
		~Wagons();
		void setCount(int countWagons);
		void print();
	};
}