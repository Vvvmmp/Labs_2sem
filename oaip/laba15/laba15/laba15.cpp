#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


int main() 
{
	//по коду массив заполняется рандомными элементами от 1 до 50. 
	// Далее копируется во 2 массив. 
	// После сортируется двумя разными способами и считает время
	srand(time(NULL));
	setlocale(0, "");
	int size;
	cout << "\nВведите размерность массива:";
	cin >> size;

	int* ArrayA = new int[size];
	cout << "\nИсходный массив: ";
	for (int i = 0; i < size; i++)
	{
		ArrayA[i] = rand() % 50 + 1;
		cout << ArrayA[i] << ' ';
	}
	auto startTime = chrono::high_resolution_clock::now();
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int temp = ArrayA[i];
			int j;
			for (j = i; j >= gap && ArrayA[j - gap] > temp; j -= gap) {
				ArrayA[j] = ArrayA[j - gap];
			}
			ArrayA[j] = temp;
		}
	}
	auto endTime = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
	cout << "\nВремя выполнения сортировкой Шелла: " << duration << " микросекунд." << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ArrayA[i] << ' ';
	}
	delete[] ArrayA;
	return 0;
}