#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;


struct stack 
{
	char date;
	int size = 0;
	stack* next;
};

bool check(char a, char b)
{
	if (a == '{')
	{
		if (b == '}')
		{ 
			return 1;
		}
		return 0;
	}
	if (a == '(')
	{
		if (b == ')')
		{
			return 1;
		}
		return 0;
	}
	if (a == '[')
	{
		if (b == ']')
		{
			return 1;
		}
		return 0;
	}
}

void push(stack*& Stack, char date)
{
	stack* buff = new stack;
	buff->date = date;
	buff->next = Stack;
	Stack = buff;
	Stack->size++;
}

void pop(stack*& Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	else 
	{
	stack* buff = new stack;
	buff = Stack;
	Stack = Stack->next;
	delete buff;
	}

}

char top(stack*& Stack)
{
	if (Stack == NULL)
	{
		return 0;
	}
	else
	{
		return Stack->date;
	}
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	stack* Stack = new stack;
	bool correct = 1;
	bool juice = 1;
	string str;
	getline(cin,str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			push(Stack, str[i]);
			juice = 0;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			juice = 0;
			if (Stack->size == 0)
			{
				correct = 0;
				break;
			}
			else if(!check(top(Stack), str[i]))
			{
				correct = 0;
				break;
			}
			else if (check(top(Stack), str[i]))
			{
				pop(Stack);
			}
		}
		else
		{
			continue;
		}
	}
	if (juice)
	{
		cout << "\nсок\n";
	}
	else if (correct)
	{
		cout << "\nскобки расставлены верно\n";
	}
	else
	{
		cout << "\nскобки расставлены не верно\n";
	}
	return 0;
}