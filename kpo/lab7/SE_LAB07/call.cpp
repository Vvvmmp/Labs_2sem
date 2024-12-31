#include "call.h"

using namespace Call;


int _cdecl Call::ccdecl(int x, int y, int z)
{
	return x + y + z;
}

int  _stdcall Call::cstd(int x, int y, int& z)
{
	return x * y * z;
}

int  _fastcall Call::cfst(int x, int y, int z, int k)
{
	return x + y + z + k;
}