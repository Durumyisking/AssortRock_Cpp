#include "Scene_Clear.h"
#include "Application.h"

CScene_Clear::CScene_Clear()
{
}

CScene_Clear::~CScene_Clear()
{
}

void CScene_Clear::Init()
{
	system("cls");
}

void CScene_Clear::Update()
{
	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		case '\r':
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::PLAY);
			break;
		default:
			break;
		}
	}
}

void CScene_Clear::Render()
{
	SetColor(static_cast<WINCOLOR>(rand() % 15));
	_SetCursor(12, 5); wcout << L"忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	_SetCursor(12, 6); wcout << L"弛                       弛" << endl;
	_SetCursor(12, 7); wcout << L"弛        Clear!!        弛" << endl;
	_SetCursor(12, 8); wcout << L"弛                       弛" << endl;
	_SetCursor(12, 9); wcout << L"戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	_SetCursor(12, 10); wcout<< L"   Enter ====> NextStage " << endl;
}

void CScene_Clear::Destroy()
{
}

void CScene_Clear::Enter()
{
	system("cls");
}

void CScene_Clear::Exit()
{
	system("cls");
}
