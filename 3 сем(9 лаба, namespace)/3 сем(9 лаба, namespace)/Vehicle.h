#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace grover
{
	class Vehicle
	{
	public:
		Vehicle();
		Vehicle(string name, int powerEngine);
		~Vehicle();
		void print();

		class Engine
		{
		private:
			int power;
		public:
			Engine();
			Engine(int power);
			~Engine();
			void setPower(int power);
			void print();
		};
	protected:
		string name;
		Engine engine;
	};
}
