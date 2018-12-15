#pragma once
#define LEXEMA_FIXSIZE 1
#define LT_MAXSIZE 4096
#define LT_TI_NULLIDX 0xffffffff
#define LEX_INTEGER 'n'
#define LEX_STRING 's'
#define LEX_BOOL 'k'
#define LEX_ID 'i'			//лексема дл€ идентификатора
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_SEMICOLON ';'
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELET '}'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTHESIS ')'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_EQUAL '='
#define LEX_MAIN 'm'
#define LEX_NUMBER 'z'

namespace LT
{
	enum priority { NDEF = 0, BRACE = 1, DS = 3, PM = 2, UM = 4 };
	struct Entry						// строка таблицы лексем
	{
		priority pr;
		char lexema;					// лексема
		int	 sn;						// номер строки в исходном тексте
		int	 idxTI;						// индекс в таблице идентефикаторов
	};

	struct LexTable						// экземпл€р такблицы лексем
	{
		int maxsize;					// емкость таблицы лексем < LT_MAXSIZE
		int size;						// текущий размер таблицы лексем < MAXSIZE
		Entry* table;					// массив строк таблицы лексем
	};

	LexTable Create(		 // создать таблицу лексем
		int size // емкость таблицы лексем < LT_MAXSIZE
	);
	void Add(					// добавить строку в таблицу лексем 
		LexTable& lextable,	// экземпл€р таблицы лексем
		Entry entry			// строка таблицы лексем
	);
	Entry Getentry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);	// удалить таблицу лексем ( освободить пам€ть )
};