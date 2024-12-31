#include <iostream>
using namespace std;

void calculate(float a, float b, float(*f)(float a, float x))
{
    float e = 0.001, x;
    do {
        x = (a + b) / 2;
        if (f(a, b) <= 0)
            b = x;
        else
            a = x;
    } while (abs(a - b) > 2 * e);
    cout << "x= " << x;
}

//float function(float a, float x)
//{
//    return (2-x*x+x) * (2-a*a+a);
//}
float function(float a, float x)
{
    return (pow(cos(x), 3)) * (pow(cos(a), 3));
}

void var6n1()
{
    setlocale(LC_CTYPE, "Ru");
    float a, b;
    cout << "¬ведите a: ";
    cin >> a;
    cout << "¬ведите b: ";
    cin >> b;
    calculate(a, b, function);
}




void fsum(int n, ...);

void var6n2()
{
    setlocale(LC_CTYPE, "Ru");
    cout << "—умма  по формуле S =a1 * a2 - a2 * a3 + a3 * a4 - . . ." << endl;
    fsum(4, 13, 512, 467, 0);
    fsum(2, 19, 2);
    fsum(5, 12, 226, 645, 14, 382);
}

void fsum(int n, ...)
{
    int* p = &n;
    float sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 0) {
            sum -= *(p + i * sizeof(short)) * *(p + (i + 1) * sizeof(short));
        }
        else {
            sum += *(p + i * sizeof(short)) * *(p + (i + 1) * sizeof(short));
        }
    }
    cout << "—умма = " << sum << endl;
}
 