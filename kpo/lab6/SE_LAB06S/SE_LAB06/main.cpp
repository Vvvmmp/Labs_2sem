#include <iostream>
#pragma comment(lib, "C:\\labi\\2sem\\kpo\\lab6\\SE_LAB06S\\Debug\\SE_LAB06L.lib")
#include "..\SE_LAB06L\Dictionary.h"


int main()
{
	setlocale(0, "");
	try
	{
		//		int counter = 0;
		//#if defined (TEST_CREATE_01) 
		//		counter++;
		//#if defined (TEST_CREATE_02) 
		//		counter++;
		//#if defined (TEST_ADDENTRY_03) 
		//		counter++;
		//#if defined (TEST_ADDENTRY_04)
		//		counter++;
		//#if defined (TEST_GETENTRY_05) 
		//		counter++;
		//#if defined (TEST_DELENTRY_06)
		//		counter++;
		//#if defined (TEST_UPDENTRY_07) 
		//		counter++;
		//#if defined (TEST_UPDENTRY_08) 
		//		counter++;
		//#if defined (TEST_DICTIONARY) 
		//		counter++;
		//		if (counter > 1) {
		////#error Больше одного макроса в файле SE_LAB05.cpp
		//		}
		//#endif
		//#endif
		//#endif
		//#endif
		//#endif
		//#endif
		//#endif
		//#endif
		//#endif
		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3,"Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" };
		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newentry1 = { 6, "Гурин" };
		Dictionary::UpdEntry(d1, 3, newentry1);
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" },
			s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (char* e)
	{
		std::cout << e << std::endl;
	};
	return 0;
}