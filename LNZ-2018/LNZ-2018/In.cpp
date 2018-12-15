#include "stdafx.h"
#include "Errors.h"
#include "LexAnalyse.h"
#include "In.h"
#include "Library.h"
#include <fstream>
#define TEXT_SIZE 4096
namespace In
{

	IN getin(wchar_t infile[])
	{
		IN myinf;
		int position = 1;
		myinf.ignor = 0;
		myinf.size = strlen(LIBRARY);
		myinf.lines = 1;
		myinf.text = new unsigned char[IN_MAX_LEN_TEXT];
		strcpy((char*)myinf.text, LIBRARY);

		unsigned char Temp = ' ';
		std::ifstream file(infile);
		if (!file)							//Файл не открыло
		{
			throw ERROR_THROW(110);
		}

		while ((Temp = file.get()) && !file.eof())
		{
			switch (myinf.code[Temp])
			{


			case myinf.F:
				throw ERROR_THROW_IN(111, myinf.lines, position); break;

			case myinf.K: case myinf.T: case myinf.D: case myinf.S: case myinf.B: case myinf.C:

				myinf.text[myinf.size] = (char)Temp;
				position++;
				myinf.size++;
				break;
			case myinf.E:
				++myinf.lines;
				myinf.text[myinf.size] = (char)Temp;
				myinf.size++;
				position = 1;
				break;
				/*default:
				myinf.text[myinf.size] = (char)Temp;
				position++;
				break;*/

			}




		}
		myinf.text[myinf.size++] = '\0';
		file.close();
		return myinf;
	}

	ArrWord::ArrWord(int mxsz)
	{
		arr = new mass[mxsz];
		size = 0;
	}
	void ArrWord::AddInArr(char*word, int len, int line)
	{
		arr[size].line = line - 3;
		word[len] = '\0';
		std::strcpy(arr[size].string, word);
		size++;
	}
	void ArrWord::Split(char* text)
	{
		int ASCI[256] = IN_CODE_TABLE;
		char word[MAX_LEN_WORD_SIZE];
		int line = 1;
		int i = 0; int j = 0;
		unsigned char curent;
		while (text[i] != '\0')
		{
			if (i > TEXT_SIZE)
				throw ERROR_THROW(116, line, 0);
			curent = text[i];
			switch (ASCI[curent])
			{


			case IN::K:
				word[j++] = text[i++];
				while (text[i] != '"')
				{
					word[j++] = text[i++];
					if (text[i] == '\n')
					{
						throw ERROR_THROW_IN(113, line - 3, -1);
					}
					if (j - 1 > STRING_MAX_LEN)
					{
						throw ERROR_THROW_IN(114, line - 3, -1);
					}

				}
				word[j++] = text[i++];
				AddInArr(word, j, line);
				j = 0;
				break;



			case IN::B:case IN::C:case IN::D:
				switch (j)
				{
				case 0:word[j++] = text[i++]; AddInArr(word, j, line); j = 0; break;

				default:AddInArr(word, j, line); j = 0;
				}
				break;

			case IN::S:
				switch (j)
				{
				case 0:i++; break;
				default: AddInArr(word, j, line); j = 0; i++;	  break;
				}break;


			case IN::T:


				word[j++] = text[i++];
				break;

			case IN::E:

				switch (j) {

				case 0:i++; line++; break;
				default:AddInArr(word, j, line); j = 0; i++; line++; break;
				}break;
			}

		}
		if (j)
			AddInArr(word, j, line);
	}
}