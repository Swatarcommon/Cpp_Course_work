#include "stdafx.h"
#include "LT.h"

namespace LT
{
	LexTable Create(int size)
	{
		LexTable* a = new LexTable;
		a->maxsize = size;
		a->size = 0;
		a->table = new Entry[size];
		return *a;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		lextable.table[lextable.size++] = entry;
	}

	Entry Getentry(LexTable& lextable, int n)
	{
		return lextable.table[n];
	}

	void Delete(LexTable& lextable)
	{
		delete &lextable;
	}
}