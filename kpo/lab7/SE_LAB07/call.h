#include <iostream>

namespace Call 
{
	int  _cdecl ccdecl(int x, int y, int z);
	

	int  _stdcall cstd(int x, int y, int& z);
	

	int  _fastcall cfst(int x, int y, int z, int k);
}