#include "Conductor.h"

using namespace grover;

Conductor::Conductor()
{
	this->numberWagon = 0;
	cout << "Constr Conductor" << endl;
}

Conductor::Conductor(int numberWagon, string nameConductor)
{
	if (numberWagon < 0)
	{
		throw exception("Error, value < 0");
	}

	this->nameConductor = nameConductor;
	this->numberWagon = numberWagon;
	cout << "Constr Conductor" << endl;
}

Conductor::~Conductor()
{
	cout << "Destructor Conductor" << endl;
}

void Conductor::setNumberWagonAndName(int numberWagon, string nameConductor)
{
	if (numberWagon < 0)
	{
		throw exception("Error, value < 0");
	}

	this->nameConductor = nameConductor;
	this->numberWagon = numberWagon;
}

void Conductor::print()
{
	cout << "Conductor " << nameConductor << " working in " << numberWagon << " wagon" << endl;
}
