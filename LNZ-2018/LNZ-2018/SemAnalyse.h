#pragma once
#include "IT.h"
#include "LT.h"
#include "Log.h"


namespace SA
{
	bool ParamCheck(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable);
	bool Typecheck(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable);
	bool FuncRet(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable);
	bool DoNotChangeParam(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable);
	int SemanticAnalyse(Log::LOG& log, LT::LexTable lextable, IT::IdTable idtable);
}
