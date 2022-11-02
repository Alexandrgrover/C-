#include <iostream>
#include <string>

using namespace std;

int ID = 0;

class Prodavec;

class Tovar
{
	friend Prodavec;

private:

	int id;

	string name;

	int cost;

public:

	Tovar()
	{

	}

	~Tovar()
	{
		cout << "Destructor complete work" << endl;
	}

	void set(string Name)
	{
		this->name = Name;

		id = ID;

		ID++;

		cost = 0;

	}

	void getData()
	{
		cout << "Tovar id is " << id << " name is " << name << " and its cost is " << cost << "$" << std::endl;
	}
};

class Prodavec
{
public:
	void changeCost(Tovar* arr)
	{
		while (1)
		{
			cout << "Enter cost of tovar with name " << (*arr).name << ": ";

			int tmp;

			cin >> tmp;

			if (tmp < 0)
			{
				cout << "You write is wrong cost and its < 0" << std::endl;
			}
			else
			{
				(*arr).cost = tmp;
				break;
			}
		}
	}
};


int main()
{
	string name;

	Tovar arr[3], Name;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter name: ";

		cin >> name;

		Name.set(name);

		arr[i] = Name;
	}

	for (int i = 0; i < 3; i++)
	{
		arr[i].getData();
	}

	Prodavec prodavec;
	
	for (int i = 0; i < 3; i++)
	{
		prodavec.changeCost(&arr[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		arr[i].getData();
	}
}