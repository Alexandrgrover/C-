#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;

string fileNameTT = "TfileTMode.txt";
string fileNameTB = "TfileBMode.txt";
string fileNameBB = "BfileBMode.bin";

class Dish
{
private:
	int id;
	double cost;
	int calorie;
public:
	Dish()
	{
		id = 0;
		cost = 0.0;
		calorie = 0;
	}

	Dish(int id, double cost, int calorie)
	{
		this->id = id;
		this->cost = cost;
		this->calorie = calorie;
	}

	~Dish()
	{

	}

	void writeInTFileInTMode()
	{
		if (findTxtTxt(this->id))
		{
			cout << "Element with id " << this->id << " already exists in file 'fileNameTT'" << endl;
			return;
		}
		ofstream ofs;

		ofs.open(fileNameTT, ofstream::app);

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'fileNameTT'");
		}

		ofs << *this;

		ofs.close();
	}

	void writeInTFileInBmode()
	{
		if (findTxtBin(this->id))
		{
			cout << "Element with id " << this->id << " already exists in file 'fileNameTB'" << endl;
			return;
		}

		ofstream ofs;

		ofs.open(fileNameTB, ofstream::app);

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'fileNameTB'");
		}

		ofs.write((char*)this, sizeof(Dish));

		ofs.close();
	}

	void writeInBFileInBmode()
	{
		if (findBinBin(this->id))
		{
			cout << "Element with id " << this->id << " already exists in file 'fileNameBB'" << endl;
			return;
		}

		ofstream ofs;

		ofs.open(fileNameBB, ios::app);

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'fileNameTB'");
		}

		ofs.write(reinterpret_cast<char*>(this), sizeof(Dish));

		ofs.close();

	}

	static void readTFileInTMode()
	{
		ifstream ifs;

		ifs.open(fileNameTT);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameTT'");
		}

		string tmp;

		while (getline(ifs, tmp))
		{
			cout << tmp << endl;
		}

		ifs.close();
	}

	static void readTFileInBMode()
	{
		ifstream ifs;

		ifs.open(fileNameTB);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameTB'");
		}

		Dish tmp;

		while (ifs.read((char*)&tmp, sizeof(Dish)))
		{
			cout << tmp;
		}

		ifs.close();
	}

	static void readBFileInBMode()
	{
		ifstream ifs;

		ifs.open(fileNameBB);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameBB'");
		}

		Dish tmp;

		while (ifs.read(reinterpret_cast<char*>(&tmp), sizeof(Dish)))
		{
			cout << tmp;
		}

		ifs.close();
	}

	static void findAllFiles(int idi)
	{
		if (findTxtTxt(idi))
		{
			cout << "element was found in file 'fileNameTT'" << endl;
		}
		if (findTxtBin(idi))
		{
			cout << "element was found in file 'fileNameTB'" << endl;
		}
		if (findBinBin(idi))
		{
			cout << "element was found in file 'fileNameBB'" << endl;
		}
	}

	static bool findTxtTxt(int idi) {
		ifstream ifs;
		ifs.open(fileNameTT);
		string tmp;
		string zap;

		int count = 0;
		bool twin = false;

		while (getline(ifs, tmp))
		{
			for (int i = 0; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ')
				{
					count++;
					int iZap = i;

					if (count == 2)
					{
						iZap = iZap + 1;
						while (tmp[iZap] != ',')
						{
							zap.push_back(tmp[iZap]);
							iZap = iZap + 1;
						}
						int temp = stoi(zap);
						if (temp == idi)
						{
							cout << tmp << endl;
							twin = true;
						}
						break;
					}
				}
			}

			count = 0;
			zap = "";

			if (twin == true)
			{
				ifs.close();
				return 1;
			}
		}

		ifs.close();
		cout << "element with id " << idi << " not found in file 'fileNameTT'" << endl;
		return 0;
	}

	static bool findTxtBin(int idi)
	{
		ifstream ifs;
		ifs.open(fileNameTB);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameTB'");
		}

		Dish tmp;

		while (ifs.read((char*)&tmp, sizeof(Dish)))
		{
			if (idi == tmp.id)
			{
				cout << "\n" << tmp;
				ifs.close();
				return 1;
			}
		}

		ifs.close();
		cout << "element with id " << idi << " not found in file 'fileNameTB'" << endl;
		return 0;
	}

	static bool findBinBin(int idi)
	{
		ifstream ifs;
		ifs.open(fileNameBB);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameBB'");
		}

		Dish tmp;

		while (ifs.read(reinterpret_cast<char*>(&tmp), sizeof(Dish)))
		{
			if (idi == tmp.id)
			{
				cout << "\n" << tmp;
				ifs.close();
				return 1;
			}
		}

		ifs.close();
		cout << "element with id " << idi << " not found in file 'fileNameBB'" << endl;
		return 0;
	}

	static void deleteAllFiles(int idi)
	{
		deleteFileTxtTxt(idi);
		deleteFileTxtBin(idi);
		deleteFileBinBin(idi);
	}

	static void deleteFileTxtTxt(int idi)
	{
		ifstream ifs;
		ofstream ofs;

		ifs.open(fileNameTT);
		ofs.open("tmpTT.txt", ofstream::app);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameTT'");
		}

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'tmpTT'");
		}

		bool del = false;
		string tmp, zap;
		int count = 0;

		while (getline(ifs, tmp))
		{
			for (int i = 0; i < tmp.size(); i++)
			{
				if (tmp[i] == ' ')
				{
					count++;
					int iZap = i;

					if (count == 2)
					{
						iZap = iZap + 1;
						while (tmp[iZap] != ',')
						{
							zap.push_back(tmp[iZap]);
							iZap = iZap + 1;
						}
						int temp = stoi(zap);
						if (temp != idi)
						{
							ofs << tmp << "\n";
						}
						if (temp == idi)
						{
							cout << "was delete " << tmp << endl;
							del = true;
						}
						break;
					}
				}
			}

			count = 0;
			zap = "";
		}

		ifs.close();
		ofs.close();

		remove("TfileTMode.txt");
		rename("tmpTT.txt", "TfileTMode.txt");

		if (del == false)
		{
			cout << "element with id " << idi << " not found in file 'fileNameTT'" << endl;
		}
	}

	static void deleteFileTxtBin(int idi)
	{
		ifstream ifs;
		ofstream ofs;

		ifs.open(fileNameTB);
		ofs.open("tmpTB.txt", ofstream::app);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameTB'");
		}

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'tmpTB'");
		}

		bool del = false;
		Dish tmp;

		while (ifs.read((char*)&tmp, sizeof(Dish)))
		{
			if (tmp.id != idi)
			{
				ofs.write((char*)&tmp, sizeof(Dish));
			}
			if (tmp.id == idi)
			{
				cout << "was delete " << tmp;
				del = true;
			}
		}

		ifs.close();
		ofs.close();

		remove("TfileBMode.txt");
		rename("tmpTB.txt", "TfileBMode.txt");

		if (del == false)
		{
			cout << "element with id " << idi << " not found in file 'fileNameTT'" << endl;
		}
	}

	static void deleteFileBinBin(int idi)
	{
		ifstream ifs;
		ofstream ofs;

		ifs.open(fileNameBB);
		ofs.open("tmpBB.bin", ofstream::app);

		if (!ifs.is_open())
		{
			throw exception("Error openning file 'fileNameBB'");
		}

		if (!ofs.is_open())
		{
			throw exception("Error openning file 'tmpBB'");
		}

		bool del = false;
		Dish tmp;

		while (ifs.read(reinterpret_cast<char*>(&tmp), sizeof(Dish)))
		{
			if (tmp.id != idi)
			{
				ofs.write(reinterpret_cast<char*>(&tmp), sizeof(Dish));
			}
			if (tmp.id == idi)
			{
				cout << "was delete " << tmp;
				del = true;
			}
		}

		ifs.close();
		ofs.close();

		remove("BfileBMode.bin");
		rename("tmpBB.bin", "BfileBMode.bin");

		if (del == false)
		{
			cout << "element with id " << idi << " not found in file 'fileNameBB'" << endl;
		}
	}

	int getId()
	{
		return id;
	}

	void setter(int id, double cost, int calorie)
	{
		this->id = id;
		this->cost = cost;
		this->calorie = calorie;
	}

	Dish operator=(Dish dish)
	{
		this->id = dish.id;
		this->cost = dish.cost;
		this->calorie = dish.cost;

		return *this;
	}

	friend ostream& operator <<(ostream& os, Dish& dish)
	{
		return os << "id is " << dish.id << ", cost " << dish.cost << "$ and calories " << dish.calorie << " cal\n";
	}

	friend istream& operator >>(istream& is, Dish& dish)
	{
		return is >> dish.id >> dish.cost >> dish.calorie;
	}

	void print()
	{
		cout << "Dish id is " << id << ", its cost " << cost << "$ and calories " << calorie << " cal" << endl;
	}
};

