#include "stdafx.h"
#include "userlib.h"
#include <iostream>
//#include <math.h>
#include <Windows.h>
#pragma warning(disable: 4996)


extern "C"
{
	char*  _stdcall copystr(char* str1, char* str2)
	{
		if (!str1 || !str2)
		{
			std::cout << "ERROR: Null string pointer in copystr function!!!" << std::endl;
			system("pause");
			ExitProcess(0);
		}
		else
			return strcpy(str1, str2);
	}
	char* _stdcall strcon(char* str1, char* str2)
	{
		char* buf = new char[255];
		if (!str1 || !str2)
		{
			std::cout << "ERROR: Null string in strcon function!!!" << std::endl;
			system("pause");
			ExitProcess(0);
		}
		strcpy(buf, str2);
		strcat(buf, str1);

		return  buf;
	}
	int _stdcall sqr(int i)
	{
		return pow(i, 2);
	}
	void _stdcall outstr(char* s)
	{
		if (s != nullptr)
			std::cout << s << std::endl;
		else
			std::cout << "Empty line!";
	}
	void _stdcall outint(int i)
	{
		std::cout << i << std::endl;
	}
	int _stdcall sqroot(int i)
	{
		return (int)std::sqrt(i);
	}

	//int _stdcall strnum(char* str)
	//{
	//	if (!str)
	//	{
	//		std::cout << "ERROR: Null string pointer in function!!!" << std::endl;
	//		system("pause");
	//		ExitProcess(0);
	//	}
	//	else
	//		return std::strlen(str);
	//}
}