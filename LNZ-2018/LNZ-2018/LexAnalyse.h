#pragma once
#include "pch.h"
#include "In.h"
#include "LT.h"
#include "Log.h"
#include "IT.h"
#include "FST.h"


#define KeyMain\
	{ {\
	"",\
	5,\
	FST::NODE(1, FST::RELATION('m', 1)),\
	FST::NODE(1, FST::RELATION('a', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('n', 4)),\
	FST::NODE()},LEX_MAIN, IT::NDEFT, IT::NDEFD}

#define EQUAL\
	{ {\
	"",\
	 2,\
	FST::NODE(1, FST::RELATION('=', 1)),\
	FST::NODE()},LEX_EQUAL, IT::NDEFT, IT::NDEFD}

#define KeySemicolon\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION(';', 1)),\
	FST::NODE()},LEX_SEMICOLON, IT::NDEFT, IT::NDEFD}



#define KeyComma\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION(',', 1)),\
	FST::NODE()},LEX_COMMA, IT::NDEFT, IT::NDEFD}


#define KeyLBrace\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION('{', 1)),\
	FST::NODE()},LEX_LEFTBRACE, IT::NDEFT, IT::NDEFD}


#define KeyRBrace\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION('}', 1)),\
	FST::NODE()},LEX_BRACELET, IT::NDEFT, IT::NDEFD}


#define KeyLBracket\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION('(', 1)),\
	FST::NODE()},LEX_LEFTHESIS,IT::NDEFT, IT::NDEFD}

#define KeyRBracket\
	{ {\
	"",\
	2,\
	FST::NODE(1, FST::RELATION(')', 1)),\
	FST::NODE()},LEX_RIGHTHESIS, IT::NDEFT, IT::NDEFD}

#define PLUS\
	{ { "", 2,\
	FST::NODE(1, FST::RELATION('+', 1)),\
	FST::NODE() }, LEX_PLUS, IT::NDEFT, IT::NDEFD }

#define DIRSLASH\
		{ { "", 2,\
	FST::NODE(1, FST::RELATION('/', 1)),\
	FST::NODE() }, LEX_DIRSLASH, IT::NDEFT, IT::NDEFD }

#define MINUS\
	{ { "", 2,\
	FST::NODE(1, FST::RELATION('-', 1)),\
	FST::NODE() }, LEX_MINUS, IT::NDEFT, IT::NDEFD }
#define STAR\
	{ { "", 2,\
	FST::NODE(1, FST::RELATION('*', 1)),\
	FST::NODE() }, LEX_STAR, IT::NDEFT, IT::NDEFD }



