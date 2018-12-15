#pragma once
#include "IT.h"
#include "LT.h"
#include "Log.h"
#include <vector>
#define BEFORE_DATA_SECTIONS_ENTRY ".586\n.model flat, stdcall\nincludelib userlib.lib\nincludelib kernel32.lib\nincludelib libucrt.lib"
#define CSMAXSIZE 255


namespace CG
{

	enum INSTRUCTIONTYPE
	{					// Типы инструкций
		PUSH = 0,		// помещение переменной в стек
		FUNC = 2,		// инициализация функции tfi
		RET = 3,		// возврат значения функции: return l/i/expression;
		PRNT = 4,		// вывод : print  l/i/expression;
		ADD = 5,		// +
		ADDSTR = 6,
		DIFF = 7,		// - бинарный
		UDIFF = 8,		// - унарный ( лексема - '!')
		DIV = 9,		// /
		MUL = 10,		// *
		SEM = 11,		// ;
		PARM = 12,		// параметр : (ti,...)
		CALL = 13,		// вызов функции : i(...)
		ENDP = 14,		// конец процедуры : fucn_name ENDP
	};

	struct ConstSegment
	{
		char** Data;
		int size;
		int maxSize;
		ConstSegment(int _size)
		{
			size = 0;
			maxSize = _size + 4;
			Data = new char*[maxSize];
			for (int i = 0; i < maxSize; i++)
				Data[i] = new char[TI_STR_MAXSIZE];
			Data[size++] = BEFORE_DATA_SECTIONS_ENTRY;
			Data[size++] = "\n\nExitProcess PROTO : DWORD\nsqroot PROTO : DWORD\ncopystr PROTO : DWORD, : DWORD\nstrcon PROTO : DWORD, : DWORD\nsqr PROTO : SDWORD\noutstr PROTO : DWORD\noutint PROTO : SDWORD ";
			Data[size++] = "\n.stack 4096\n.const";
			Data[size++] = "\n\toverflow db 'ERROR: VARIABLE OVERFLOW', 0 \n\tnull_division db 'ERROR: DIVISION BY ZERO', 0";

		}
	};
	struct DataSegment
	{
		char** Data;
		int size;
		int maxSize;
		DataSegment(int _size)
		{
			size = 0;
			maxSize = _size + 1;
			Data = new char*[maxSize];
			for (int i = 0; i < maxSize; i++)
				Data[i] = new char[TI_STR_MAXSIZE];
			Data[size++] = "\n.data";
		}
	};
	struct CodeSegment
	{
		char** Data;
		int size;
		int maxSize;
		void add(std::string str);
		CodeSegment()
		{
			size = 0;
			maxSize = CSMAXSIZE;
			Data = new char*[maxSize];
			for (int i = 0; i < maxSize; i++)
				Data[i] = new char[TI_STR_MAXSIZE];
			Data[size++] = "\n.code";
		}
	};



	void add(IT::IdTable& idtable, ConstSegment& cnst);
	void add(IT::IdTable& idtable, DataSegment& dataseg);
	void generateExpression(std::vector<LT::Entry>& tempEntries, CodeSegment& CS, int idxTI, IT::IdTable iT, IT::IDDATATYPE type = IT::INT);
	void	CodeSegmentGeneration(CodeSegment& CS, LT::LexTable l, IT::IdTable& iT);
	std::string	generateInstructions(INSTRUCTIONTYPE t, int idxTI, IT::IdTable iT, IT::IDDATATYPE type = IT::INT, std::string fucn_name = "");
	void endOfFucntion(CodeSegment& CS);
	void startGeneration(const char* file, ConstSegment& CnstS, DataSegment& DS, CodeSegment& CS);

	void print(Log::LOG log, ConstSegment& cnst, DataSegment& dataseg, CodeSegment& codeseg);
}