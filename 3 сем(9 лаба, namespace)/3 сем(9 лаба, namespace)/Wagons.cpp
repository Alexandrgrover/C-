#include "Wagons.h"

using namespace grover;

Wagons::Wagons()
{
	this->countWagons = 0;
	cout << "Constr Wagons" << endl;
}

Wagons::Wagons(int countWagons)
{
	if (countWagons < 0)
	{
		throw exception("Error, value < 0");
	}

	this->countWagons = countWagons;
	cout << "Constr Wagons" << endl;
}

Wagons::~Wagons()
{
	cout << "Destructor Wagons" << endl;
}

void Wagons::setCount(int countWagons)
{
	if (countWagons < 0)
	{
		throw exception("Error, value < 0");
	}

	this->countWagons = countWagons;
}

void Wagons::print()
{
	cout << "Wagons count " << countWagons << endl;
}
