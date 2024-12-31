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
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по цене\n";
		cout << "4.Удаление товара\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите количество товаров: ";
			cin >> number;
			input(number);
			break;

		case 2:
			output();
			break;

		case 3:
			cout << "Введите цену: ";
			cin >> price;
			find(price);
			break;

		case 4:
			cout << "Введите название: ";
			cin >> prodName;
			deleteProduct(prodName);
			break;

		case 0:
			exit(0);
			break;

		default:
			cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
			break;
		}
	} while (choice != 0);
}

void input(int size)
{
	FILE* f;
	product buf;

	if (fopen_s(&f, "base.txt", "ab+") == 0) // Открываем файл в режиме добавления/чтения в двоичном режиме
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Название: ";
			cin >> buf.name;
			cout << "Количество: ";
			cin >> buf.amount;
			cout << "Цена: ";
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
			cout << "Процент торговой надбавки: " << buf.percent << "\n\n";

			fwrite(&buf, sizeof(buf), 1, f); // Записываем структуру в файл
		}

		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	FILE* f;
	product buf;

	if (fopen_s(&f, "base.txt", "rb") == 0) // Открываем файл в режиме чтения в двоичном режиме
	{
		cout << "\nНазвание количество цена процент\n";
		fread(&buf, sizeof(buf), 1, f); // Читаем структуру из файла

		while (!feof(f))
		{
			cout << buf.name << "  " << buf.amount << "  " << buf.price << "  " << buf.percent << endl;
			fread(&buf, sizeof(buf), 1, f); // Читаем следующую структуру из файла
		}

		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void find(float price)
{
	FILE* f;
	product buf;
	bool found = false;

	if (fopen_s(&f, "base.txt", "rb") == 0) // Открываем файл в режиме чтения в двоичном режиме
	{
		while (fread(&buf, sizeof(buf), 1, f) == 1)
		{
			if (buf.price == price)
			{
				cout << "\nНазвание Количество\n";
				cout << buf.name << "\t " << buf.amount << endl;
				found = true;
			}
		}

		fclose(f);

		if (!found)
			cout << "Товар не найден\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void deleteProduct(const string& productName)
{
	ifstream inputFile("base.txt", ios::binary); // Открываем входной файл в двоичном режиме
	ofstream tempFile("temp.bin", ios::binary); // Открываем временный файл для записи в двоичном режиме

	if (!inputFile || !tempFile)
	{
		cout << "Ошибка открытия файлов" << endl;
		return;
	}

	product buf;
	bool deleted = false;

	while (inputFile.read(reinterpret_cast<char*>(&buf), sizeof(buf)))
	{
		if (buf.name == productName)
		{
			deleted = true;
			continue;  // Пропускаем запись товара, который нужно удалить
		}

		tempFile.write(reinterpret_cast<const char*>(&buf), sizeof(buf)); // Записываем структуру во временный файл
	}

	inputFile.close();
	tempFile.close();

	if (deleted)
	{
		if (remove("base.txt") != 0) // Удаляем исходный файл
		{
			cout << "Ошибка удаления файла" << endl;
			return;
		}

		if (rename("temp.bin", "base.txt") != 0) // Переименовываем временный файл в исходное имя
		{
			cout << "Ошибка переименования файла" << endl;
			return;
		}

		cout << "Товар успешно удален" << endl;
	}
	else
	{
		cout << "Товар не найден" << endl;
	}
}