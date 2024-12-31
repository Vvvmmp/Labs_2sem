#include <fstream>

using namespace std;

struct list
{
	int number;
	list* next;
};

void insert(list*&, float); //функция добавления элемента, передается адрес 
float del(list*&, float); //функция удаления, передается адрес списка и символ, 
float find(list*&, float); //функция поиска
int IsEmpty(list*); //функция, которая проверяет, пуст ли список
void printList(list*); //функция вывода
void sumElemenentDividedFive(list*); //функция подсчета суммы положительных элементов
void toFile(list *&p); //Запись в файл
void fromFile(list *&p); //Считывание из файла

int variant6()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	float value;

	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вычисление суммы положительных элементов, кратных 5" << endl;
	cout << " 4 - Запись списка в файл" << endl;
	cout << " 5 - Чтение списка из файла" << endl;
	cout << " 6 - Поиск числа" << endl;
	cout << " 0 - Выход" << endl;
	cout << " ? ";
	cin >> choice;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << "Введите число "; // добавить число в список
			cin >> value;
			insert(first, value);
			printList(first);
			break;

		case 2:
			if (!IsEmpty(first)) // удалить число из списка
			{
				cout << "Введите удаляемое число ";
				cin >> value;
				if (del(first, value))
				{
					cout << "Удалено число " << value << endl;
					printList(first);
				}
				else
					cout << "Число не найдено" << endl;
			}
			  else
			cout << "Список пуст" << endl;
			break;

		case 3:
			sumElemenentDividedFive(first); // вычисление суммы положительных элементов
				break;

		case 4:
			toFile(first);
			break;

		case 5:
			fromFile(first);
			break;

		case 6:
			if (!IsEmpty(first)) // есть ли число в списке?
			{
				cout << "Введите число ";
				cin >> value;
				if (find(first, value))
				{
					cout << "Найдено число: " << value << endl;
					printList(first);
				}
				else
					cout << "Число не найдено" << endl;
			}
			else
				cout << "Список пуст" << endl;
			break;

		default: cout << "Неправильный выбор" << endl;
			break;
		}

		cout << "? ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}

void insert(list*& p, float value) //Добавление числа value в список
{
	list* newP = new list;
	if (newP != NULL) //есть ли место? 
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

float del(list * &p, float value) // Удаление числа
{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next; // отсоединить узел
		delete temp; //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему
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

int IsEmpty(list* p) //Список пустой? (1-да, 0-нет)
{
	return p == NULL;
}

void printList(list * p) //Вывод списка
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void sumElemenentDividedFive(list* p) // Вычисление суммы положительных элементов, кратных 5
{
	int sm = 0;
	
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number > 0 && p->number % 5 == 0) 
				sm = sm + (p->number);			
				p = p->next;
			
		}
		cout << "Сумма положительных элементов, кратных 5= " << sm << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p) //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
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
	cout << "\nСписок считан из файла mList.dat\n";
}

float find(list*& p, float value) // Поиск
{
	list* current = p;
	while (current != NULL)
	{
		if (current->number == value)
		{
			return current->number; // Возвращаем найденное значение
		}
		current = current->next; // Переходим к следующему элементу списка
	}

	return 0.0f; // Значение не найдено, возвращаем значение по умолчанию
}