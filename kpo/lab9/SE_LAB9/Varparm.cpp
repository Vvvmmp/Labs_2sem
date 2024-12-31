#include <iostream>
#include "Varparm.h"

using namespace std;

namespace Varparm {

	int ivarparm(int a, ...)
	{
		int* p = &a;
		int counter = 0;
		int result = 1;
		while (counter <= *p)
		{
			result *= p[counter];
			counter++;
		}
		return result;
	}

	int svarparm(short a, ...)
	{
		short* p = &a;
		short result = 0;
		for (int i = 0; i < *p; i++)
		{
			if (p[i] > result)
			{
				result = p[i];
			}
		}
		return result;
	}

	int fvarparm(float a, ...)
	{
		va_list args;
		va_start(args, a);

		double sum = 0.0;
		float value = a;

		while (value != FLT_MAX)
		{
			sum += value;
			value = va_arg(args,double);
		}

		va_end(args);

		return sum;
	}

	int dvarparm(double a, ...)
	{
		va_list args;
		va_start(args, a);

		double sum = 0.0;
		double value = a;

		while (value != DBL_MAX)
		{
			sum += value;
			value = va_arg(args, double);
		}

		va_end(args);

		return sum;
	}
}




int main()
{
	setlocale(0, "");

	Varparm::ivarparm(1,5);
	Varparm::svarparm(1,5);
	Varparm::fvarparm(FLT_MAX);
	Varparm::dvarparm(DBL_MAX);

	Varparm::ivarparm(2,5, 6);
	Varparm::svarparm(2, 5, 6);
	Varparm::fvarparm(5.0, FLT_MAX);
	Varparm::dvarparm(5.0, DBL_MAX);

	Varparm::ivarparm(3, 5, 6, 7);
	Varparm::svarparm(3, 5, 6, 7);
	Varparm::fvarparm(5.0, 6.0, FLT_MAX);
	Varparm::dvarparm(5.0, 6.0, DBL_MAX);

	Varparm::ivarparm(7, 1, 2, 3, 4, 5, 6, 7);
	Varparm::svarparm(8,1, 2, 3, 4, 5, 6, 7);
	Varparm::fvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, FLT_MAX);
	Varparm::dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, DBL_MAX);

	return 0;
}