#include "stdafx.h"
#include <iostream>
#include <locale>
//#include <cwchar>

#include "Rules.h"
#include "Errors.h"
#include "Parm.h"

#include "In.h"
#include "Log.h"
#include "LexAnalyse.h"
#include "MFST.h"
#include "MFST_TRACE.h"
#include "PolishNotation.h" 
#include "SemAnalyse.h"
#include "CodeGenerator.h"
#define FILE_PATH_ASM "D:/Coursach/LNZ-2018/ASM/ASM.asm"

int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "");
	bool Param_Ok = false;
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		Param_Ok = true;
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест:", "без ошибок ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);

		//этап лексического анализа
		In::ArrWord arr(4096);
		arr.Split((char*)in.text);
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		IT::IdTable idtable = IT::Create(TI_MAXSIZE);
		
		if (!Lex::LexicalAnalyse(arr, lextable, idtable, log))
		{
			//этап синтаксического анализа
			MFST::Mfst mfst(lextable, GRB::greibach);
			std::cout << "Lexical Analise is done.\n";
			if (mfst.start(log))
			{
				mfst.printrules(log);
				/*GRB::Print_Rules(GRB::greibach);*/
				std::cout << "Syntaxis Analise is done.\n";
				//этап семантического анализа
				if (!SA::SemanticAnalyse(log, lextable, idtable))
				{
					std::cout << "Semantic Analise is done.\n";
					//Генерация
					CG::ConstSegment CnstS(idtable.size);
					CG::DataSegment Data(idtable.size);
					CG::CodeSegment Code;
					CG::add(idtable, CnstS);
					CG::add(idtable, Data);
					CG::CodeSegmentGeneration(Code, lextable, idtable);
					CG::startGeneration(FILE_PATH_ASM, CnstS, Data, Code);

				}

			}
		}


	}
	catch (Error::ERROR e)
	{
		if (e.id == 100)
			std::cout << "Параметр -in должен быть задан обязательно!\n";
		else if (e.id == 104)
			std::cout << "Превышена длина входного параметра\n";
		else
		{

			Log::WriteError(log, e);
		}

	}


	if (Param_Ok)
		Log::Close(log);
	return 0;
}


