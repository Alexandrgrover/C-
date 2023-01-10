#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string filePath1 = "file1.txt";
string filePath2 = "file2.txt";

int search(string symbols, string fileStr)
{
	int countWord = 0;

	int searchSpace = 0;

	while (1)
	{
		searchSpace = 0;
		searchSpace = fileStr.find(" ", searchSpace);
		if (searchSpace != -1)
		{
			string word;
			word = fileStr.substr(0, searchSpace);
			int i = 0;
			while (i < symbols.size())
			{
				if (word.find(symbols[i]) != -1)
				{
					countWord++;
					cout << "Symbol " << symbols[i] << " was found in word " << word << endl;
					break;
				}

				i++;
			}

			fileStr.erase(0, searchSpace + 1);
		}
		else
		{
			int i = 0;
			while (i < symbols.size())
			{
				if (fileStr.find(symbols[i]) != -1)
				{
					countWord++;
					cout << "Symbol " << symbols[i] << " was found in word " << fileStr << endl;
					break;
				}

				i++;
			}

			break;
		}
	}

	return countWord;
}

void readAndWriteFile(string symbols)
{
	try
	{
		ifstream ifs;
		ifs.open(filePath1);
		if (!ifs.is_open())
		{
			throw exception("Error openning file!");
		}
		else
		{
			cout << "File " << filePath1 << " open successful" << endl;
		}

		ofstream ofs;
		ofs.open(filePath2, ofstream::app);
		if (!ofs.is_open())
		{
			throw exception("Error openning file!");
		}
		else
		{
			cout << "File " << filePath2 << " open successful" << endl;
		}

		string fileStr;
		int countStr = 1;
		while (getline(ifs, fileStr))
		{
			cout << "\nThe string was read " << countStr++ << ": " << fileStr << endl;

			int countWord = search(symbols, fileStr);

			ofs << to_string(countWord) << "\n";
			cout << "String with result was add in file " << filePath2 << endl;
		}

		ifs.close();
		cout << "\nFile with name " << filePath1 << " was closed" << endl;
		ofs.close();
		cout << "File with name " << filePath2 << " was closed" << endl;
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}

int main()
{
	cout << "Enter symbols for search: ";
	string symbols;
	cin >> symbols;

	readAndWriteFile(symbols);
}