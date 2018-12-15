#include "stdafx.h"
#include "string.h"
#include <iostream>
#include "FST.h"


namespace FST
{

	RELATION::RELATION(char c, short ns) { symbol = c; nnode = ns; }

	NODE::NODE() { n_relation = NULL; RELATION* relations = NULL; }
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* current = &rel;
		relations = new RELATION[n];
		for (int i = 0; i < n; i++) relations[i] = current[i];
	}


	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;
		nstates = ns;
		NODE* current = &n;
		nodes = new NODE[ns];
		for (int i = 0; i < ns; i++) nodes[i] = current[i];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short)*nstates);
		rstates[0] = 0;
		position = -1;
	}

	bool step(FST& fst, short* &cur_states)
	{
		bool rc = false;
		std::swap(cur_states, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (cur_states[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				}
		}
		return rc;
	}

	bool execute(FST& fst)
	{
		bool rc = true;
		short* cur_states = new short[fst.nstates];
		memset(cur_states, 0xff, sizeof(short)*fst.nstates);
		short str_len = strlen(fst.string);
		for (short i = 0; i < str_len && rc; i++)
		{
			fst.position++;
			rc = step(fst, cur_states);
		}
		return (rc ? (fst.rstates[fst.nstates - 1] == str_len) : rc);
	}
	void TOKEN::SetLexeme(char* lexeme)
	{
		this->fst.position = -1;
		this->fst.string = lexeme;
		this->fst.rstates[0] = 0;
	}
};