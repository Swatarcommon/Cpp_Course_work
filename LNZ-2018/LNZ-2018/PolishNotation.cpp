#include "stdafx.h"
#include <stdlib.h>
#include "PolishNotation.h"




namespace PN
{
	/*void start(Log::LOG log, LT::LexTable& lextable, IT::IdTable idtable)
	{
	for (int i = 0; i < lextable.size; i++)
	if (lextable.table[i].lexema == LEX_EQUAL)
	toPolish(++i, lextable, idtable);
	*log.stream << "" << std::endl;
	for (int i = 0; i < lextable.size; i++)
	{

	if (lextable.table[i].sn != lextable.table[i - 1].sn && lextable.table[i].sn>0)
	{

	Log::WriteLine(log, "\n", "");
	*log.stream << lextable.table[i].sn << " ";
	}
	if(lextable.table[i].sn>0)
	*log.stream << lextable.table[i].lexema;
	}
	}*/

	IT::IDDATATYPE toPolish(std::vector<LT::Entry>& temp, int& pos, LT::LexTable& lextable, IT::IdTable idtable)
	{
		IT::IDDATATYPE forreturn;
		LT::Entry last = lextable.table[pos];
		int forpos = pos;
		char current = lextable.table[pos].lexema;
		char next = lextable.table[pos + 1].lexema;
		int curpos = pos;
		int commas = 0; int thesis_commas = 0; bool function = false; int func = 0;
		std::stack<LT::Entry> stack;
		while (current != LEX_SEMICOLON)
		{
			switch (current)
			{
			case LEX_COMMA:
				thesis_commas++;
				commas++;
				break;
			case LEX_ID: case LEX_NUMBER: case LEX_LITERAL:
				lextable.table[curpos++] = lextable.table[pos];
				break;
			case LEX_LEFTHESIS:
				if (lextable.table[pos - 1].lexema == 'i')
				{
					if (idtable.table[lextable.table[pos - 1].idxTI].idtype != IT::F)
						throw ERROR_THROW_IN(306, lextable.table[curpos].sn, -1);
				}
				else if (lextable.table[pos - 1].lexema == 'z' || lextable.table[pos - 1].lexema == 'l')
					throw ERROR_THROW_IN(306, lextable.table[curpos].sn, -1);
				thesis_commas++;
				stack.push(lextable.table[pos]);

				if (idtable.table[lextable.table[curpos - 1].idxTI].idtype == IT::F)
					function = true;
				break;
			case LEX_RIGHTHESIS:
				thesis_commas++;
				if (function == true)
				{

					lextable.table[curpos].lexema = SEP;
					lextable.table[++curpos].lexema = commas + 1;
					thesis_commas -= 2;
					curpos++;
					function = false;
					commas = 0;

				}
				while (!stack.empty() && stack.top().lexema != LEX_LEFTHESIS)
				{
					lextable.table[curpos++] = stack.top();

					stack.pop();
				}
				if (stack.size() != 0)
					stack.pop();

				break;
			case LEX_PLUS: case LEX_MINUS: case LEX_STAR: case LEX_DIRSLASH:

				if (current == LEX_MINUS)
					if (lextable.table[pos - 1].lexema == LEX_EQUAL ||
						lextable.table[pos - 1].lexema == LEX_LEFTHESIS ||
						lextable.table[pos - 1].lexema == LEX_PRINT ||
						lextable.table[pos - 1].lexema == LEX_RETURN ||
						lextable.table[pos - 1].lexema == LEX_PLUS ||
						lextable.table[pos - 1].lexema == LEX_STAR ||
						lextable.table[pos - 1].lexema == LEX_DIRSLASH)

						/*lextable.table[pos - 1].lexema == LEX_COMMA*/
					{
						lextable.table[pos].lexema = '!';
						lextable.table[pos].pr = LT::UM;


					}
				while (!stack.empty() && stack.top().pr >= lextable.table[pos].pr)
				{
					lextable.table[curpos++] = stack.top();
					stack.pop();
				}
				stack.push(lextable.table[pos]);
				break;
			}

			if (next == LEX_SEMICOLON)
			{
				while (!stack.empty() && stack.top().pr >= lextable.table[pos].pr)
				{
					lextable.table[curpos++] = stack.top();
					stack.pop();
				}


				while (thesis_commas > 0)
				{
					lextable.table[curpos++].lexema = SEP2;
					thesis_commas--;
				}


			}
			current = lextable.table[++pos].lexema;
			next = lextable.table[pos + 1].lexema;
		}
		int funcIdxTI; LT::Entry forfunc; static std::vector<int> vec;
		forreturn = idtable.table[lextable.table[forpos].idxTI].iddatatype;
		forfunc.lexema = '_';
		for (forpos; lextable.table[forpos].lexema != SEP2 && lextable.table[forpos].lexema != ';'; forpos++)
		{

			if (idtable.table[lextable.table[forpos].idxTI].idtype == IT::F)
			{
				if (strcmp(idtable.table[lextable.table[forpos].idxTI].id, "strcon") != 0
					&& strcmp(idtable.table[lextable.table[forpos].idxTI].id, "copystr") != 0
					&& strcmp(idtable.table[lextable.table[forpos].idxTI].id, "sqroot") != 0
					&& strcmp(idtable.table[lextable.table[forpos].idxTI].id, "sqr") != 0
					////&& strcmp(idtable.table[lextable.table[forpos].idxTI].id, "strnum") != 0
					&& (std::find(vec.begin(), vec.end(), lextable.table[forpos].idxTI) == vec.end()))
				{
					strcat(idtable.table[lextable.table[forpos].idxTI].id, "_proc");
					vec.push_back(lextable.table[forpos].idxTI);

				}
				funcIdxTI = lextable.table[forpos].idxTI;
			}
			if (lextable.table[forpos].lexema == '@')
			{

				temp.push_back(forfunc);
				temp[temp.size() - 1].idxTI = funcIdxTI;

			}

			temp.push_back(lextable.table[forpos]);
		}
		LT::Entry comma;
		comma.lexema = ';';


		temp.push_back(comma);
		return forreturn;
	}
}