#define KeyPrint\
	{ {\
	"",\
	4,\
	FST::NODE(1, FST::RELATION('o', 1)),\
	FST::NODE(1, FST::RELATION('u', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE()},LEX_PRINT,IT::NDEFT, IT::NDEFD}

#define KeyInteger\
	{ {\
	"",\
	4,\
	FST::NODE(1, FST::RELATION('i', 1)),\
	FST::NODE(1, FST::RELATION('n', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE()},LEX_INTEGER,IT::V,IT::INT}

#define  KeyString\
	{ {\
	"",\
	7,\
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('t', 2)),\
	FST::NODE(1, FST::RELATION('r', 3)),\
	FST::NODE(1, FST::RELATION('i', 4)),\
	FST::NODE(1, FST::RELATION('n', 5)),\
	FST::NODE(1, FST::RELATION('g', 6)),\
	FST::NODE()},LEX_STRING, IT::V, IT::STR}


#define KeyDeclare\
	{ {\
	"",\
	4,\
	FST::NODE(1, FST::RELATION('v', 1)),\
	FST::NODE(1, FST::RELATION('a', 2)),\
	FST::NODE(1, FST::RELATION('r', 3)),\
	FST::NODE()},LEX_DECLARE, IT::NDEFT, IT::NDEFD}



#define KeyReturn\
	{ {\
	"",\
	7,\
	FST::NODE(1, FST::RELATION('r', 1)),\
	FST::NODE(1, FST::RELATION('e', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE(1, FST::RELATION('u', 4)),\
	FST::NODE(1, FST::RELATION('r', 5)),\
	FST::NODE(1, FST::RELATION('n', 6)),\
	FST::NODE()}, LEX_RETURN, IT::NDEFT, IT::NDEFD}

#define KeyFunction\
	{ {\
	"",\
	9,\
	FST::NODE(1, FST::RELATION('f', 1)),\
	FST::NODE(1, FST::RELATION('u', 2)),\
	FST::NODE(1, FST::RELATION('n', 3)),\
	FST::NODE(1, FST::RELATION('c', 4)),\
	FST::NODE(1, FST::RELATION('t', 5)),\
	FST::NODE(1, FST::RELATION('i', 6)),\
	FST::NODE(1, FST::RELATION('o', 7)),\
	FST::NODE(1, FST::RELATION('n', 8)),\
	FST::NODE()}, LEX_FUNCTION, IT::F, IT::NDEFD}

#define KeyId\
	{ {\
	"",\
	2,\
	FST::NODE(52,\
		FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0),\
	    FST::RELATION('e', 0), FST::RELATION('f', 0), FST::RELATION('g', 0), FST::RELATION('h', 0),\
		FST::RELATION('i', 0), FST::RELATION('j', 0), FST::RELATION('k', 0), FST::RELATION('l', 0),\
		FST::RELATION('m', 0), FST::RELATION('n', 0), FST::RELATION('o', 0), FST::RELATION('p', 0),\
		FST::RELATION('q', 0), FST::RELATION('r', 0), FST::RELATION('s', 0), FST::RELATION('t', 0),\
		FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0), FST::RELATION('x', 0),\
		FST::RELATION('y', 0), FST::RELATION('z', 0), FST::RELATION('a', 1), FST::RELATION('b', 1),\
		FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
		FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1),\
		FST::RELATION('k', 1), FST::RELATION('l', 1), FST::RELATION('m', 1), FST::RELATION('n', 1),\
		FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
		FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1),\
		FST::RELATION('w', 1), FST::RELATION('x', 1), FST::RELATION('y', 1), FST::RELATION('z', 1)),\
		FST::NODE()},LEX_ID, IT::NDEFT,IT::NDEFD}


#define  KeyLT\
	{ {"", 2,\
	FST::NODE(20,\
		FST::RELATION('0', 0), FST::RELATION('0', 1),\
		FST::RELATION('1', 0), FST::RELATION('1', 1),\
		FST::RELATION('2', 0), FST::RELATION('2', 1),\
		FST::RELATION('3', 0), FST::RELATION('3', 1),\
		FST::RELATION('4', 0), FST::RELATION('4', 1),\
		FST::RELATION('5', 0), FST::RELATION('5', 1),\
		FST::RELATION('6', 0), FST::RELATION('6', 1),\
		FST::RELATION('7', 0), FST::RELATION('7', 1),\
		FST::RELATION('8', 0), FST::RELATION('8', 1),\
		FST::RELATION('9', 0), FST::RELATION('9', 1)),\
	    FST::NODE()}, LEX_NUMBER, IT::L,IT::INT}

#define StringKeyLT\
	{ { "", 4,\
	FST::NODE(1, FST::RELATION('"', 1)),\
	FST::NODE(178,\
FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),\
FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),\
FST::RELATION('i', 1), FST::RELATION('g', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),\
FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('A', 1), FST::RELATION('B', 1),\
FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1),\
FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1),\
FST::RELATION('K', 1), FST::RELATION('L', 1), FST::RELATION('M', 1), FST::RELATION('N', 1),\
FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1),\
FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1),\
FST::RELATION('W', 1), FST::RELATION('X', 1), FST::RELATION('Y', 1), FST::RELATION('Z', 1),\
FST::RELATION('1', 1), FST::RELATION('2', 1),\
FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
FST::RELATION('-', 1), FST::RELATION('=', 1), FST::RELATION('_', 1), FST::RELATION('+', 1),\
FST::RELATION('!', 1), FST::RELATION('"', 1), FST::RELATION('¹', 1), FST::RELATION(';', 1),\
FST::RELATION('%', 1), FST::RELATION(':', 1), FST::RELATION('?', 1), FST::RELATION('*', 1),\
FST::RELATION('(', 1), FST::RELATION(')', 1), FST::RELATION('~', 1), FST::RELATION('@', 1),\
FST::RELATION('#', 1), FST::RELATION('$', 1), FST::RELATION('%', 1), FST::RELATION('^', 1),\
FST::RELATION('&', 1), FST::RELATION('<', 1), FST::RELATION('>', 1), FST::RELATION(',', 1),\
FST::RELATION('.', 1), FST::RELATION(' ', 1),FST::RELATION('/', 1), FST::RELATION(' ', 2),\
FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2),\
FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2),\
FST::RELATION('i', 2), FST::RELATION('g', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),\
FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2),\
FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2),\
FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),\
FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('A', 2), FST::RELATION('B', 2),\
FST::RELATION('C', 2), FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2),\
FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), FST::RELATION('J', 2),\
FST::RELATION('K', 2), FST::RELATION('L', 2), FST::RELATION('M', 2), FST::RELATION('N', 2),\
FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2),\
FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), FST::RELATION('V', 2),\
FST::RELATION('W', 2), FST::RELATION('X', 2), FST::RELATION('Y', 2), FST::RELATION('Z', 2),\
FST::RELATION('1', 2), FST::RELATION('2', 2),\
FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2),\
FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2),\
FST::RELATION('-', 2), FST::RELATION('=', 2), FST::RELATION('_', 2), FST::RELATION('+', 2),\
FST::RELATION('!', 2), FST::RELATION('"', 2), FST::RELATION('¹', 2), FST::RELATION(';', 2),\
FST::RELATION('%', 2), FST::RELATION(':', 2), FST::RELATION('?', 2), FST::RELATION('*', 2),\
FST::RELATION('(', 2), FST::RELATION(')', 2), FST::RELATION('~', 2), FST::RELATION('@', 2),\
FST::RELATION('#', 2), FST::RELATION('$', 2), FST::RELATION('%', 2), FST::RELATION('^', 2),\
FST::RELATION('&', 2), FST::RELATION('<', 2), FST::RELATION('>', 2),FST::RELATION('/', 2), FST::RELATION(',', 2),\
FST::RELATION('.', 2)),\
	FST::NODE(1, FST::RELATION('"', 3)), \
	FST::NODE() }, LEX_LITERAL, IT::L, IT::STR }
namespace Lex
{
	bool LexicalAnalyse(In::ArrWord arr, LT::LexTable& lextable, IT::IdTable& idtable, Log::LOG log);
	void LexTableOut(LT::LexTable lextable, Log::LOG log);
	void IDTableOut(IT::IdTable idtable, Log::LOG log);
}