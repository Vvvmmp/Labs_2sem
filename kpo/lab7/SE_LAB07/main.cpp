#include <iostream>
#include "call.h"
#include <Windows.h>

using namespace Call;
using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x=4, y=3, z=2, k=1;
	//int choice = 1;

	//while (choice != 0)
	//{
	//	cout << "\nВыберите 1 из предложенных вариантов\n";
	//	cout << "1. Вызов функции ccdecl (сумма x y z)\n";
	//	cout << "2. Вызов функции cstd (произведение x y z)\n";
	//	cout << "3. Вызов функции cfst (сумма x y z k)\n";
	//	cout << "0. Выход из программы\n";
	//
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 1:
	//		cout << "Введите x y z: ";
	//		cin >> x >> y >> z;
	//		cout << ccdecl(x, y, z);
	//		break;
	//	
	//	case 2:
	//		cout << "Введите x y z: ";
	//		cin >> x >> y >> z;
	//		cout << cstd(x, y, z);
	//		break;
	//
	//	case 3:
	//		cout << "Введите x y z k: ";
	//		cin >> x >> y >> z >> k;
	//		cout << cfst(x, y, z, k);
	//		break;
	//
	//	case 0:
	//		exit(0);
	//		break;
	//
	//	default:
	//		cout << "Некорректный ввод";
	//		break;
	//
	//	}
	//}
	int value = Call::ccdecl(x,y,z);
	int value2 = Call::cstd(x,y,z);
	int value3 = Call::cfst(x,y,z,k);
	return 0;
}