#include <iostream>
#include <vector>
#include <time.h>

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
		for (int i = 0; i < ring.size(); i++)
		{
			if (ring.at(i) == data)
			{
				throw exception("There is already such an element in the ring");
			}
		}

		ring.push_back(data);
	}

	void delElelem(T data)
	{
		bool there = false;

		for (auto iter = ring.begin(); iter != ring.end(); iter++)
		{
			if (*iter == data)
			{
				there = true;
				ring.erase(iter);
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
		for (auto iter = ring.begin(); iter != ring.end(); iter++)
		{
			cout << *iter << " ";
		}

		cout << "\n";
	}
};

int main()
{
	Ring<int> ringInt;
	Ring<double> ringDoub;
	Ring<char> ringChar;
	
	cout << "Enter count elements of ring int: ";
	int countInt;
	cin >> countInt;

	cout << "Enter count elements of ring double: ";
	int countDoub;
	cin >> countDoub;

	cout << "Enter count elements of ring char: ";
	int countChar;
	cin >> countChar;
	system("cls");

	try
	{
		cout << "Enter " << countInt << " elements for ring int: ";
		for (int i = 0; i < countInt; i++)
		{
			int tmp;
			cin >> tmp;
			ringInt.add(tmp);
		}

		cout << "Enter " << countDoub << " elements for ring double: ";
		for (int i = 0; i < countDoub; i++)
		{
			double tmp;
			cin >> tmp;
			ringDoub.add(tmp);
		}

		cout << "Enter " << countChar << " elements for ring char: ";
		for (int i = 0; i < countChar; i++)
		{
			char tmp;
			cin >> tmp;
			ringChar.add(tmp);
		}
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}

	system("cls");
	cout << "Ring of int: ";
	ringInt.print();

	cout << "Enter int element, which you will want to find: ";
	int findInt;
	cin >> findInt;
	ringInt.find(findInt);

	cout << "Enter int element, which you will want to delete: ";
	int delInt;
	cin >> delInt;
	ringInt.delElelem(delInt);

	cout << "Enter int element, which you will want to find: ";
	cin >> findInt;
	ringInt.find(findInt);

	cout << "Ring of int: ";
	ringInt.print();

	for (int i = 0; i < 220000000; i++)
	{

	}
	system("cls");

	cout << "Ring of double: ";
	ringDoub.print();

	cout << "Enter double element, which you will want to find: ";
	double findDoub;
	cin >> findDoub;
	ringDoub.find(findDoub);

	cout << "Enter double element, which you will want to delete: ";
	double delDoub;
	cin >> delDoub;
	ringDoub.delElelem(delDoub);

	cout << "Enter double element, which you will want to find: ";
	cin >> findDoub;
	ringDoub.find(findDoub);

	cout << "Ring of double: ";
	ringDoub.print();

	for (int i = 0; i < 220000000; i++)
	{

	}
	system("cls");

	cout << "Ring of char: ";
	ringChar.print();

	cout << "Enter char element, which you will want to find: ";
	char findChar;
	cin >> findChar;
	ringChar.find(findChar);

	cout << "Enter char element, which you will want to delete: ";
	char delChar;
	cin >> delChar;
	ringChar.delElelem(delChar);

	cout << "Enter char element, which you will want to find: ";
	cin >> findChar;
	ringChar.find(findChar);

	cout << "Ring of char: ";
	ringChar.print();
}