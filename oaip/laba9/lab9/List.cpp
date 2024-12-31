#include "List.h"
bool Object::Insert(char* nameproduct, char* price, char* quantity, int percent)           // ������� � ������
{
	bool rc = 0;
	if (Head == NULL) // ���� ������  ����
	{
		Head = new Element(NULL, nameproduct, price, quantity, percent, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, nameproduct, price, quantity, percent, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(char* price)    // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (strcmp(rc->Price, price)))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, int))     // ����� // �������� ������� ��� ���������
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->NameProduct, e->Price, e->Quantity, e->Percent); // ������������� ����������� ��������� ������� ��� ������ ��������
		e = e->GetNext(); // ��������� ��������� �� ��������� ������� � ������� ������
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, int), Element* e)
{
	f(e->NameProduct, e->Price, e->Quantity, e->Percent);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // ������� �� ������
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(char* owner)      // ������� �� ��������
{
	return Delete(Search(owner));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object()); // ������������� ����� ������������ � ���������� ������ ��� ������, � ����� ���������� �������� ������ ������������
}

int Object::CountList()
{
	Element* p = Head;
	int counter = 0;
	while (p) {
		p = p->Next;
		counter++;
	}
	return counter;
}
bool Object::DeleteList()
{
	while (Head) {
		Element* p = Head;
		Head = Head->Next;
		delete[]p;
	}
	return Head == NULL ? 1 : 0;
}




