#include <iostream>
#include <windows.h> 

using namespace std;

char f1(char c) {
	return c;
}
char f2(char c) {
	return c;
}

int main()
{
	setlocale(0, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	
	int n, x, y, z;
	float s;
	bool firstBool = false, secondBool = true;
	char engChar = 'u';//utf-8
	char rusChar = 'у';//windows-1251
	wchar_t testChar = 'u';//utf-16
	wchar_t testChar2 = 'у';//utf-16
	short X = 0x0001;
	short negativeX = -X;
	short maxShort = SHRT_MAX;
	short minShort = SHRT_MIN;
	unsigned short maxUnsignedShort = 0xFFFF;
	int Y = 0x001;
	int negativeY = -Y;
	int maxInt = 0x7FFFFFFF;
	int minInt = 0x80000000;
	unsigned int maxUnsignedInt = 0xFFFFFFFF;
	unsigned int minUnsignedInt = 0x0000;
	long int Z = 0x7FFFFFFFFFFFFFFF;
	long negativeZ = -Z;
	long maxLong = 0x7FFFFFFFFFFFFFFF;       
	long minLong = 0x8000000000000000;  
	unsigned long maxULong = 0xFFFFFFFFFFFFFFFF;
	unsigned long minULong = 0x0;
	float S = 2.345f;     
	float negativeS = -S; 
	float positiveInf = S / 0;
	float negativeInf = negativeS / 0;
	float negativeInd = negativeInf + positiveInf;
	char* pointer =  &engChar+3;
	
	wchar_t* pointer1 = &testChar2+3;
	short* pointer2 = &X+3;
	int* pointer3 = &Y+3;
	float* pointer4 = &S+3;

	cout << "Введите ваш порядковый номер: ";
	cin >> n;

	cout << negativeInf << S;
	
	char(*f[])(char) = { f1, f2 };

	

	x = n + 9;
	y = n + 10;
	z = n + 11;
	s = n + 1.0;


	return 0;
}



