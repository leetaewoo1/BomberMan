#include "pch.h"
#include "Define.h"


void SetCursor(const COORD& a_stPos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a_stPos);
}

void SetCursor(int a_nPosX, int a_nPosY)
{
	SetCursor(COORD{ (short)a_nPosX,(short)a_nPosY });
}

// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
void SetCursorTypeI(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (C)
	{
	case CURSOR_TYPE::NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.
	}
}