#include <iostream>
#include <cstdarg>
#include <limits>

using namespace std;

void fsum2(int n, ...);

void dop2()
{
    setlocale(LC_CTYPE, "Ru");
    cout << "Сумма  по формуле S = a1 * a2 + a2 * a3 + ..." << endl;
    fsum2(4, 29, 52, 37, 0);
    fsum2(2, 229, 91);
    fsum2(5, 13, 226, 45, 13, 381);
}

void fsum2(int n, ...)
{
    int* p = &n;
    float sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        sum += *(p + i * sizeof(short)) * *(p + (i + 1) * sizeof(short));
    }
    cout << "Сумма = " << sum << endl;
}

// функция fmax с переменным числом параметров
template<typename t>
t fmax(int type, int num, ...) {
    // инициализируем переменную min значением максимального числа типа t
    t min = numeric_limits<t>::max();

    
    if (type == 0) { // int
        va_list args;
        va_start(args, num);
        for (int i = 0; i < num; ++i) {
            t val = va_arg(args, int);
            if (val < min) {
                min = val;
            }
        }
        va_end(args);
    }
    else if (type == 1) { // double
        va_list args;
        va_start(args, num);
        for (int i = 0; i < num; ++i) {
            t val = va_arg(args, double);
            if (val < min) {
                min = val;
            }
        }
        va_end(args);
    }

    return min;
}

void dop3() {
   
    int result1 = fmax<int>(1, 5, 10, 20, 5, 15, 25); 
    double result2 = fmax<double>(1, 4, 3.14, 2.71, 1.618, 0.123);

    cout << "min int: " << result1 << endl;
    cout << "min double: " << result2 << endl;

   
}

// Функция fmin с переменным числом параметров для определения минимального числа типа int
int fmin(int num, ...) {
    int maxi = INT_MIN; // Инициализируем минимальное значение максимальным возможным значением для int
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; ++i) {
        int current = va_arg(args, int);
        if (current > maxi) {
            maxi = current;
        }
    }
    va_end(args);
    return maxi;
}

void dop1() {
    // Вызов функции fmin с различным количеством параметров
    int max1 = fmin(3, 23, 3, 6);
    int max2 = fmin(5, 50, 4, 5, 30, 5);
    int max3 = fmin(4, 100, 50, 75, 25);

    // Вывод результатов
    cout << "Max 1: " << max1 << endl;
    cout << "Max 2: " << max2 << endl;
    cout << "Max 3: " << max3 << endl;

   
}