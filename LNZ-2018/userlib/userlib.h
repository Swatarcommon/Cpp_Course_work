#pragma once

extern "C"
{
	char* _stdcall copystr(char*, char*);
	char* _stdcall strcon(char*, char*);
	void _stdcall outstr(char*);
	void _stdcall outint(int);
	int _stdcall sqroot(int);
	int _stdcall sqr(int);
	//int _stdcall strnum(char* str);
}