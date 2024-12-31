#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	
	int N, N1, maxSteps=1, result, order = 1, flag=0;
	bool answer = 0;

	cout << "Введите N(диапазон от 1 до N) и загадайте число X: ";
	cin >> N;

	if(N == 0)
	{
		cout << "Введено некорректное значение.";
		return 0;
	}

	N1 = N;

	while (N1 / 2 > 0)
	{
		N1 /= 2;
		maxSteps++;
	}

	int* array = new int[maxSteps];

	int minValue = 1, maxValue = N;
	
	if (N % 2 == 0) {
		result = N / 2;
	}
	else {
		result = (N + 1) / 2;
	}
	

	while (!answer)
	{
		
		
		cout << "\nВаше загаданное число равно: " << result;
		cout << "\nНажмите 1, если число угадано верно";
		cout << "\nНажмите 2, если загаданное число меньше";
		cout << "\nНажмите 3, если загаданное число больше\n";

		while (flag != 1)
		{
			array[0] = result;
			flag++;
		}
			
		
		
		int choice;
		cin >> choice;


		switch (choice)
		{
		case 1:
			
			cout << "Максимальное количество шагов при бинарном поиске равно: " << maxSteps << "\n";
			cout << "Промежуточные шаги: ";
			for (int i = 0; i < order; i++)    
			{
				cout << array[i] << ' ';
			}
			answer = 1;
			break;

		case 2: //Если меньше
			maxValue = result;
			result = (maxValue + minValue) / 2;
			for (int i = order; i < order+1; i++)
			{
				array[i] = result;
			}
			order++;
			break;

		case 3: //Если больше
			minValue = result;
			result = (maxValue + minValue) / 2;
			for (int i = order; i < order + 1; i++)
			{
				array[i] = result;
			}
			order++;
			break;

		default:
			cout << "Введено неверное значение.\n";
			break;
		}

	}
	return 0;
}

