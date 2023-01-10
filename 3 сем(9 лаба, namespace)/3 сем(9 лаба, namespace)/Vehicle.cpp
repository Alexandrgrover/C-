#include "Vehicle.h"

using namespace grover;

Vehicle::Vehicle()
{
	this->name = "-";
	this->engine.setPower(0);
	cout << "Constr Vehicle" << endl;
}

Vehicle::Vehicle(string name, int powerEngine)
{
	cout << "Constr Vehicle" << endl;
	this->name = name;
	this->engine.setPower(powerEngine);
}

Vehicle::~Vehicle()
{
	cout << "Destructor Vehicle" << endl;
}

void Vehicle::print()
{
	cout << "Name vehicle is " << name << endl; 
	engine.print();
}

Vehicle::Engine::Engine()
{
	this->power = 0;
	cout << "Constr Engine" << endl;
}

Vehicle::Engine::Engine(int power)
{
	if (power < 0)
	{
		if (power < 0)
		{
			throw exception("Error, value < 0");
		}
	}

	this->power = power;
	cout << "Constr Engine" << endl;
}

Vehicle::Engine::~Engine()
{
	cout << "Destructor Engine" << endl;
}

void Vehicle::Engine::setPower(int power)
{
	if (power < 0)
	{
		throw exception("Error, value < 0");
	}

	this->power = power;
}

void Vehicle::Engine::print()
{
	cout << "Power = " << power << " wt" << endl;
}
