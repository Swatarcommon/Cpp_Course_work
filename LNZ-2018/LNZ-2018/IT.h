#pragma once
#define	ID_MAXSIZE		10			// максимальное количество символов в идентификатореID_MAXSIZE
#define	TI_MAXSIZE		4096		// максимальное количество строк в таблице идентификаторов
#define	TI_INT_DEFAULT	0x00000000	// значение по умолчанию дл€ типа int
#define	TI_STR_DEFAULT	0x00		// значеник по умолчанию дл€ типа string 
#define	TI_NULLIDX		0xffffffff	// нет элемента таблицы идентификаторов
#define	TI_STR_MAXSIZE	255
#define TI_


namespace IT
{
	enum IDDATATYPE {
		NDEFD = 0,			//неопределен
		INT = 1,			//ingeter
		STR = 2,			//string
		BOOL = 3			//bool
	};			
	enum IDTYPE {
		NDEFT = 0,	//неопределен 
		V = 1,		//переменна€	
		F = 2,		//функци€ 
		L = 3,		//литерал
		P = 4		//параметр
	};	

	struct Entry									// строка таблицы идентефикаторов
	{
		int			idxfirstLE;						// индекс первой строки в таблице лексем
		char		id[30] = "";					//идентефикатор (автоматически усекаетс€ до ID_MAXSIZE)
		IDDATATYPE	iddatatype;						//тип данных
		IDTYPE		idtype;
		char* scope;
		union
		{
			int vint;
			struct
			{
				char len;
				char str[TI_STR_MAXSIZE - 1];
			}	vstr[TI_STR_MAXSIZE];
		}value;
		void reset()
		{
			for(int i = 0; i<30; i++)
			{
				id[i] = 0;
			}
			//memset(id, 0, ID_MAXSIZE);
			idxfirstLE = TI_NULLIDX;
			iddatatype = IT::NDEFD;
			idtype = IT::NDEFT;
		}
	};

	struct  IdTable						// экземпл€р таблицы идентефикаторов
	{
		int maxsize;					// емкость таблицы идентефикаторов < TI_MAXSIZE
		int size;						// текущий размер таблицы идентефикаторов < maxsize
		Entry* table;					// массив строк таблицы идентефикаторов
	};


	IdTable Create(						// создать таблицу идентефикаторов	
		int size						// емкость таблицы идентефикаторов < TI_MAXSIZE 
	);
	void Add(							// добавить строку в таблицу идентефикаторов
		IdTable& idtable,				// экземпл€р таблицы идентефикаторов
		Entry entry						// строка таблицы идентефикаторов
	);
	Entry Getentry(IdTable& idtable, int n);

	int IsId(IdTable& idtable, char id[ID_MAXSIZE]);

	void Delete(IdTable& idtable);		// удалить таблицу идентефикаторов ( освободить пам€ть );
}