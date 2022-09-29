#include "Scene_Dead.h"
#include "Application.h"

CScene_Dead::CScene_Dead()
{
}

CScene_Dead::~CScene_Dead()
{
}

void CScene_Dead::Init()
{
}

void CScene_Dead::Update()
{
	Sleep(3000);

	CApplication::GetInst()->SetIsRunning(false);

}

void CScene_Dead::Render()
{
	SetColor(WINCOLOR::DARK_RED);
	_SetCursor(12, 5); wcout << L"��������������������������������������������������" << endl;
	_SetCursor(12, 6); wcout << L"��      DEAD             ��" << endl;
	_SetCursor(12, 7); wcout << L"��            SCENE      ��" << endl;
	_SetCursor(12, 8); wcout << L"��������������������������������������������������" << endl;
	_SetCursor(12, 9); wcout << L"       You Are Dead      " << endl;
}

void CScene_Dead::Destroy()
{
}

void CScene_Dead::Enter()
{
	system("cls");
}

void CScene_Dead::Exit()
{
	system("cls");
}
