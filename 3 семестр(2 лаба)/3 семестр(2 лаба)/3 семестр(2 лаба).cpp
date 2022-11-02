#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Str
{
private:
	string str;
	string mass[5];
	double size_str;
	
public:
	Str()
	{
		str = "empty";

		for (int i = 0; i < 5; i++)
		{
			mass[i] = "empty";
		}

		size_str = 0;
	}

	Str(string tmp)
	{
		str = tmp;
		size_str = str.length();
	}

	~Str()
	{

	}

	Str operator + (Str p2)
	{
		return Str(this->str + p2.str);
	}

	bool operator == (Str p2)
	{
		return (this->str == p2.str);
	}

	bool operator != (Str p2)
	{
		return (this->str != p2.str);
	}

	Str operator = (Str p2)
	{
		return Str(this->str = p2.str);
	}

	Str& operator ++()
	{
		int counter = (*this).str.length();
		(*this).str.resize((*this).str.size() + 1, (*this).str[counter - 1]);
		(*this).size_str++;

		return *this;
	}

	Str operator ++(int)
	{
		Str tmp = *this;

		++* this;

		return tmp;
	}

	string& operator [] (int index)
	{
		return mass[index];
	}

	operator double() const
	{
		return size_str;
	}

	void getDataMass()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << i << " is " << mass[i] << endl;
		}
	}

	friend Str operator +(Str data, string value)
	{
		return Str(data.str + value);
	}

	friend Str operator +(string value, Str data)
	{
		return Str(value + data.str);
	}

	friend bool operator >(Str data, string value)
	{
		return(data.str > value);
	}

	friend bool operator >(string value, Str data)
	{
		return(value > data.str);
	}

	friend Str& operator --(Str&data)
	{
		if (data.size_str > 0)
		{
			data.str.resize(data.str.size() - 1);
			data.size_str--;
		}
		else
		{
			cout << "Size of string is 0";
		}

		return data;
	}

	friend Str operator --(Str&data, int)
	{
		Str tmp = data;
		
		--data;

		return tmp;
	}

	friend ostream& operator << (ostream& out, Str str)
	{
		out << str.str;

		return out;
	}
};

class Str2
{
private:
	string str;

public:

	Str2(string tmp)
	{
		str = tmp;
	}

	explicit operator Str() const
	{
		return Str(str);
	}
};

int main()
{
	Str c1("Pri"), c2("vet");

	cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;

	Str c3 = c1 + c2;
	cout << "Resalt c1 + c2 : " << c3 << endl;

	bool b = c1 == c2;

	cout << "Resalt sravneniya c1 == c2: ";
	if (b == 1)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

	c1 = c2;
	cout << "Rezalt prisvoeniya c1 = c2: c1 = c2 = " << c1 << endl;

	c2++;
	cout << "Resalt c2++: " << c2 << endl;

	Str mass;

	mass[1] = "Hello";
	cout << "Resalt indexing mass[1] = Hello: " << endl;
	mass.getDataMass();

	cout << "Press enter to next operations...";
	getchar();
	system("cls");

	Str frienD("hi"), friendRez;
	cout << "frienD = " << frienD << "\n" << "friendRez = " << friendRez << endl;

	friendRez = frienD + "5";
	cout << "Rezalt friendRez = frienD + 5: friendRez = " << friendRez << endl;

	friendRez = "5" + frienD;
	cout << "Rezalt friendRez = 5 + frienD: friendRez = " << friendRez << endl;

	bool sravn = "6ix" > frienD;
	if (sravn == 1)
	{
		cout << "6ix > frienD"<<endl;
	}
	else
	{
		cout << "6ix !> frienD"<<endl;
	}

	sravn = frienD > "6ix";
	if (sravn == 1)
	{
		cout << "frienD > 6ix"<<endl;
	}
	else
	{
		cout << "frienD !> 6ix"<<endl;
	}

	Str minus_minus("hello");

	cout << "minus_minus = " << minus_minus << endl;

	minus_minus--;
	cout << "minus_minus--: minus_minus = " << minus_minus << endl;

	double size = minus_minus;

	cout << "double size = minus_minus, size = " << size << endl;

	Str2 str2("Gang");

	minus_minus = (Str)str2;

	cout << "minus_minus = str2 : minus_minus = " << minus_minus << endl;
}