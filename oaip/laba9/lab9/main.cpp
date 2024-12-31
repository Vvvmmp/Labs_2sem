#include "List.h"
#include <Windows.h>
using namespace std;

void print(char* nameProduct, char* price, char* quantity, int percent)
{
	cout << nameProduct << "  " << price << "  " << quantity << "  " << percent << '\n';
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	Object L1 = Create();
	do {
		cout << "Выберите вариант: " << endl;
		cout << "1. Внести элемент в начало списка" << endl;
		cout << "2. Вывод" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Удаление элемента" << endl;
		cout << "5. Удалить список" << endl;
		cout << "6. Подсчёт число элементов списка" << endl;
		cout << "7. Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			char nameProduct[50];
			char price[50];
			char quantity[50];
			int percent;
			
			cout << "Название продукта: ";
			cin >> nameProduct;
			cout << "Цена: ";
			cin >> price;
			cout << "Количество: ";
			cin >> quantity;
			cout << "Процент надбавки: ";
			cin >> percent;
			L1.Insert(nameProduct, price, quantity, percent);
			break;
		}
		case 2:
		{
			L1.PrintList(print);
			break;
		}
		case 3:
		{
			char price[50];
			cout << "Введите Цену: ";
			cin >> price;
			Element* e = L1.Search(price);
			if (e == NULL)
			{
				cout << "Элемент не найден" << endl;
			}
			else
			{
				cout << "Найден элемент= " << e->NameProduct << " " << e->Price << " " << e->Quantity << " " << e->Percent << '\n';
			}
			break;
		}
		case 4:
		{
			char productname[50];
			cout << "Введите название товара для удаления: ";
			cin >> productname;
			bool rc = L1.Delete(productname);
			if (rc == true) cout << "Удален элемент" << endl;
			break;
		}
		case 5:
		{
			if (L1.DeleteList())
			{
				cout << "Список успешно удалён" << endl;
			}
			else {
				cout << "Ошибка удаления" << endl;
			}
			break;
		}
		case 6: {
			cout << "Количество элементов: " << L1.CountList() << endl;
			break;
		}
		}
	} while (choice != 7);
	return 0;
}
