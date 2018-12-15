#pragma once
#include "IT.h"

namespace FST
{



	struct RELATION    //ребро:символ->вершина графа переходов КА
	{
		char symbol;   // символ перехода
		short nnode;   // номер смежной вершины
		RELATION(char c = 0x00, short ns = NULL); //символ перехода и новое состояние
	};


	struct NODE         //вершина графа переходов
	{
		short n_relation;			//количество состояний, в которое можем перейти
		RELATION *relations;		//ребра
		NODE();
		NODE(short n, RELATION rel, ...);  //количество инцидентных ребер и список ребер
	};


	struct FST
	{
		char* string;											//цепочка (строка, завершается 0х00)
		short position;											//текущая позиция в цепочке
		short nstates;											//количество состояний автомата
		NODE* nodes;											//граф переходов: [0] - Начальное состояние, [nstate-1]- конечное
		short* rstates;											//возможные состояния автомата на данной позиции
		FST(
			char*s,												//цепочка (строка, завершается 0х00)
			short nsm,											//количество состояний автомата
			NODE n, ...											//список состояний(граф переходов)
		);
	};

	struct TOKEN//структура, связывающая конечный автомат и лексему
	{
		FST fst;//конечный автомат
		char token;//лексема
		IT::IDTYPE IdType;//тип идентификатора
		IT::IDDATATYPE IdDataType;//тип данных

		void SetLexeme(char* lexeme);//задать строку, для конечного автомата
	};
	bool execute(FST& fst);       //выполнить расспознование цепочки
}

