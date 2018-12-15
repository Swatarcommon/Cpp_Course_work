#include "stdafx.h"
#include "Errors.h"
#include "Parm.h"
namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM myParm;

		bool ParmIn = false;
		bool ParmOut = false;
		bool ParmLog = false;

		wchar_t *temp = NULL;

		for (int i = 1; i < argc; i++)
		{
			if (wcslen(argv[i]) < PARM_MAX_SIZE)
			{
				if (wcsstr(argv[i], PARM_IN) != 0)
				{
					temp = wcsstr(argv[i], PARM_IN) + wcslen(PARM_IN);
					wcscpy(myParm.in, temp);
					temp -= wcslen(PARM_IN);
					ParmIn = true;
				}
				if (wcsstr(argv[i], PARM_OUT) != 0)
				{
					temp = wcsstr(argv[i], PARM_OUT) + wcslen(PARM_OUT);
					wcscpy(myParm.out, temp);
					temp -= wcslen(PARM_OUT);
					ParmOut = true;
				}
				if (wcsstr(argv[i], PARM_LOG) != 0)
				{
					temp = wcsstr(argv[i], PARM_LOG) + wcslen(PARM_LOG);
					wcscpy(myParm.log, temp);
					temp -= wcslen(PARM_LOG);
					ParmLog = true;
				}
			}
			else
			{
				throw ERROR_THROW(104);
			}
		}
		if (!ParmIn)
		{
			throw ERROR_THROW(100);
		}
		if (!ParmOut)
		{
			wcscpy(temp, myParm.in);
			wcsncat(temp, PARM_OUT_DEFAULT_EXT, 4);
			wcscpy(myParm.out, temp);
		}
		if (!ParmLog)
		{
			wcscpy(temp, myParm.in);
			wcsncat(temp, PARM_LOG_DEFAULT_EXT, 4);
			wcscpy(myParm.log, temp);
		}
		return myParm;
	}
}