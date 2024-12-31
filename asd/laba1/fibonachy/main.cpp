#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long int cycle(int n);
long long int recursion(int n);


int main()
{
    setlocale(0, "");

    int n;
    cout << "������� ������� ����� ���������: ";
    cin >> n;

    auto startCycle = high_resolution_clock::now();
    long long int resultCycle = cycle(n);
    auto stopCycle = high_resolution_clock::now();
    auto durationCycle = duration_cast<minutes>(stopCycle - startCycle);
    auto secondsCycle = duration_cast<seconds>(stopCycle - startCycle) % 60;

    auto startRecursion = high_resolution_clock::now();
    long long int resultRecursion = recursion(n);
    auto stopRecursion = high_resolution_clock::now();
    auto durationRecursion = duration_cast<minutes>(stopRecursion - startRecursion);
    auto secondsRecursion = duration_cast<seconds>(stopRecursion - startRecursion) % 60;
   
    cout << "����� ������� " << n << " (����): \t" << resultCycle << endl;
    cout << "����� ������: " << durationCycle.count() << " ����� " << secondsCycle.count() << " ������" << endl;

   cout << "����� ������� " << n << " (��������): \t" << resultRecursion << endl;
    cout << "����� ���������: " << durationRecursion.count() << " ����� " << secondsRecursion.count() << " ������" << endl;

    return 0;
}

long long int cycle(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long int a = 0, b = 1, s = 0;
    for (int i = 3; i <= n; i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

long long int recursion(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return recursion(n - 1) + recursion(n - 2);
}