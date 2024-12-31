#pragma once
#pragma once
#include <iostream>
struct Element                   // ������� ������ 
{
	Element* Prev;                // ��������� �� ���������� ������� 
	Element* Next;                // ��������� �� ��������� ������� 
	char NameProduct[50];
	char Price[50];
	char Quantity[50];
	int Percent;
	Element(Element* prev, char* nameproduct, char* price, char* quantity, int percent, Element* next) // ����������� ��� �������� ��������
	{
		Prev = prev;
		strcpy_s(NameProduct, nameproduct);
		strcpy_s(Price, price);
		strcpy_s(Quantity, quantity);
		Next = next;
	}
	Element* GetNext()            // �������� ���������
	{
		return Next;
	};
	Element* GetPrev()            // �������� ����������  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // ���� ���������� ������� 
{
	Element* Head;                 // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // �������� ������ ������� ������
	{
		return Head;
	};
	Element* GetLast();            // �������� ��������� ������� ������
	Element* Search(char*);   // �����  ������ ������� �� ������ 
	bool Insert(char*, char*, char*, int);       // �������� ������� � ������
	bool InsertEnd(char*, char*, char*, int);    // �������� � ����� 
	bool Delete(Element* e);       // ������� �� ������ �������� 
	bool Delete(char*);       // ������� ������ �� ������
	bool DeleteList();		    // �������� ������ 
	void PrintList(void(*f)(char*, char*, char*, int));
	void PrintList(void(*f)(char*, char*, char*, int), Element*);
	int CountList();
	bool  DeleteDouble();
};
Object Create();


