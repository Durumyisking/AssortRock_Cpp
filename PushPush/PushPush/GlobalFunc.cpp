#include "Common.h"
#include "GlobalFunc.h"

void _SetCursor(short _x, short _y)
{
	COORD xy = { _x, _y }; // Windows ÁÂÇ¥°è
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void SetColor(WINCOLOR _eColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(_eColor));
}
