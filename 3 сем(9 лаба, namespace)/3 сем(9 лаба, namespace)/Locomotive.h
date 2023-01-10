#pragma 
#include "Vehicle.h"

namespace grover
{
	class Locomotive : public Vehicle
	{
	public:
		Locomotive();
		Locomotive(string nameVehicle, int power, int speed, string nameDriver, int age);
		~Locomotive();
		void print();

		class Driver
		{
		public:
			Driver();
			Driver(string name, int age);
			~Driver();
			void setNameAndAge(string name, int age);
			void print();
		private:
			string name;
			int age;
		};
	protected:
		int speed;
		Driver driver;
	};
}
