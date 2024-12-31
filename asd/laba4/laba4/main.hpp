#include <time.h>

using namespace std;

#define MAX_PRODUCT 10000

void number1()
{
	int N, max = INT_MIN, min = INT_MAX;
	cout << "������� ����� �������: ";
	cin >> N;
	cout << endl;
	int* array = new int[N];
	int* resultArray = new int[N];
	

	if (N> MAX_PRODUCT)
	{
		cout << "��������� ������������ ���-��!";
		return;
	}

	srand(time(NULL));
	cout << "����� ������� � ����: ";
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

	cout << "\n��������: ";
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

	cout << "\n��������: ";
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ' ';
		sum += array[i];
	}
	cout << "�����: " << sum;
	
}

void number2()
{
	int N;
	int counter = 0, differentScore = 0;
	cout << "������� ���-�� ����������: ";
	cin >> N;
	cout << endl;
	int* array = new int[N];
	int* resultArray = new int[N];
	int* diffArray = new int[3];

	if (N > MAX_PRODUCT)
	{
		cout << "��������� ������������ ���-��!";
		return;
	}

	srand(time(NULL));
	cout << "\n���������� ���������� ���������: ";
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

	cout << "\n��������������� ����������: ";
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ' ';
	}

	int score = 0, m = 0;
	cout << "\n��� ������ � ���������: ";
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
				cout << "\n����� ��������: " << counter;
				cout << "\n1 ����� - " << diffArray[0];
				cout << "\n2 ����� - " << diffArray[1];
				cout << "\n3 ����� - " << diffArray[2];
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