#include <iostream>

using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int f = 1, int g = 2)
{
	return (a + b + c + d + e + f + g) / 7;
}

int main()
{
	setlocale(0, "");

	int x1 = defaultparm(1, 2, 3, 4, 5);
	int x2 = defaultparm(1, 2, 3, 4, 5, 6);
	int x3 = defaultparm(1, 2, 3, 4, 5, 6, 7);

	cout << "\n 5 параметров: " << x1;
	cout << "\n 6 параметров: " << x2;
	cout << "\n 7 параметров: " << x3;
}