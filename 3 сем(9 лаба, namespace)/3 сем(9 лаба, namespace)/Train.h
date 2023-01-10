#pragma once
#include "Locomotive.h"
#include "Wagons.h"
#include "Conductor.h"

namespace grover
{
	class Train : public Locomotive
	{
	private:
		int departureTime;
		Wagons wagons;
		Conductor conductor;
	public:
		Train();
		Train(string nameTrain, int powerEngine, int speedTrain, string nameDriver, int ageDriver, int departureTime, int countWagons,
			int numberWagon, string nameConductor);
		~Train();
		void print();
	};
}
