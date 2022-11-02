#include <iostream>

using namespace std;

class Tool
{
protected:
	string name;

public:
	Tool(string name)
	{
		this->name = name;

		cout << "constr Tool" << endl;
	}

	~Tool()
	{
		cout << "distr Tool" << endl;
	}

	void display()
	{
		cout << "name: " << name << endl;
	}
};

class Electric : public virtual Tool
{
protected:
	int power;

public:
	Electric(string name, int power) : Tool(name)
	{
		this->power = power;

		cout << "constr Electric" << endl;
	}

	~Electric()
	{
		cout << "distr Electric" << endl;
	}

	void display()
	{
		cout << "Name is " << name << ", it electric and it power is " << power << " watt" << endl;
	}
};

class DisElectric : public virtual Tool
{
protected:
	int weight;

public:
	DisElectric(string name, int weigh) : Tool(name)
	{
		this->weight = weigh;

		cout << "constr DisElectric" << endl;
	}

	~DisElectric()
	{
		cout << "distr DisElectric" << endl;
	}

	void display()
	{
		cout << "Name is " << name << ", it diselectric and it weight is " << weight << "kg" << endl;
	}
};

class Drell : public Electric
{
protected:
	int dSverlo;
public:
	Drell(string name, int power, int dSverlo) : Tool(name), Electric(name, power)
	{
		this->dSverlo = dSverlo;

		cout << "constr Drell" << endl;
	}

	~Drell()
	{
		cout << "distr Drell" << endl;
	}

	void display()
	{
		cout << "Drell name is " << name << ", it electric and it power is " << power << " watt and diametr sverla is " 
			<< dSverlo << " mm" << endl;
	}
};

class Molotok : public DisElectric
{
protected:
	int sqareOfPunchSide;

public:
	Molotok(string name, int weight, int sqareOfPunchSide) : Tool(name), DisElectric(name, weight)
	{
		this->sqareOfPunchSide = sqareOfPunchSide;

		cout << "constr Molotok" << endl;
	}

	~Molotok()
	{
		cout << "distr Molotok" << endl;
	}

	void display()
	{
		cout << " Molotok name is " << name << ", it diselectric and it weight is "
			<< weight << "kg and it sqare of punch side is " << sqareOfPunchSide << " sm^2" << endl;
	}
};

class Utrambovshik : private Drell, private Molotok
{
private:
	int countOfPunchs;

public:
	Utrambovshik(string name, int weight, int power, int sqareOfPunchSide, int countOfPunchs) : Tool(name), Drell(name, power, 0),
		Molotok(name, weight, sqareOfPunchSide)
	{
		this->countOfPunchs = countOfPunchs;

		cout << "constr Utrmbovshik" << endl;
	}

	~Utrambovshik()
	{
		cout << "distr Utrambovshik" << endl;
	}

	/*void display()
	{
		cout << " Utrambovshik name is " << name << ", it weight is "
			<< weight << "kg, it sqare of punch side is " << sqareOfPunchSide << " sm^2 \nand it count of punchs in minute is "
			<< countOfPunchs << " count/min" <<  endl;
	}*/
};

int main()
{
	Utrambovshik molotok("bosh", 100, 1000, 300, 100);
	molotok.display();
}