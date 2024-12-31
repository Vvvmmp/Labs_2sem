#pragma once
#pragma once
#include <iostream>
struct Element                   // Ёлемент списка 
{
	Element* Prev;                // указатель на предыдущий элемент 
	Element* Next;                // указатель на следующий элемент 
	char NameProduct[50];
	char Price[50];
	char Quantity[50];
	int Percent;
	Element(Element* prev, char* nameproduct, char* price, char* quantity, int percent, Element* next) // конструктор дл€ создани€ элемента
	{
		Prev = prev;
		strcpy_s(NameProduct, nameproduct);
		strcpy_s(Price, price);
		strcpy_s(Quantity, quantity);
		Next = next;
	}
	Element* GetNext()            // получить следующий
	{
		return Next;
	};
	Element* GetPrev()            // получить предыдущий  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // Ѕлок управлени€ списком 
{
	Element* Head;                 // указатель на начало списка
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // получить первый элемент списка
	{
		return Head;
	};
	Element* GetLast();            // получить последний элемент списка
	Element* Search(char*);   // найти  первый элемент по данным 
	bool Insert(char*, char*, char*, int);       // добавить элемент в начало
	bool InsertEnd(char*, char*, char*, int);    // добавить в конец 
	bool Delete(Element* e);       // удалить по адресу элемента 
	bool Delete(char*);       // удалить первый по данным
	bool DeleteList();		    // очистить список 
	void PrintList(void(*f)(char*, char*, char*, int));
	void PrintList(void(*f)(char*, char*, char*, int), Element*);
	int CountList();
	bool  DeleteDouble();
};
Object Create();


