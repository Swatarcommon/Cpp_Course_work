#pragma once

typedef short GRBALHABET;	// символы алфавита грамматики ( терминалы > 0, нетерминалы < 0) 
#define NS(n)	(Rule::Chain::N(n))
#define TS(n)	(Rule::Chain::T(n))
#define ISNS(n) (GRB::Rule::Chain::isN(n))

namespace GRB
{
	struct Rule		// правило в грамматике Грейбах
	{
		GRBALHABET	nn;		//	нетерминал ( левый символ правила) < 0
		int iderror;		//	идентефикатор диагностического сообщения
		short	size;		//	количество цепочек - правых частей правила
		struct Chain		//	цепочка ( правая часть правила )
		{
			short size;				//	длина цепочки
			GRBALHABET* nt;			//	цепочка терминалов (>0) и нетерминалов (<0)
			Chain() { size = 0; nt = 0; };
			Chain(
				short psize,		//	количество символо в цепочке
				GRBALHABET s, ...	//	символы (терминал или нетерминал)
			);
			char* getCChain(char* b);//	получить правую сторону правила
			static GRBALHABET T(char t) { return  GRBALHABET(t); };	//	Теминал
			static GRBALHABET N(char n) { return -GRBALHABET(n); };	//	Нетерминал
			static bool isT(GRBALHABET s) { return s > 0; };		//	Терминал?
			static bool isN(GRBALHABET s) { return s < 0; };		//	Нетерминал?
			static char alphabet_to_char(GRBALHABET s) { return isT(s) ? char(s) : char(-s); };	// GRBALPHABET -> char
		} *chains;						//	массив цеполчек - правых частей правила
		Rule() { nn = 0x00; size = 0; }
		Rule(

			GRBALHABET pnn,				// нетерминал
			int iderror,				// идентефикатор диагностического сообщения
			short psize,				// количество цепочек - правых частей правила
			Chain c, ...				// множество цепочек - правых частей правила
		);
		char* getCRule(					// получить правило в виде N-> цепочка (для распечатеки)
			char*b,			// буфер
			short nchain	// номер цепочки ( правой части ) в правиле
		);
		short Rule::getNextChain(		// получить следующую за j подходящую цепочку, вернуть ее номер или -1
			GRBALHABET t,			// первый символ цепочки
			Rule::Chain& pchain,	// возвращаемая цепочка
			short j					// номер цепочки
		);
	};
	struct  Greibach			// грамматика ГРейбах
	{
		short size;				// количество правил
		GRBALHABET startN;		// стартовый символ
		GRBALHABET stbottomT;	// дно стека
		Rule* rules;			// множество правил
		Greibach() { short size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(
			GRBALHABET	pstartN,		// стартовый символ
			GRBALHABET  pstbottomT,		// дно стека
			short psize,				// множество правил
			Rule r, ...					// правила
		);
		short getRule(							// получить правило, возвращается номер правила или -1
			GRBALHABET pnn,			// левый символ правила
			Rule& prule				// возвращаемое правило грамматики
		);
		Rule getRule(short n);					// получить правило по номеру
	};
	void Print_Rules(Greibach greibach);
};