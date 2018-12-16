#include "stdafx.h"
#include "LexAnalyse.h"
#include <cstdlib>
#include <iostream>
#include <stack>

#define LENTH_OF_TOKEN_FST_TABLE 22

namespace Lex
{
	void LexTableOut(LT::LexTable lextable, Log::LOG log)
	{
		*log.stream << "" << std::endl;
		for (int i = 27; i < lextable.size; i++)
		{

			if (lextable.table[i].sn != lextable.table[i - 1].sn)
			{

				Log::WriteLine(log, "\n", "");
				*log.stream << lextable.table[i].sn << " ";
			}
			if (lextable.table[i].lexema == LEX_ID || lextable.table[i].lexema == LEX_NUMBER || lextable.table[i].lexema == LEX_LITERAL)
				*log.stream << lextable.table[i].lexema << "[" << lextable.table[i].idxTI << "]";
			else
				*log.stream << lextable.table[i].lexema;
		}
		*log.stream << '\n' << std::endl;
	}
	void IDTableOut(IT::IdTable idtable, Log::LOG log)
	{
		*log.stream << "" << std::endl;
		for (int i = 7; i < idtable.size; i++)
		{
			*log.stream << i << " " << idtable.table[i].id << " " << idtable.table[i].idxfirstLE << std::ends;
			switch (idtable.table[i].iddatatype)
			{
			case IT::INT:
				*log.stream << "integer";
				break;
			case IT::STR:
				*log.stream << "string";
				break;
			case IT::BOOL:
				*log.stream << "bool";
			}

			switch (idtable.table[i].idtype)
			{
			case IT::F: *log.stream << " функция"; break;
			case IT::V: *log.stream << " переменная"; break;
			case IT::P: *log.stream << " параметр"; break;
			case IT::L: *log.stream << " литерал"; break;
			}
			*log.stream << std::endl;
		}
	}



