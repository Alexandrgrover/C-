#include <iostream>
#include <array>

using namespace std;

template<typename T>
void reverseTwinElem(T* arr, int size, T twinElem, T reverseElem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == twinElem)
		{
			arr[i] = reverseElem;
		}
	}
}

template<>
void reverseTwinElem(char* arr, int size, char twinElem, char reverseElem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == twinElem)
		{
			arr[i] = reverseElem;
		}
	}
}

template<typename T>
void print(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "char:" << endl;
	char arrChar[] = { 'h', 'e', 'l', 'l', 'o' };
	print(arrChar, size(arrChar));
	reverseTwinElem(arrChar, size(arrChar), 'l', '/');
	print(arrChar, size(arrChar));

	cout << "\n";
	cout << "int:" << endl;
	int arrInt[] = { 1, 2, 4, 2, 2, 1, 9 };
	print(arrInt, size(arrInt));
	reverseTwinElem(arrInt, size(arrInt), 2, 0);
	print(arrInt, size(arrInt));

	cout << "\n";
	cout << "double" << endl;
	double arrDouble[] = { 1.2, 3.9, 2.3, 2.6, 3.9, 3.9 };
	print(arrDouble, size(arrDouble));
	reverseTwinElem(arrDouble, size(arrDouble), 3.9, 1.1);
	print(arrDouble, size(arrDouble));
}