#include "Train.h"
#include <conio.h>
#include <Windows.h>

using namespace std;

void withNamespace();

void withoutNamespace();

int main()
{
	while (1)
	{
		cout << "Choose:\n1|With namespace\n2|Without namespace\n3|Exit" << endl;

		char get = _getch();

		switch (get)
		{
		case '1':
			system("cls");
			withNamespace();
			Sleep(3000);
			system("cls");
			break;
		case '2':
			system("cls");
			withoutNamespace();
			Sleep(3000);
			system("cls");
			break;
		case '3':
			system("cls");
		return 0;
		default:
			cout << "Error choose" << endl;
			system("cls");
			break;
		}
	}
}

void withoutNamespace()
{
	try
	{
		string nameTrain, nameDriver, nameConductor;
		int powerEngine, speed, ageDriver, departureTime, countWagons, numberWagon;
		cout << "Enter name train: ";
		cin >> nameTrain;
		cout << "Enter power engine(wt): ";
		cin >> powerEngine;
		cout << "Enter speed train(km/h): ";
		cin >> speed;
		cout << "Enter name driver: ";
		cin >> nameDriver;
		cout << "Enter age driver: ";
		cin >> ageDriver;
		cout << "Enter departure time train(h): ";
		cin >> departureTime;
		cout << "Enter count wagons: ";
		cin >> countWagons;
		cout << "Enter name conductor: ";
		cin >> nameConductor;
		cout << "Enter number wagon, which work conductor " << nameConductor << ": ";
		cin >> numberWagon;

		grover::Train train(nameTrain, powerEngine, speed, nameDriver, ageDriver, departureTime, countWagons, numberWagon, nameConductor);

		Sleep(3000);
		system("cls");
		train.print();
		cout << "\nPress any key...\n";
		_getch();
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}

void withNamespace()
{
	using namespace grover;
	try
	{
		string nameTrain, nameDriver, nameConductor;
		int powerEngine, speed, ageDriver, departureTime, countWagons, numberWagon;
		cout << "Enter name train: ";
		cin >> nameTrain;
		cout << "Enter power engine(wt): ";
		cin >> powerEngine;
		cout << "Enter speed train(km/h): ";
		cin >> speed;
		cout << "Enter name driver: ";
		cin >> nameDriver;
		cout << "Enter age driver: ";
		cin >> ageDriver;
		cout << "Enter departure time train(h): ";
		cin >> departureTime;
		cout << "Enter count wagons: ";
		cin >> countWagons;
		cout << "Enter name conductor: ";
		cin >> nameConductor;
		cout << "Enter number wagon, which work conductor " << nameConductor << ": ";
		cin >> numberWagon;

		Train train(nameTrain, powerEngine, speed, nameDriver, ageDriver, departureTime, countWagons, numberWagon, nameConductor);
		
		Sleep(3000);
		system("cls");
		train.print();
		cout << "\nPress any key...\n";
		_getch();
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}