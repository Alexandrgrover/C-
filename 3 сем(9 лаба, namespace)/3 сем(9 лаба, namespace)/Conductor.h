#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace grover
{
	class Conductor
	{
	private:
		int numberWagon;
		string nameConductor;
	public:
		Conductor();
		Conductor(int numberWagon, string nameConductor);
		~Conductor();
		void setNumberWagonAndName(int numberWagon, string nameConductor);
		void print();
	};
}

