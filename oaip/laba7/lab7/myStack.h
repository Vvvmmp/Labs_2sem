#pragma once

struct Stack
{
	int data; //�������������� �������
	Stack* next; //��������� �� ��������� �������
	Stack* before; //��������� �� ���������� �������
};

void show(Stack*& myStk);
char pop(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void clear(Stack*& myStk);
void DeleteFirstPositiveElement(Stack*& myStk);