#include "stdafx.h"
#include "IT.h"
#include <stack>
#include "SemAnalyse.h"

namespace SA
{
	bool ParamCheck(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable)
	{
		std::stack<LT::Entry> call;
		std::stack<LT::Entry> called;
		bool error = false; bool er301 = false;
		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].idxTI != TI_NULLIDX && idtable.table[lextable.table[i].idxTI].idtype == IT::F)
			{
				int j = idtable.table[lextable.table[i].idxTI].idxfirstLE + 1;
				if (lextable.table[i + 1].lexema == LEX_LEFTHESIS)
				{
					i++;
					while (lextable.table[i].lexema != LEX_RIGHTHESIS)
					{
						if (lextable.table[i].lexema == LEX_ID || lextable.table[i].lexema == LEX_NUMBER || lextable.table[i].lexema == LEX_LITERAL)
							call.push(lextable.table[i]);
						i++;

					}
					while (lextable.table[j].lexema != LEX_RIGHTHESIS)
					{
						if (lextable.table[j].lexema == LEX_ID || lextable.table[j].lexema == LEX_NUMBER || lextable.table[j].lexema == LEX_LITERAL)
							called.push(lextable.table[j]);
						j++;
						if (lextable.table[j].lexema == LEX_STRING || lextable.table[j].lexema == LEX_INTEGER)
							j++;
					}

					while (!called.empty() && !call.empty())
					{
						if (idtable.table[call.top().idxTI].iddatatype != idtable.table[called.top().idxTI].iddatatype)
						{
							Log::WriteError(log, Error::geterrorin(300, lextable.table[i].sn, -1));
							error = true;
						}
						call.pop();
						called.pop();
					}
					if (call.size() != called.size() && !er301)
					{
						Log::WriteError(log, Error::geterrorin(301, lextable.table[i].sn, -1));
						er301 = true;
						error = true;
					}
				}
			}
		}
		return error;
	}
	bool Typecheck(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable)
	{
		int buf = 0; bool str = false; bool boolean = false; bool operation = false; bool number = false; bool equal = false; bool operation_plus = false;
		bool er302 = false; bool er303 = false; bool er304 = false; bool er307 = false; bool error = false;
		for (int i = 0; i < lextable.size; i++)
		{

			if (lextable.table[i].lexema == '=' || lextable.table[i].lexema == 'r' || lextable.table[i].lexema == 'p')
			{
				if (lextable.table[i].lexema == '=')
				{
					buf = i - 1;
					equal = true;
				}
				i++;
				while (lextable.table[i].lexema != ';')
				{
					if (lextable.table[i].lexema == '*' || lextable.table[i].lexema == '-' || lextable.table[i].lexema == '\/')
						operation = true;
					if (lextable.table[i].lexema == '+')
						operation_plus = true;
					if (idtable.table[lextable.table[i].idxTI].iddatatype == IT::BOOL && idtable.table[lextable.table[i].idxTI].idtype != IT::F)
						boolean = true;
					if (idtable.table[lextable.table[i].idxTI].iddatatype == IT::STR && idtable.table[lextable.table[i].idxTI].idtype != IT::F)
						str = true;
					if (idtable.table[lextable.table[i].idxTI].iddatatype == IT::INT && idtable.table[lextable.table[i].idxTI].idtype != IT::F)
						number = true;
					if (idtable.table[lextable.table[i].idxTI].value.vint == 2147483647)
					{
						Log::WriteError(log, Error::geterrorin(307, lextable.table[i].sn, -1));
						error = true;
						er307 = true;

					}
					if (idtable.table[lextable.table[i].idxTI].iddatatype != idtable.table[lextable.table[buf].idxTI].iddatatype && lextable.table[i].idxTI != -1 && equal && !er302)
					{


						Log::WriteError(log, Error::geterrorin(302, lextable.table[i].sn, -1));
						er302 = true;
						error = true;

					}
					if(operation && boolean && !er304)
					{
						Log::WriteError(log, Error::geterrorin(304, lextable.table[i].sn, -1));
						er304 = true;
						error = true;
					}
					if (operation && str && !er303)
					{
						Log::WriteError(log, Error::geterrorin(303, lextable.table[i].sn, -1));
						er303 = true;
						error = true;
					}
					if (number && str && (operation || operation_plus) && !er304)
					{
						Log::WriteError(log, Error::geterrorin(304, lextable.table[i].sn, -1));
						er304 = true;
						error = true;
					}
					i++;
				}
				operation_plus = false;
				number = false;
				operation = false;
				str = false;
				equal = false;
				er302 = er303 = er304 = er307 = false;
			}

		}
		return error;
	}

	bool FuncRet(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable)
	{
		int check; bool error = false;
		for (int i = 27; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == 'f')
			{
				check = i + 1;
				while (lextable.table[i].lexema != 'r' && lextable.table[i].lexema != '}')
				{
					i++;
				}
				if (idtable.table[lextable.table[check].idxTI].iddatatype != idtable.table[lextable.table[i + 1].idxTI].iddatatype)
				{
					Log::WriteError(log, Error::geterrorin(305, lextable.table[i].sn, -1));
					error = true;
				}
			}

		}
		return error;
	}
	bool DoNotChangeParam(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable)
	{
		bool error = false;
		for (int i = 38; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == '=' && idtable.table[lextable.table[i - 1].idxTI].idtype == IT::P  && idtable.table[lextable.table[i - 1].idxTI].iddatatype == IT::STR)

			{
				Log::WriteError(log, Error::geterrorin(308, lextable.table[i].sn, -1));
				error = true;
			}
		}
		return error;
	}
	int SemanticAnalyse(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable)
	{
		int error = 0;
		error += FuncRet(log, lextable, idtable);
		error += Typecheck(log, lextable, idtable);
		error += ParamCheck(log, lextable, idtable);
		error += DoNotChangeParam(log, lextable, idtable);
		return error;
	}
}
