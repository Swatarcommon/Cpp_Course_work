#include "stdafx.h"
#include "Errors.h"
#include "Log.h"
#include "Parm.h"
#include <time.h>
#include <fstream>

namespace Log
{

	LOG getlog(wchar_t logfile[])
	{
		LOG temp = INITLOG;
		temp.stream = new std::ofstream;
		temp.stream->open(logfile);
		if (!temp.stream)
			throw ERROR_THROW(112);
		return temp;
	}


	void WriteLine(LOG log, char* c, ...)
	{
		char **p = &c;
		while (*p != "")
		{
			(*log.stream) << *p;
			*p++;
		}
	}



	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t **p = &c;
		char buffer[PARM_MAX_SIZE];

		while (*p != L"")
		{
			wcstombs(buffer, *p, PARM_MAX_SIZE);
			(*log.stream) << buffer;
			*p++;
		}
	}


	void WriteLog(LOG log)
	{
		char buffer[PARM_MAX_SIZE];

		time_t rawtime;
		struct tm* timeinfo;

		rawtime = time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, PARM_MAX_SIZE, "Дата: %d.%m.%y %H:%M:%S", timeinfo);
		(*log.stream) << "\n---- Протокол ---- " << buffer << " ---- \n";
	}


	void WriteParm(LOG log, Parm::PARM parm)
	{

		char inInfo[PARM_MAX_SIZE];
		char outInfo[PARM_MAX_SIZE];
		char logInfo[PARM_MAX_SIZE];
		wcstombs(inInfo, parm.in, sizeof(inInfo));
		wcstombs(outInfo, parm.out, sizeof(outInfo));
		wcstombs(logInfo, parm.log, sizeof(logInfo));

		(*log.stream) << "---- Параметры ---- \n" << " -in: " << inInfo << "\n" << " -out: " << outInfo << "\n" << " -log: " << logInfo << "\n";
	}

	void WriteIn(LOG log, In::IN in)
	{
		(*log.stream) << "---- Параметры ---- \n" << "Количество символов: " << in.size << "\nКоличество строк: " << in.lines << "\n";

	}

	void WriteError(LOG log, Error::ERROR error)
	{
		(*log.stream) << "Ошибка " << error.id << ": " << error.message << ".";
		if (error.inext.col != -1)
			(*log.stream) << " Позиция: " << error.inext.col << ".\n";
		if (error.inext.line != -1)
			(*log.stream) << " Строка: " << error.inext.line << ".\n";
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
}