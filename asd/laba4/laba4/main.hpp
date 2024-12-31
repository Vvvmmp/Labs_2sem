#include <time.h>

using namespace std;

#define MAX_PRODUCT 10000

void number1()
{
	int N, max = INT_MIN, min = INT_MAX;
	cout << "Введите число товаров: ";
	cin >> N;
	cout << endl;
	int* array = new int[N];
	int* resultArray = new int[N];
	

	if (N> MAX_PRODUCT)
	{
		cout << "Превышено максимальное кол-во!";
		return;
	}

	srand(time(NULL));
	cout << "Всего товаров в чеке: ";
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << ' ';
	}

	int temp; 

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << "\nисходный: ";
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ' ';
	}

	int minIndex = 0;
	int maxIndex = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (array[j] > max)
			{
				max = array[j];
				maxIndex = j;
			}
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}

		resultArray[i] = max;	
		

		for (int k = minIndex; k < N - 1; k++)
		{
			array[k] = array[k + 1];
		}
		
		N--;
	}

	cout << "\nитоговый: ";
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ' ';
		sum += array[i];
	}
	cout << "Сумма: " << sum;
	
}

void number2()
{
	int N;
	int counter = 0, differentScore = 0;
	cout << "Введите кол-во участников: ";
	cin >> N;
	cout << endl;
	int* array = new int[N];
	int* resultArray = new int[N];
	int* diffArray = new int[3];

	if (N > MAX_PRODUCT)
	{
		cout << "Превышено максимальное кол-во!";
		return;
	}

	srand(time(NULL));
	cout << "\nРезультаты участников олимпиады: ";
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 10+1;
		cout << array[i] << ' ';
	}

	int temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << "\nОтсортированные результаты: ";
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ' ';
	}

	int score = 0, m = 0;
	cout << "\nВсе оценки с дипломами: ";
	for (int j = N-1; j >= 0; j--)
	{
		resultArray[j] = array[j];
		if (resultArray[j] != resultArray[j + 1])
		{
			differentScore++;
			while (score < differentScore)
			{
				diffArray[m] = resultArray[j];
				score++;
				m++;
			}
			if (differentScore > 3)
			{
				cout << "\nВсего дипломов: " << counter;
				cout << "\n1 место - " << diffArray[0];
				cout << "\n2 место - " << diffArray[1];
				cout << "\n3 место - " << diffArray[2];
				return;
			}
		}

		cout << resultArray[j] << ' ';
		counter++;
	}

		

		delete[] array;
		delete[] resultArray;
		delete[] diffArray;
}