#pragma once
#include "stdafx.h"
#include "Log.h"
#include "LT.h"
#include "IT.h"
#include <stack>
#include <vector>
#define SEP '@'
#define SEP2 '^'

namespace PN
{
	void start(Log::LOG log, LT::LexTable& lextable, IT::IdTable idtable);
	IT::IDDATATYPE toPolish(std::vector<LT::Entry>& temp, int& pos, LT::LexTable& lextable, IT::IdTable idtable);
}
