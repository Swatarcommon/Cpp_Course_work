#pragma once
#include "GRB.h"
#include "LT.h"
#include "Log.h"
#include <stack>

#define ERROR_MAXSIZE_MASSAGE 255
#define MFST_DIAGN_MAXSIZE (2*ERROR_MAXSIZE_MASSAGE)
#define MFST_DIAGN_NUMBER 3
typedef std::stack<short>  MFSTSTSTACK;
namespace MFST
{

	struct MfstState					// состояние автомата (для сохранения)
	{
		short lenta_position;			// позиция на ленте
		short nrule;					// номер текущего правила
		short nrulechain;				// номер текущей цепочки, текущего правила
		MFSTSTSTACK st;					// стек автомата
		MfstState();
		MfstState(
			short pposition,	// позиция на ленте
			MFSTSTSTACK pst,	// стек автомата
			short pnrulechain	// номер текущей цепочки, текущего правила
		);
		MfstState(
			short pposition,	// позиция на ленте
			MFSTSTSTACK pst,	// стек автомата	
			short pnrulem,		// номет текущего правила 
			short pnrulechain	// номер текущей цепочки, текущего правила
		);
	};
	struct  Mfst						// магазинный автомат
	{
		enum RC_STEP {					// код возврата функции step
			NS_OK,			// найдено правило и цепочка, цепочка записана в стек
			NS_NORULE,		// не найдено правило грамматики (ошибка в грамматике)
			NS_NORULECHAIN,	// не найдена подходящая цепочка правила (ошибка в исходном коде)
			NS_ERROR,		// неизвестный нетерминальный символ грамматики
			TS_OK,			// тек. символ ленты == вершине стека, продвинулась лента, рор стека
			TS_NOK,			// тек. символ ленту != вершине стека, восстановленно состояние
			LENTA_END,		// текущая позиция ленту >= lenta_size
			SURPRISE		// неожиданный код возврата (ошибка в step)
		};
		struct  MfstDiagnosis			// диагностика
		{
			short lenta_position;		// позиция на лентке
			RC_STEP rc_step;			// код завершения шага
			short nrule;				// номер правила
			short nrule_chain;			// номер цепочки правила
			MfstDiagnosis();
			MfstDiagnosis(				// диагностика
				short plenta_posiion,	// позиция на ленте
				RC_STEP	prc_step,		// код завершения шага
				short pnrule,			// номер правила
				short pnrule_chain		// номер цепочки правила
			);
		}	diagnosis[MFST_DIAGN_NUMBER];			// последние самые глубокие сообщения

		GRBALHABET* lenta;				// перекодированная (TS/NS) лента (из lextable)
		short lenta_position;			// текущая позиция на ленте
		short nrule;					// номер текущего правила
		short nrulechain;				// номер текущей цепочки, текущего правила
		short lenta_size;				// размер ленты
		GRB::Greibach grebach;			// грамматика Грейбах(описание правил грамматики)
		LT::LexTable lex;				// резульатат работы лексического анализатора
		MFSTSTSTACK st;					// стек автомата
		std::stack<MfstState> storestate;//стек для сохранения состояний
		Mfst() : lenta(0), lenta_size(0), lenta_position(0) {};
		Mfst(
			LT::LexTable plex,			// результат работы лексического анализотора
			GRB::Greibach pgrebach		// грамматика Грейбах
		);
		char* getCSt(char* buf);		// получить содержимое стека
		char* getCLenta(char* buf, short pos, short n = 25);	// лента : n символо с роs
		char* getDiagnosis(short n, char* buf);	// получить n-ую строку диагностики или 0х00
		bool savestate(Log::LOG& log);				// сохранить состояние автомата
		bool reststate(Log::LOG& log);				// восстановить состояние автомата
		bool push_chain(				// поместить цепочку правила в стек
			GRB::Rule::Chain chain	// цепочка правила
		);
		RC_STEP step(Log::LOG& log);		// выполнить шаг автомата
		bool start(Log::LOG& log);		// запустить автомат
		bool savediagnosis(
			RC_STEP pprc_step		// Код завершения шага
		);
		void printrules(Log::LOG log);				// вывести последовательность правил

		struct Deducation
		{
			short size;					// количество шагов в выводе
			short* nrules;				// номера правил грамматики
			short* nrulechains;			// номера цепочек правил грамматики (nrules)
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };

		} deducation;
		bool savededucation();			// сохранить дерево вывода
	};
}