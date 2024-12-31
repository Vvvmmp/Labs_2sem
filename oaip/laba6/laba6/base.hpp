#include <fstream>

using namespace std;

struct list
{
	int number;
	list* next;
};

void insert(list*&, float); //������� ���������� ��������, ���������� ����� 
float del(list*&, float); //������� ��������, ���������� ����� ������ � ������, 
float find(list*&, float); //������� ������
int IsEmpty(list*); //�������, ������� ���������, ���� �� ������
void printList(list*); //������� ������
void sumElemenentDividedFive(list*); //������� �������� ����� ������������� ���������
void toFile(list *&p); //������ � ����
void fromFile(list *&p); //���������� �� �����

int variant6()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	float value;

	cout << "�������� �����:" << endl;
	cout << " 1 - ���� �����" << endl;
	cout << " 2 - �������� �����" << endl;
	cout << " 3 - ���������� ����� ������������� ���������, ������� 5" << endl;
	cout << " 4 - ������ ������ � ����" << endl;
	cout << " 5 - ������ ������ �� �����" << endl;
	cout << " 6 - ����� �����" << endl;
	cout << " 0 - �����" << endl;
	cout << " ? ";
	cin >> choice;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "������� ����� "; // �������� ����� � ������
			cin >> value;
			insert(first, value);
			printList(first);
			break;

		case 2:
			if (!IsEmpty(first)) // ������� ����� �� ������
			{
				cout << "������� ��������� ����� ";
				cin >> value;
				if (del(first, value))
				{
					cout << "������� ����� " << value << endl;
					printList(first);
				}
				else
					cout << "����� �� �������" << endl;
			}
			  else
			cout << "������ ����" << endl;
			break;

		case 3:
			sumElemenentDividedFive(first); // ���������� ����� ������������� ���������
				break;

		case 4:
			toFile(first);
			break;

		case 5:
			fromFile(first);
			break;

		case 6:
			if (!IsEmpty(first)) // ���� �� ����� � ������?
			{
				cout << "������� ����� ";
				cin >> value;
				if (find(first, value))
				{
					cout << "������� �����: " << value << endl;
					printList(first);
				}
				else
					cout << "����� �� �������" << endl;
			}
			else
				cout << "������ ����" << endl;
			break;

		default: cout << "������������ �����" << endl;
			break;
		}

		cout << "? ";
		cin >> choice;
	}
	cout << "�����" << endl;
	return 0;
}

void insert(list*& p, float value) //���������� ����� value � ������
{
	list* newP = new list;
	if (newP != NULL) //���� �� �����? 
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}

float del(list * &p, float value) // �������� �����
{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next; // ����������� ����
		delete temp; //���������� ������������� ���� 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // ������� � ����������
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}

int IsEmpty(list* p) //������ ������? (1-��, 0-���)
{
	return p == NULL;
}

void printList(list * p) //����� ������
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void sumElemenentDividedFive(list* p) // ���������� ����� ������������� ���������, ������� 5
{
	int sm = 0;
	
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number > 0 && p->number % 5 == 0) 
				sm = sm + (p->number);			
				p = p->next;
			
		}
		cout << "����� ������������� ���������, ������� 5= " << sm << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.dat\n";
}

void fromFile(list*& p) //���������� �� �����
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
			exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\n������ ������ �� ����� mList.dat\n";
}

float find(list*& p, float value) // �����
{
	list* current = p;
	while (current != NULL)
	{
		if (current->number == value)
		{
			return current->number; // ���������� ��������� ��������
		}
		current = current->next; // ��������� � ���������� �������� ������
	}

	return 0.0f; // �������� �� �������, ���������� �������� �� ���������
}