	bool LexicalAnalyse(In::ArrWord mas, LT::LexTable& lextable, IT::IdTable& idtable, Log::LOG log)
	{

		/*strcpy(idtable.table[0].id,"squareroot");
		idtable.table[0].iddatatype = IT::INT;
		idtable.table[0].idtype = IT::F;

		strcpy(idtable.table[1].id, "squareroot_a");
		idtable.table[1].iddatatype = IT::INT;
		idtable.table[1].idtype = IT::P;

		strcpy(idtable.table[2].id, "squareroot_a");
		idtable.table[2].iddatatype = IT::STR;
		idtable.table[2].idtype = IT::F;*/



		FST::TOKEN FstTable[] =
		{
			KeyFunction,
			KeyDeclare,
			KeyMain,
			KeySemicolon,
			KeyComma,
			KeyLBrace,
			KeyRBrace,
			KeyLBracket,
			KeyRBracket,
			PLUS,
			EQUAL,
			DIRSLASH,
			MINUS,
			STAR,
			KeyPrint,
			KeyInteger,
			KeyString,
			KeyBool,
			KeyReturn,
			KeyLT,
			KeyId,
			StringKeyLT,
		};

		bool parametrs = false;
		LT::Entry LexEl;
		IT::Entry IdT;
		memset(IdT.id, NULL, sizeof(IdT.id));
		std::stack<char*> prefix; bool result = false; bool isMain = false;
		int numbfun = 3; int numbskob = 6; int checkLIT; int literals = 0; int Main = 0;  bool error = false;
		prefix.push("");

		for (int i = 0; i < mas.size; i++)
		{
			result = false;
			for (int j = 0; j < LENTH_OF_TOKEN_FST_TABLE ; j++)
			{
				FstTable[j].SetLexeme(mas.arr[i].string);
				if (FST::execute(FstTable[j].fst))
				{
					result = true;
					LexEl.lexema = FstTable[j].token;
					LexEl.sn = mas.arr[i].line;
					LexEl.idxTI = TI_NULLIDX;
					LexEl.pr = LT::NDEF;

					switch (FstTable[j].token)
					{
					case LEX_MAIN:
						Main++;
						isMain = true;
						prefix.push(mas.arr[i].string);
						numbfun++;

						break;
					case LEX_FUNCTION:

						IdT.idtype = FstTable[j].IdType;
						if (mas.arr[i].line > 0)
							numbfun++;

						break;
					case LEX_INTEGER:  case LEX_BOOL: case LEX_STRING:      //Заносит в таблицу лексем, если это Целочисленные, Строковые или Логические

						IdT.iddatatype = FstTable[j].IdDataType;
						if (parametrs)
							IdT.idtype = IT::P;
						else
							IdT.idtype = FstTable[j].IdType;
						break;
					case LEX_LEFTBRACE:
						LexEl.pr = LT::BRACE;
						numbskob++;
						break;
					case LEX_LEFTHESIS:

						if (lextable.table[lextable.size - 1].lexema == LEX_ID)
						{

							parametrs = true; break;
						}
						LexEl.pr = LT::BRACE;
						break;
					case LEX_BRACELET:
						if (!prefix.empty() && prefix.size() != 1)
							prefix.pop();
						numbskob--;
						numbfun--;
						break;
					case LEX_RIGHTHESIS:
						parametrs = false;
						IdT.reset();
						break;
					case LEX_SEMICOLON:
						IdT.reset();
						break;


					
					case LEX_NUMBER:
						/*checkLIT = IT::IsId(idtable, mas.arr[i].string);*/
						checkLIT = TI_NULLIDX;
						for (int j = i; j >= 0; j--)
						{
							if (abs(idtable.table[j].value.vint) == atoi(mas.arr[i].string))
							{
								checkLIT = j;

							}
						}

						if (checkLIT == TI_NULLIDX)
						{

							literals++; char l[20] = "_Lit";
							std::strcat(IdT.id, l);
							std::strcat(IdT.id, _itoa(literals, l, 10));
							/*std::strcpy(IdT.id, mas.arr[i].string);*/
							IdT.idxfirstLE = lextable.size;
							LexEl.idxTI = idtable.size;
							IdT.idtype = IT::L;
							IdT.iddatatype = IT::INT;
							if (lextable.table[i - 1].lexema == '-')
								IdT.value.vint = -atoi(mas.arr[i].string);
							else
								IdT.value.vint = atoi(mas.arr[i].string);
						}
						else
						{
							LexEl.idxTI = checkLIT;
						}
						break;
					case LEX_PLUS: case LEX_MINUS:
						LexEl.pr = LT::PM;
						break;

					case LEX_STAR: case LEX_DIRSLASH:
						LexEl.pr = LT::DS;
						break;
					case LEX_LITERAL:
						/*checkLIT = IT::IsId(idtable, mas.arr[i].string);*/
						checkLIT = TI_NULLIDX;
						for (int j = i; j >= 0; j--)
						{
							if (std::strcmp(idtable.table[j].value.vstr->str, mas.arr[i].string) == NULL)
							{
								checkLIT = j;
								break;
							}
						}
						if (checkLIT == TI_NULLIDX)
						{
							literals++; char l[20] = "_Lit";
							std::strcat(IdT.id, l);
							std::strcat(IdT.id, _itoa(literals, l, 10));
							IdT.idxfirstLE = lextable.size;
							LexEl.idxTI = idtable.size;
							IdT.iddatatype = IT::STR;
							IdT.idtype = IT::L;
							std::strcpy(IdT.value.vstr->str, mas.arr[i].string);
						}
						else
						{

							IdT.idxfirstLE = lextable.size;
							LexEl.idxTI = checkLIT;
						}
						break;
					case LEX_ID:

						if (strlen(mas.arr[i].string) > ID_MAXSIZE)
						{
							Log::WriteError(log, Error::geterrorin(120, mas.arr[i].line, -1));
							mas.arr[i].string[ID_MAXSIZE] = '\0';
						}

						int check = IT::IsId(idtable, mas.arr[i].string);
						/*	if (IdT.idtype == IT::F)
						{
						std::strcat(mas.arr[i].string, "_func");
						}
						int check_func = IT::IsId(idtable, mas.arr[i].string);*/


						if (check != TI_NULLIDX && IdT.idtype == IT::F)
						{
							Log::WriteError(log, Error::geterrorin(121, mas.arr[i].line, -1));
							error = true;
						}
						else if (check == TI_NULLIDX && IdT.idtype == IT::F)
						{
							std::strcpy(IdT.id, mas.arr[i].string);

							IdT.idxfirstLE = lextable.size;
							LexEl.idxTI = idtable.size;
							if (isMain == false)
								prefix.push(mas.arr[i].string);

						}
						/*else if (check != TI_NULLIDX && IdT.idtype == IT::NDEFD)
						{

						LexEl.idxTI = check;

						}*/
						else if (IdT.idtype == IT::P || IdT.idtype == IT::V)
						{

							std::strcpy(IdT.id, prefix.top());
							std::strcat(IdT.id, "_");
							std::strcat(IdT.id, mas.arr[i].string);
							int check = IT::IsId(idtable, IdT.id);
							if (check == TI_NULLIDX)
							{
								IdT.idxfirstLE = lextable.size;
								LexEl.idxTI = idtable.size;
							}
							else
							{
								Log::WriteError(log, Error::geterrorin(122, mas.arr[i].line, -1));
								error = true;
							}


						}
						else if (IdT.idtype == IT::NDEFD)
						{
							int check1 = IT::IsId(idtable, mas.arr[i].string);
							if (numbfun > numbskob && isMain == false)
							{
								prefix.pop();
								numbfun--;
							}
							std::strcpy(IdT.id, prefix.top());
							std::strcat(IdT.id, "_");
							std::strcat(IdT.id, mas.arr[i].string);
							int check = IT::IsId(idtable, IdT.id);
							if (check == TI_NULLIDX && check1 == TI_NULLIDX)
							{
								Log::WriteError(log, Error::geterrorin(124, mas.arr[i].line, -1));
								error = true;
							}
							else if (check != TI_NULLIDX && (mas.arr[i + 1].string[0] != '(' || check1 == TI_NULLIDX))
								LexEl.idxTI = check;
							else if (check1 != TI_NULLIDX && mas.arr[i + 1].string[0] == '(')
								LexEl.idxTI = check1;
							else
							{
								Log::WriteError(log, Error::geterrorin(124, mas.arr[i].line, -1));
								error = true;
							}

							IdT.reset();
						}

						break;
					}break;
				}
			}
			if (Main > 1)
			{
				throw ERROR_THROW(126, mas.arr[i].line, -1);
			}
			if (!result)
			{
				Log::WriteError(log, Error::geterrorin(123, mas.arr[i].line, -1));
				error = true;
			}
			if (strcmp(IdT.id, "") != NULL)
			{
				IT::Add(idtable, IdT);
				IdT.reset();
			}
			LT::Add(lextable, LexEl);

		}
		if (Main == 0)
		{
			throw ERROR_THROW(125, mas.arr[i].line, -1);
		}


		if (!error)
		{
			LexTableOut(lextable, log);
			IDTableOut(idtable, log);
		}

		return error;
	}
}

