#include <iostream>
#include <windows.h>

using namespace std;

class Tool
{
protected:
	string name;

public:
	Tool()
	{
	
	}

	Tool(string name)
	{
		this->name = name;

		cout << "constr Tool" << endl;
	}

	virtual ~Tool()
	{
		cout << "distr Tool" << endl;
	}

	virtual double cost() = 0;

	virtual void display() = 0;
};

class Electric : public virtual Tool
{
protected:
	int minCost;
	int maxCost;

public:
	Electric()
	{
		minCost = 0;
		maxCost = 0;
	}

	Electric(string name, int minCost, int maxCost) : Tool(name)
	{
		this->minCost = minCost;
		this->maxCost = maxCost;

		cout << "constr Electric" << endl;
	}

	~Electric() override
	{
		cout << "distr Electric" << endl;
	}

	double cost() override
	{
		return minCost + maxCost;
	}

	void display() override
	{
		cout << "Name is " << name << ", it electric and it mincost " << minCost << "$ and maxcost " << maxCost << "$" << endl;
	}
};

class DisElectric : public virtual Tool
{
protected:
	int minCost;
	int maxCost;

public:
	DisElectric()
	{
		minCost = 0;
		maxCost = 0;
	}

	DisElectric(string name, int minCost, int maxCost) : Tool(name)
	{
		this->minCost = minCost;
		this->maxCost = maxCost;

		cout << "constr DisElectric" << endl;
	}

	~DisElectric() override
	{
		cout << "distr DisElectric" << endl;
	}

	double cost() override
	{
		return minCost + maxCost;
	}

	void display() override
	{
		cout << "Name is " << name << ", it diselectric and it mincost " << minCost << "$ and maxcost " << maxCost << "$" << endl;
	}
};

class Drell : public Electric
{
protected:
	int costSverlo;
	int costBatery;
	int costOtherSpareParts;

public:
	Drell()
	{
		costSverlo = 0;
		costBatery = 0;
		costOtherSpareParts = 0;
	}

	Drell(string name, int minCost, int maxCost, int costSverlo, int costBatery, int costOtherSpareParts) : Tool(name), Electric(name, minCost, maxCost)
	{
		this->costSverlo = costSverlo;
		this->costBatery = costBatery;
		this->costOtherSpareParts = costOtherSpareParts;

		cout << "constr Drell" << endl;
	}

	~Drell() override
	{
		cout << "distr Drell" << endl;
	}

	double cost() override
	{
		return costSverlo + costBatery + costOtherSpareParts;
	}

	void display() override
	{
		cout << "Name is " << name << ", it electric and it mincost " << minCost << "$ and maxcost " << maxCost << "$, it cost of sverlo is " <<
			costSverlo << "$, cost of batery is " << costBatery << "$ and cost of other spare parts is " << costOtherSpareParts << "$" << endl;

	}
};

int main()
{
	Tool* electric = new Electric("Shurupovert", 100, 2000);
	Tool* disElectric = new DisElectric("Molotok", 10, 500);
	Tool* drell = new Drell("Drell", 200, 3000, 100, 300, 500);

	Tool* tools[] = { electric, disElectric, drell };

	for (int i = 0; i < 3; i++)
	{
		tools[i]->display();
		cout << "And it cost: " << tools[i]->cost() << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete tools[i];
	}
}