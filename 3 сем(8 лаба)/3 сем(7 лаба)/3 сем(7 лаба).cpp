#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

template<typename T>
class Ring
{
private:
	vector<T> ring;
public:
	Ring()
	{

	}

	void add(T data)
	{
		for (auto iter = ring.begin(); iter < ring.end(); iter++)
		{
			if (*iter == data)
			{
				throw exception("There is already such an element in the ring");
			}
		}

		ring.push_back(data);
	}

	void delElelem(T data)
	{
		if (ring.empty())
		{
			throw exception("List is empty!");
		}

		bool there = false;

		for (auto iter = ring.begin(); iter != ring.end(); iter++)
		{
			if (*iter == data)
			{
				there = true;
				ring.erase(iter);
				cout << "Element was delete" << endl;
				return;
			}
		}

		if (!there)
		{
			cout << "This element isn't exist in this ring" << endl;
		}
	}

	void find(T data)
	{
		if (ring.empty())
		{
			throw exception("List is empty!");
		}

		bool exist = false;

		for (auto iter = ring.begin(); iter != ring.end(); iter++)
		{
			if (*iter == data)
			{
				cout << "This element exist in ring" << endl;
				exist = true;
			}
		}

		if (!exist)
		{
			cout << "This element isn't exist in ring" << endl;
		}
	}

	void print()
	{
		if (ring.empty())
		{
			throw exception("List is empty!");
		}

		for (auto iter = ring.begin(); iter != ring.end(); iter++)
		{
			cout << *iter << " ";
		}

		cout << endl;
	}
};

template<typename T>
Ring<T> func(Ring<T> ring)
{
	while (1)
	{
		try
		{
			cout << "1|Add\n2|Delete\n3|Find\n4|Print\n5|Exit" << endl;

			char get = _getch();

			switch (get)
			{
			case '1':
				system("cls");
				cout << "Enter data: ";
				T data;
				cin >> data;
				ring.add(data);
				system("cls");
				break;
			case '2':
				system("cls");
				ring.print();
				cout << "Enter data: ";
				cin >> data;
				ring.delElelem(data);
				cout << "\nPress any key...";
				_getch();
				system("cls");
				break;
			case '3':
				system("cls");
				cout << "Enter data: ";
				cin >> data;
				ring.find(data);
				cout << "\nPress any key...";
				_getch();
				system("cls");
				break;
			case '4':
				system("cls");
				ring.print();
				cout << "\nPress any key...";
				_getch();
				system("cls");
				break;
			case '5':
				system("cls");
				return ring;
			default:
				break;
			}
		}
		catch (exception error)
		{
			cout << error.what() << endl;
			Sleep(1500);
			system("cls");
		}
	}
}

int main()
{
	Ring<int> ringInt;
	Ring<double> ringDouble;
	Ring<char> ringChar;

	cout.unsetf(ios::dec);

	cout.setf(ios::hex | ios::fixed | ios::showpos | ios::showbase);
	while (1)
	{
		cout << "Choose:\n1|Int\n2|Double\n3|Char\n4|Exit" << endl;
		char get = _getch();

		switch (get)
		{
		case '1':
			system("cls");
			ringInt = func(ringInt);
			system("cls");
			break;
		case '2':
			system("cls");
			ringDouble = func(ringDouble);
			system("cls");
			break;
		case '3':
			system("cls");
			ringChar = func(ringChar);
			system("cls");
			break;
		case '4':
			system("cls");
			return 0;
		default:
			cout << "Error value!" << endl;
			break;
		}
	}
}