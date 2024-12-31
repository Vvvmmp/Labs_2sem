#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Функция для поиска различных комбинаций чисел из введенного числа
void findDifferentNumbers(int number)
{
    // Преобразуем число в строку и сортируем его по возрастанию
    string numberString = to_string(number);
    sort(numberString.begin(), numberString.end());

    // Вектор для хранения перестановок
    vector<int> permutations;

    // Генерируем все перестановки чисел
    do {
        int permutation = stoi(numberString);
        permutations.push_back(permutation);
    } while (next_permutation(numberString.begin(), numberString.end()));

    // Сортируем перестановки по возрастанию
    sort(permutations.begin(), permutations.end());

    // Выводим различные комбинации чисел
    cout << "Различные комбинации чисел:\n";
    for (int permutation : permutations) {
        cout << permutation << ' ';
    }
}

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number;

    cout << "Введите число: ";
    cin >> number;

    // Проверяем корректность введенного числа
    if (number > 99999 || number < 10000) {
        cout << "Некорректный ввод";
        return 0;
    }

    // Вызываем функцию для поиска различных комбинаций чисел
    findDifferentNumbers(number);

    return 0;
}