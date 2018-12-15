#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstddef>
#include "IT.h"
namespace IT
{
	IdTable Create(int size)
	{
		IdTable* a = new IdTable;
		a->maxsize = size;
		a->size = 0;
		a->table = new Entry[size];
		return *a;
	}
	Entry Getentry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}

	void Add(IdTable&  idtable, Entry entry)
	{
		idtable.table[idtable.size++] = entry;
	}
	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		int i;
		bool fl = false;
		for (i = idtable.size; i >= 0; i--)
		{
			if (std::strcmp(idtable.table[i].id, id) == NULL)
			{
				fl = true;
				return i;
			}

		}
		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete &idtable;
	}
}