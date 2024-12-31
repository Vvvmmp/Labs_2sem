#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{	
		cout << "1 - Вывод первой кучи на экран" << endl;
		cout << "2 - Добавить элемент в первой кучу" << endl;
		cout << "3 - Вывод второй кучи на экран" << endl;
		cout << "4 - Добавить элемент в второй кучу" << endl;
		cout << "5 - Объединение двух куч" << endl;
		cout << "6 - Удалить минимальный элемент первой кучи" << endl;
		cout << "7 - Удалить i-й элемент первой кучи" << endl;
		cout << "8 - Сумма вершин" << endl; 
		cout << "9 - Количество листьев" << endl; 
		cout << "10 - Сумма значений листьев" << endl; 
		cout << "0 - выход" << endl;
		cout << "Ваш выбор: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: h1.scan(0);
			break;
		case 2:
		{AAA* a = new AAA;
		cout << "Введите ключ" << endl; cin >> k;
		a->x = k;
		h1.insert(a);
		}
		break;
		case 3: h2.scan(0);
			break;
		case 4:
		{AAA* a = new AAA;
		cout << "Введите ключ" << endl; cin >> k;
		a->x = k;
		h2.insert(a);
		h1.insert(a);
		}
		break;
		case 5:
			h1.scan(0);
			break;
		case 6: h1.extractMin();
			break;
		case 7: h1.extractI();
			break;
		case 8: cout << "Сумма вершин: " << h1.sumVertices() << endl;
			break;
		case 9: cout << "Количество листьев: " << h1.countLeaves() << endl;
			break;
		case 10: cout << "Сумма значений листьев: " << h1.sumLeaves() << endl;
			break;

		default: cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}


