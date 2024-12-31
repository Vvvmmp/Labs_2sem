#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

const int MAX_NAME_SIZE = 100;

struct product
{
	char name[MAX_NAME_SIZE];
	float price;
	int percent;
	int amount;
};

void input(int size);
void output();
void find(float price);
void deleteProduct(const string& productName);

void variant6()
{
	int choice, number;
	float price;
	string prodName;

	do
	{
		cout << "\n1.���� ������ � ���������� � ������ � ����\n";
		cout << "2.����� ������ �� �����\n";
		cout << "3.����� �� ����\n";
		cout << "4.�������� ������\n";
		cout << "0.����� �� ���������\n\n";
		cout << "������� ����� ��������: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "������� ���������� �������: ";
			cin >> number;
			input(number);
			break;

		case 2:
			output();
			break;

		case 3:
			cout << "������� ����: ";
			cin >> price;
			find(price);
			break;

		case 4:
			cout << "������� ��������: ";
			cin >> prodName;
			deleteProduct(prodName);
			break;

		case 0:
			exit(0);
			break;

		default:
			cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
			break;
		}
	} while (choice != 0);
}

void input(int size)
{
	FILE* f;
	product buf;

	if (fopen_s(&f, "base.txt", "ab+") == 0) // ��������� ���� � ������ ����������/������ � �������� ������
	{
		for (int p = 0; p < size; p++)
		{
			cout << "��������: ";
			cin >> buf.name;
			cout << "����������: ";
			cin >> buf.amount;
			cout << "����: ";
			cin >> buf.price;
			if (buf.amount >= 0 && buf.amount < 5)
				buf.percent = 30;
			if (buf.amount >= 5 && buf.amount < 10)
				buf.percent = 25;
			if (buf.amount >= 10 && buf.amount < 15)
				buf.percent = 20;
			if (buf.amount >= 15 && buf.amount < 20)
				buf.percent = 15;
			if (buf.amount >= 20 && buf.amount < 25)
				buf.percent = 10;
			if (buf.amount >= 25)
				buf.percent = 5;
			cout << "������� �������� ��������: " << buf.percent << "\n\n";

			fwrite(&buf, sizeof(buf), 1, f); // ���������� ��������� � ����
		}

		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
}

void output()
{
	FILE* f;
	product buf;

	if (fopen_s(&f, "base.txt", "rb") == 0) // ��������� ���� � ������ ������ � �������� ������
	{
		cout << "\n�������� ���������� ���� �������\n";
		fread(&buf, sizeof(buf), 1, f); // ������ ��������� �� �����

		while (!feof(f))
		{
			cout << buf.name << "  " << buf.amount << "  " << buf.price << "  " << buf.percent << endl;
			fread(&buf, sizeof(buf), 1, f); // ������ ��������� ��������� �� �����
		}

		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
}

void find(float price)
{
	FILE* f;
	product buf;
	bool found = false;

	if (fopen_s(&f, "base.txt", "rb") == 0) // ��������� ���� � ������ ������ � �������� ������
	{
		while (fread(&buf, sizeof(buf), 1, f) == 1)
		{
			if (buf.price == price)
			{
				cout << "\n�������� ����������\n";
				cout << buf.name << "\t " << buf.amount << endl;
				found = true;
			}
		}

		fclose(f);

		if (!found)
			cout << "����� �� ������\n";
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
}

void deleteProduct(const string& productName)
{
	ifstream inputFile("base.txt", ios::binary); // ��������� ������� ���� � �������� ������
	ofstream tempFile("temp.bin", ios::binary); // ��������� ��������� ���� ��� ������ � �������� ������

	if (!inputFile || !tempFile)
	{
		cout << "������ �������� ������" << endl;
		return;
	}

	product buf;
	bool deleted = false;

	while (inputFile.read(reinterpret_cast<char*>(&buf), sizeof(buf)))
	{
		if (buf.name == productName)
		{
			deleted = true;
			continue;  // ���������� ������ ������, ������� ����� �������
		}

		tempFile.write(reinterpret_cast<const char*>(&buf), sizeof(buf)); // ���������� ��������� �� ��������� ����
	}

	inputFile.close();
	tempFile.close();

	if (deleted)
	{
		if (remove("base.txt") != 0) // ������� �������� ����
		{
			cout << "������ �������� �����" << endl;
			return;
		}

		if (rename("temp.bin", "base.txt") != 0) // ��������������� ��������� ���� � �������� ���
		{
			cout << "������ �������������� �����" << endl;
			return;
		}

		cout << "����� ������� ������" << endl;
	}
	else
	{
		cout << "����� �� ������" << endl;
	}
}