#include <iostream>
#include <Windows.h>
#include "Dictionary.h"

namespace Dictionary
{
	Instance Create(const char name[DICTNAMEMAXSIZE], int size)
	{
		//TEST_CREATE_01(name);
		//TEST_CREATE_02(size);
		if (strlen(name) > DICTNAMEMAXSIZE)
		{
			throw THROW01;
		}
		if (size > DICTMAXSIZE)
		{
			throw THROW02;
		}
		Instance* instance = new Instance;
		strcpy_s(instance->name, name);
		instance->maxsize = size;
		instance->size = 0;
		instance->dictionary = new Entry[size];
		return *instance;
	};
	void AddEntry(Instance& inst, Entry ed)
	{
		//TEST_ADDENTRY_03(inst.maxsize);
		//for (int i = 0; i < inst.size; i++)
		//{
		//	TEST_ADDENTRY_04(inst.dictionary[i].id);
		//}
		if (inst.maxsize == inst.size)
		{
			throw THROW03;
		}
		for (int i = 0; i < inst.maxsize; i++)
		{
			if (ed.id == inst.dictionary[i].id)
			{
				throw THROW04;
			}
		}
		inst.dictionary[inst.size] = ed;
		inst.size++;
	};
	void DelEntry(Instance& inst, int id)
	{
		bool flag = 0;
		for (int i = 0; i < inst.size; i++)
		{
			if (inst.dictionary[i].id == id) {
				flag = true;
				for (int j = i; j < inst.maxsize - 1; j++)
				{
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				inst.size--;
				return;
			}
		}
		//TEST_DELENTRY_06(flag);
		throw THROW06;
	};

	void UpdEntry(Instance& inst, int id, Entry new_ed)
	{
		bool flag = 0;
		for (int i = 0; i < inst.size; i++)
		{
			//TEST_UPDENTRY_08(inst.dictionary[i].id);
			if (inst.dictionary[i].id == id)
			{
				flag = true;
				if (id == new_ed.id)
				{
					throw THROW08;
				}
				inst.dictionary[i] = new_ed;
				return;
			}
		}
		//TEST_UPDENTRY_07(flag);
		throw THROW07;
	};

	Entry GetEntry(Instance inst, int id)
	{
		for (int i = 0; i < inst.size; i++)
		{
			if (id == inst.dictionary[i].id)
			{
				return inst.dictionary[i];
			}
		}
		//TEST_GETENTRY_05();
		throw THROW05;
	};
	void Print(Instance d)
	{
		std::cout << "\t\t\t" << d.name << "\t\t\t" << std::endl;
		for (int i = 0; i < d.size; i++)
		{
			std::cout << d.dictionary[i].id << ' ';
			std::cout << d.dictionary[i].name << std::endl;
		}
	};
	void Delete(Instance& d)
	{
		delete[] d.dictionary;
		//delete &d;
	};
}