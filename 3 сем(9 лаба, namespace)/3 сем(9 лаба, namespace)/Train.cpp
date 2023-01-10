#include "Train.h"

grover::Train::Train()
{
	cout << "Constr Train" << endl;
	this->departureTime = 0;
	this->wagons.setCount(0);
	this->conductor.setNumberWagonAndName(0, "-");
}

grover::Train::Train(string nameTrain, int powerEngine, int speedTrain, string nameDriver, int ageDriver, int departureTime, int countWagons, 
	int numberWagon, string nameConductor) : Locomotive(nameTrain, powerEngine, speedTrain, nameDriver, ageDriver)
{
	if (departureTime < 0)
	{
		throw exception("Error, value < 0");
	}

	this->departureTime = departureTime;
	this->wagons.setCount(countWagons);
	this->conductor.setNumberWagonAndName(numberWagon, nameConductor);

	cout << "Constr Train" << endl;
}

grover::Train::~Train()
{
	cout << "Destructor Train" << endl;
}

void grover::Train::print()
{
	Locomotive::print();
	cout << "Departure time " << departureTime << ".00 h" << endl;
	wagons.print();
	conductor.print();
}
