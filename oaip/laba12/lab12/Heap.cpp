#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AAA::print()
{
	cout << x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*)) // �������� ����
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)  // ��������� ������ ��������
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix) // ��������� ������� ��������
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix) // ��������� ������������� ����
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j) // ������ �������
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix) //��������������� ����
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}


	void Heap::insert(void* x) // ��������� ������� � ����
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax() // ������� ������������ �������� �� ����
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}



	void Heap::scan(int i) const     //����� �������� ��������� �� �����
	{
		int probel = 20;
		cout << '\n';
		if (size == 0)
			cout << "���� �����";
		for (int u = 0, y = 0; u < size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		cout << '\n';
	}

	void Heap::extractI() // �������� i-�� ��������
	{
		int i;
		cout << "������� i:"; 
		cin >> i;
		cout << endl;
		if (!isEmpty()) // ��������, ��� ���� �� �����
		{
			for (int j = i; j < size - 1; j++) // ����� ��������� ����� i �� ���� ������� �����
			{
				storage[j] = storage[j + 1];
			}
			size--; // ���������� ������� ���� �� 1
			heapify(0); // �������������� ������� ����
		}
	}

	void Heap::extractMin() // �������� ������������
	{
		int min = 100, a; // ������������� ���������� min � a
		int** A = (int**)storage; // ���������� ��������� storage � ���� int**
		void* rc = nullptr; // ������������� ��������� rc

		if (!isEmpty()) // ��������, ��� ���� �� �����
		{
			for (int i = 0; i < size; i++) // ����� ������������ �������� � ����
			{
				if (*A[i] < min) // ���� ������� ������� ������ min, ��������� min � ���������� ������ a
				{
					min = *A[i];
					a = i;
				}
			}
			int i = parent(a); // ���������� ������� �������� �������� a
			for (int i = a; i < size - 1; i++) // ����� ��������� ����� a �� ���� ������� �����
			{
				storage[i] = storage[i + 1];
			}
			size--; // ���������� ������� ���� �� 1
			heapify(0); // �������������� ������� ����
		}
	}

	void Heap::unionHeap(void* x) // ����������� ���� ��� � ����
	{
		int i;

		for (i = 0; i < size - 1; i++) // ����� ��������� ���� �� ���� ������� �����
		{
			storage[i] = storage[i + 1];
		}
		heapify(0); // �������������� ������� ����

		storage[i = ++size - 1] = x; // ���������� ������ �������� x � ����� ����
		while (i > 0 && isLess(storage[parent(i)], storage[i])) // ���� �� ��������� ������ � �������� �������� ����, ��������� ������������ ���������
		{
			swap(parent(i), i);
			i = parent(i);
		}
	}

	int Heap::sumVertices() // ������� ��� �������� ����� ���� ������ ����  ��� ������� 10
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += *((int*)storage[i]);
		}
		return sum; // ���������� �����
	}

	int Heap::countLeaves() // ���������� �������     ��� ������� 7
	{
		// �� ������ ����� ������� �������� ��� ��������
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (left(i) == -1 && right(i) == -1) // ��������� ���������� � ������, � ������� ��������
			{
				count++;
			}
		}
		return count;
	}

	int Heap::sumLeaves() // ����� �������� �������    ��� ������� 16
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (left(i) == -1 && right(i) == -1)
			{
				sum += *((int*)storage[i]);
			}
		}

		return sum;
	}
}




