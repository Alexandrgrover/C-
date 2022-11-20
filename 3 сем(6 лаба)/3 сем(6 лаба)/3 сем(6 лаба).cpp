#include <iostream>
#include <exception>
#include <string>

using namespace std;

class ListException : public exception
{
private:
	string m_error;

public:
	ListException(string error) : m_error(error)
	{

	}

	string what()
	{
		return m_error;
	}
}; 

class Node
{
private:
	int data;
	class Node* next;

public:
	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}

	int getData()
	{
		return data;
	}

	Node* operator =(Node* node)
	{
		return new Node(this->data = node->data);
	}

	bool operator ==(Node* node)
	{
		return this->data == node->data;
	}

	friend class List;
};

class List
{
private:
	Node* head;
	int count;

public:
	List()
	{
		head = NULL;
		count = 0;
	}

	void add(int data)
	{
		Node* node = new Node;

		if (head == NULL)
		{
			node->data = data;
			node->next = NULL;
			head = node;
			count++;
		}
		else
		{
			node->data = data;
			node->next = head;
			head = node;
			count++;
		}
	}

	void dele_te(int data)
	{
		if (count == 0)
		{
			throw ListException("List is empty");
		}

		int counter = 0;
		Node* error = head;
		while (error != NULL)
		{
			if (error->data == data)
			{
				counter++;
			}

			error = error->next;
		}

		if (counter == 0)
		{
			throw ListException("No given element(s) in this list");
		}
	
		Node* tmp = head;

		while (tmp != NULL)
		{
			if (tmp->data == data)
			{
				break;
			}

			tmp = tmp->next;
		}

		if (tmp->data == head->data)
		{
			delete(head);
			head = tmp->next;
			delete(tmp);
			count--;
		}
		else
		{
			Node* tmp2 = head;
			while (tmp2->next != tmp)
			{
				tmp2 = tmp2->next;
			}

			tmp2->next = tmp->next;
			delete(tmp);
			count--;
		}
	}

	void changeNodes(int data1, int data2)
	{
		if (count == 0)
		{
			throw ListException("List is empty");
		}

		if (count < 2)
		{
			throw ListException("Count of list lower than 2");
		}

		int counter1 = 0, counter2 = 0;
		Node* error = head;
		while (error != NULL)
		{
			if (error->data == data1)
			{
				counter1++;
			}

			if (error->data == data2)
			{
				counter2++;
			}

			error = error->next;
		}

		if (counter1 == 0 || counter2 == 0)
		{
			throw ListException("No given element(s) in this list");
		}

		Node* tmp1 = head;
		Node* tmp2 = head;

		while (tmp1 != NULL)
		{
			if (tmp1->data == data1)
			{
				break;
			}

			tmp1 = tmp1->next;
		}

		while (tmp2 != NULL)
		{
			if (tmp2->data == data2)
			{
				break;
			}

			tmp2 = tmp2->next;
		}

		if (tmp1 == head)
		{
			if (tmp1->next == tmp2)
			{
				tmp1->next = tmp2->next;
				tmp2->next = tmp1;
				head = tmp2;
			}
			else
			{
				Node* tmpPrev = head;
				while (tmpPrev->next != tmp2)
				{
					tmpPrev = tmpPrev->next;
				}
				Node* tmpSave = tmp1->next;
				tmp1->next = tmp2->next;
				tmpPrev->next = tmp1;
				tmp2->next = tmpSave;
				head = tmp2;
			}
		}
		else if (tmp2 == head)
		{
			if (tmp2->next == tmp1)
			{
				tmp2->next = tmp1->next;
				tmp1->next = tmp2;
				head = tmp1;
			}
			else
			{
				Node* tmpPrev = head;
				while (tmpPrev->next != tmp1)
				{
					tmpPrev = tmpPrev->next;
				}

				Node* tmpSave = tmp2->next;
				tmp2->next = tmp1->next;
				tmpPrev->next = tmp2;
				tmp1->next = tmpSave;
				head = tmp1;
			}
		}
		else
		{
			Node* tmpPrev1 = head;
			Node* tmpPrev2 = head;

			while (tmpPrev1->next != tmp1)
			{
				tmpPrev1 = tmpPrev1->next;
			}

			while (tmpPrev2->next != tmp2)
			{
				tmpPrev2 = tmpPrev2->next;
			}

			if (tmp1->next == tmp2)
			{
				tmp1->next = tmp2->next;
				tmp2->next = tmp1;
				tmpPrev1->next = tmp2;
			}
			else if (tmp2->next == tmp1)
			{
				tmp2->next = tmp1->next;
				tmp1->next = tmp2;
				tmpPrev2->next = tmp1;
			}
			else
			{
				Node* p = tmp1->next;
				tmp1->next = tmp2->next;
				tmp2->next = p;
				tmpPrev1->next = tmp2;
				tmpPrev2->next = tmp1;
			}
		}
	}

	Node* getNode(int data)
	{
		if (count == 0)
		{
			throw ListException("List is empty");
		}

		Node* tmp = head;
		int counter = 0;
		while (tmp != NULL)
		{
			if (tmp->data == data)
			{
				counter++;
				break;
			}

			tmp = tmp->next;
		}

		if (counter == 0)
		{
			throw ListException("No given element in this list");
		}

		return tmp;
	}

	Node* getHead()
	{
		return head;
	}

	void print()
	{
		if (count == 0)
		{
			throw ListException("List is empty");
		}

		Node* p = head;

		cout << "List" << endl;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << "\n";
	}

	friend class Node;
};

void terminate()
{
	cout << "My terminate handler!" << endl;
	exit(-1);
}

void unexpected()
{
	cout << "my_unexpected handler" << endl;
}

int main()
{
	try
	{
		List list;

		cout << "Enter size of list: ";
		int size;
		cin >> size;
		if (size < 0)
		{
			throw ListException("Size < 0");
		}

		cout << "Enter list" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Enter " << i + 1 << " element of list:";
			int tmp;
			cin >> tmp;
			list.add(tmp);
		}

		list.print();

		int changeObj1, changeObj2;
		cout << "Enter 2 elements, which you want to swap: ";
		cin >> changeObj1 >> changeObj2;
		list.changeNodes(changeObj1, changeObj2);

		list.print();

		cout << "Enter element, which you want to delete: ";
		int objDelete;
		cin >> objDelete;
		list.dele_te(objDelete);

		list.print();

		cout << "Enter 1 value to compare: ";
		Node* sravn1, sravn2;
		int sravnInt1;
		cin >> sravnInt1;
		sravn1 = list.getNode(sravnInt1);
		cout << "Enter 2 value to compare: ";
		int sravnInt2;
		cin >> sravnInt2;
		sravn2 = list.getNode(sravnInt2);

		int sravn = sravn2 == sravn1;
		if (sravn == 1)
		{
			cout << "Equal" << endl;
		}
		else
		{
			cout << "Not equal" << endl;
		}
	}
	catch (ListException error)
	{
		cout << error.what() << endl;
		terminate();
	}
}