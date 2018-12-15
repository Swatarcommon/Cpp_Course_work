#pragma once
#include "pch.h"
#include "GRB.h"
#define GRB_ERROR_SERIES 200
namespace GRB
{
	Greibach greibach(NS('S'), TS('$'),		// стартовый символ, дно стека
		6,									// количество правил
		Rule(NS('S'), GRB_ERROR_SERIES + 0,	// Ќеверна€ структура программы
			9, // S->m{N}; | pi(F){N}S


			Rule::Chain(14, TS('n'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(14, TS('s'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),

			Rule::Chain(13, TS('n'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(13, TS('s'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),

			Rule::Chain(12, TS('n'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(12, TS('s'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),

			Rule::Chain(13, TS('n'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(13, TS('s'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),

			Rule::Chain(4, TS('m'), TS('{'), NS('N'), TS('}'))

		),
		Rule(NS('N'), GRB_ERROR_SERIES + 1, // ќшибочный оператор
			25,//c(i>i)N c(i<i)N

			Rule::Chain(5, TS('d'), TS('n'), TS('i'), TS(';'), NS('N')),							//объ€вление integer
			Rule::Chain(5, TS('d'), TS('s'), TS('i'), TS(';'), NS('N')),							//объ€вление strin
			Rule::Chain(5, TS('d'), TS('k'), TS('i'), TS(';'), NS('N')),							//объ€вление bool
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),							// инициализаци€ идентификатора
			Rule::Chain(7, TS('d'), TS('n'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),			// объ€вл.+иниц. integer
			Rule::Chain(7, TS('d'), TS('s'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),			// объ€вл.+иниц. string
			Rule::Chain(4, TS('p'), TS('i'), TS(';'), NS('N')),										// вывод идентификатора
			Rule::Chain(4, TS('p'), TS('l'), TS(';'), NS('N')),										// вывод литерала
			Rule::Chain(8, TS('i'), TS('='), TS('i'), TS('('), NS('W'), TS(')'), TS(';'), NS('N')),	// присваение ид-ру рез-та вызова ф-ии
			Rule::Chain(7, TS('p'), TS('i'), TS('('), NS('W'), TS(')'), TS(';'), NS('N')),			// вывод результата ф-ии
			Rule::Chain(6, TS('p'), TS('i'), TS('('), TS(')'), TS(';'), NS('N')),
			Rule::Chain(9, TS('i'), TS('='), TS('i'), TS('('), NS('W'), TS(')'), NS('M'), TS(';'), NS('N')),
			Rule::Chain(4, TS('p'), NS('E'), TS(';'), NS('N')),

			Rule::Chain(4, TS('d'), TS('n'), TS('i'), TS(';')),
			Rule::Chain(4, TS('d'), TS('s'), TS('i'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(6, TS('d'), TS('n'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(6, TS('d'), TS('s'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('p'), TS('i'), TS(';')),
			Rule::Chain(3, TS('p'), TS('l'), TS(';')),
			Rule::Chain(7, TS('i'), TS('='), TS('i'), TS('('), NS('W'), TS(')'), TS(';')),
			Rule::Chain(6, TS('p'), TS('i'), TS('('), NS('W'), TS(')'), TS(';')),
			Rule::Chain(5, TS('p'), TS('i'), TS('('), TS(')'), TS(';')),
			Rule::Chain(8, TS('i'), TS('='), TS('i'), TS('('), NS('W'), TS(')'), NS('M'), TS(';')),
			Rule::Chain(3, TS('p'), NS('E'), TS(';'))
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 2, // ќшибка в выражении
			17,		//E -> i | iM | (E) | (E)M | i(W) | i(W)M | nM | n
			Rule::Chain(2, TS('i'), NS('M')),
			Rule::Chain(2, TS('z'), NS('M')),
			Rule::Chain(2, TS('l'), NS('M')),
			Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')')),
			Rule::Chain(3, TS('i'), TS('('), TS(')')),
			Rule::Chain(4, TS('i'), TS('('), TS(')'), NS('M')),
			Rule::Chain(5, TS('i'), TS('('), NS('W'), TS(')'), NS('M')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(5, TS('-'), TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(1, TS('z')),
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('-'), TS('i'), NS('M')),
			Rule::Chain(3, TS('-'), TS('z'), NS('M')),
			Rule::Chain(2, TS('-'), TS('z')),
			Rule::Chain(2, TS('-'), TS('i'))
		),
		Rule(NS('M'), GRB_ERROR_SERIES + 3, // ќшибка в выражении
			4,		//M -> vE 
			Rule::Chain(2, TS('+'), NS('E')),
			Rule::Chain(2, TS('-'), NS('E')),
			Rule::Chain(2, TS('*'), NS('E')),
			Rule::Chain(2, TS('/'), NS('E'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 4,	// ќшибка в параметрах функции +
			4,		//F -> ti | ti,F
			Rule::Chain(2, TS('n'), TS('i')),
			Rule::Chain(4, TS('n'), TS('i'), TS(','), NS('F')),
			Rule::Chain(2, TS('s'), TS('i')),
			Rule::Chain(4, TS('s'), TS('i'), TS(','), NS('F'))
		),
		Rule(NS('W'), GRB_ERROR_SERIES + 5, // ќшибки в параметрах вызываемой +
			6,		//W -> i | l | i,W | l,W
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('z')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W')),
			Rule::Chain(3, TS('z'), TS(','), NS('W'))));
}