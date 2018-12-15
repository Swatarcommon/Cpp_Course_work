#include "stdafx.h"
#include "GRB.h"
#include <iostream>
#include <iomanip>
namespace GRB
{
	Rule::Chain::Chain(short psize, GRBALHABET s, ...)
	{
		nt = new GRBALHABET[size = psize];
		int* p = (int*)&s;
		for (short i = 0; i < psize; i++)
			nt[i] = (GRBALHABET)p[i];
	}
	Rule::Rule(GRBALHABET pnn, int piderror, short psize, Chain c, ...)
	{
		nn = pnn;
		iderror = piderror;
		chains = new Chain[size = psize];
		Chain* p = &c;
		for (int i = 0; i < size; i++) chains[i] = p[i];
	};
	Greibach::Greibach(GRBALHABET pstartN, GRBALHABET pstbottom, short psize, Rule r, ...)
	{
		startN = pstartN;
		stbottomT = pstbottom;
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i = 0; i < size; i++) rules[i] = p[i];
	};
	short Greibach::getRule(GRBALHABET pnn, Rule& prule)
	{
		short rc = -1;
		short k = 0;
		while (k < size && rules[k].nn != pnn) k++;
		if (k < size) prule = rules[rc = k];
		return rc;
	};
	Rule Greibach::getRule(short n)
	{
		Rule rc;
		if (n < size) rc = rules[n];
		return rc;
	};
	char* Rule::getCRule(char* b, short nchain)
	{
		char bchain[200];
		b[0] = Chain::alphabet_to_char(nn); b[1] = '-'; b[2] = '>'; b[3] = 0x00;
		chains[nchain].getCChain(bchain);
		strcat_s(b, sizeof(bchain) + 5, bchain);
		return b;
	};
	short Rule::getNextChain(GRBALHABET t, Rule::Chain& pchain, short j)
	{
		short rc = -1;
		while (j < size && chains[j].nt[0] != t) ++j;
		rc = (j < size ? j : -1);
		if (rc >= 0) pchain = chains[rc];
		return rc;
	};
	char* Rule::Chain::getCChain(char* b)
	{
		for (int i = 0; i < size; i++) b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	};
	void Print_Rules(Greibach greibach)
	{
		for (int i = 0; i < greibach.size; i++)
		{
			std::cout << i + 1 << "." << (char)-greibach.rules[i].nn << "->";
			for (int k = 0; k < greibach.rules[i].size; k++)
			{
				if (k == 0)
					std::cout << std::setw(2) << k + 1 << ") ";
				else
					std::cout << std::setw(10) << k + 1 << ") ";
				for (int m = 0; m < greibach.rules[i].chains[k].size; m++)
					std::cout << (char)((greibach.rules[i].chains[k].nt[m] > 0) ? greibach.rules[i].chains[k].nt[m] : -greibach.rules[i].chains[k].nt[m]);
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
}