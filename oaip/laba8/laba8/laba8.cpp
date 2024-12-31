#include <iostream>
#include <fstream> 
#include <Windows.h> 
#include <string>

using namespace std;

// Структура для представления узла в очереди
struct Node
{
	char symbol; // Символ
	Node* next = nullptr; // Указатель на следующий узел
};

// Очередь
struct queue
{
	Node* first = nullptr; // Указатель на первый узел
	Node* last = nullptr; // Указатель на последний узел
};

// Функция для добавления элемента в очередь
void push(queue*& q, char n)
{
	if (q->first == nullptr)
	{
		q->first = q->last = new Node;
		q->first->symbol = q->last->symbol = n;
		return;
	}
	q->last = q->last->next = new Node;
	q->last->symbol = n;
}

int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	queue* Symbols = new queue; // Очередь для символов
	queue* Numbers = new queue; // Очередь для чисел

	string buf;

	ifstream Fin("f.txt"); // Открытие файла для чтения
	ofstream Fout("g.txt"); // Открытие файла для записи

	while (!Fin.eof())
	{
		getline(Fin, buf); // Чтение строки из файла

		// Разбор строки на символы и добавление их в соответствующие очереди
		for (int i = 0; i < buf.length(); i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				push(Numbers, buf[i]); // Добавление цифры в очередь чисел
			}
			else
			{
				push(Symbols, buf[i]); // Добавление символа в очередь символов
			}
		}

		// Запись символов из очереди символов в файл
		while (Symbols->first != nullptr)
		{
			Fout.write((char*)&Symbols->first->symbol, sizeof(char));
			Symbols->first = Symbols->first->next;
		}

		Fout << ' '; // Добавление пробела между символами и числами

		// Запись чисел из очереди чисел в файл
		while (Numbers->first != nullptr)
		{
			Fout.write((char*)&Numbers->first->symbol, sizeof(char));
			Numbers->first = Numbers->first->next;
		}

		Fout << '\n'; // Переход на новую строку в файле
	}

	Fin.close(); // Закрытие файла чтения
	Fout.close(); // Закрытие файла записи

	return 0;
}