void writeTT()
{
	cout << "Enter id: ";
	int id;
	cin >> id;

	cout << "Enter cost: ";
	double cost;
	cin >> cost;
	cout << "Enter calorie: ";
	int calorie;
	cin >> calorie;

	Dish dish;
	dish.setter(id, cost, calorie);
	dish.writeInTFileInTMode();
}

void writeTB()
{
	cout << "Enter id: ";
	int id;
	cin >> id;

	cout << "Enter cost: ";
	double cost;
	cin >> cost;
	cout << "Enter calorie: ";
	int calorie;
	cin >> calorie;

	Dish dish;
	dish.setter(id, cost, calorie);
	dish.writeInTFileInBmode();
}

void writeBB()
{
	cout << "Enter id: ";
	int id;
	cin >> id;

	cout << "Enter cost: ";
	double cost;
	cin >> cost;
	cout << "Enter calorie: ";
	int calorie;
	cin >> calorie;

	Dish dish;
	dish.setter(id, cost, calorie);
	dish.writeInBFileInBmode();
}

int main()
{
	char get;
	try
	{
		Dish dish;
		while(1)
		{
			cout << "1|Write in text file in text mode\n2|Write in text file in binary mode\n3|Write in binary file in binary mode\n"
				<< "4|View text file in text mode\n5|View text file in binary mode\n6|View binary file in binary mode\n"
				<< "7|Find element in all files\n8|Delete element from all files\n9|Exit" << endl;
			get = _getch();
			switch (get)
			{
			case '1':
				system("cls");
				writeTT();
				cout << "Object was added\nPress any key..." << endl;
				_getch();
				system("cls");
				break;
			case '2':
				system("cls");
				writeTB();
				cout << "Object was added\nPress any key..." << endl;
				_getch();
				system("cls");
				break;
			case '3':
				system("cls");
				writeBB();
				cout << "Object was added\nPress any key..." << endl;
				_getch();
				system("cls");
				break;
			case '4':
				system("cls");
				Dish::readTFileInTMode();
				cout << "Press any key...";
				_getch();
				system("cls");
				break;
			case '5':
				system("cls");
				Dish::readTFileInBMode();
				cout << "Press any key...";
				_getch();
				system("cls");
				break;
			case '6':
				system("cls");
				Dish::readBFileInBMode();
				cout << "Press any key...";
				_getch();
				system("cls");
				break;
			case '7':
				system("cls");
				cout << "Enter id: ";
				int id;
				cin >> id;
				Dish::findAllFiles(id);
				cout << "\nPress any key...";
				_getch();
				system("cls");
				break;
			case '8':
				system("cls");
				cout << "Enter id: ";
				id;
				cin >> id;
				Dish::deleteAllFiles(id);
				cout << "\nPress any key...";
				_getch();
				system("cls");
				break;
			case '9':
				system("cls");
				return 0;
			default:
				system("cls");
				cout << "Error value!" << endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}