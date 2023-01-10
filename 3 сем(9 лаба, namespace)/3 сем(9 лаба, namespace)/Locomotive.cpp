#include "Locomotive.h"

using namespace grover;

Locomotive::Locomotive()
{
	cout << "Constr Locomotive" << endl;

	this->name = "-";
	this->engine.setPower(0);
	this->speed = 0;
	this->driver.setNameAndAge("-", 0);
}

Locomotive::Locomotive(string nameVehicle, int power, int speed, string nameDriver, int age) : Vehicle(nameVehicle, power)
{
	this->name = nameVehicle;
	this->engine.setPower(power);
	if (speed < 0)
	{
		throw exception("Error, value < 0");
	}
	this->speed = speed;
	this->driver.setNameAndAge(nameDriver, age);

	cout << "Constr Locomotive" << endl;
}

Locomotive::~Locomotive()
{
	cout << "Destructor Locomotive" << endl;
}

void Locomotive::print()
{
	Vehicle::print(); 
	cout << "Speed is " << speed << "km/h\n"; 
	driver.print();
}

Locomotive::Driver::Driver()
{
	this->name = "-";
	this->age = 0;

	cout << "Constr Driver" << endl;
}

Locomotive::Driver::Driver(string name, int age)
{
	this->name = name;
	this->age = age;

	cout << "Constr Driver" << endl;
}

Locomotive::Driver::~Driver()
{
	cout << "Destructor Driver" << endl;
}

void Locomotive::Driver::setNameAndAge(string name, int age)
{
	this->name = name;
	if (age < 0)
	{
		throw exception("Error, value < 0");
	}

	this->age = age;
}

void Locomotive::Driver::print()
{
	cout << "Name driver is " << this->name << ", his age " << this->age << " years" << endl;
}
