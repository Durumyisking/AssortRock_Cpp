#include "Scene_Title.h"
#include "Application.h"


CScene_Title::CScene_Title()
{

}

CScene_Title::~CScene_Title()
{
}

void CScene_Title::Init()
{


}

void CScene_Title::Update()
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

void CScene_Title::Render()
{
	SetColor(static_cast<WINCOLOR>(rand() % 15));
	_SetCursor(12, 5); wcout << L"忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	_SetCursor(12, 6); wcout << L"弛      PUSH             弛" << endl;
	_SetCursor(12, 7); wcout << L"弛             PUSH      弛" << endl;
	_SetCursor(12, 8); wcout << L"戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	_SetCursor(12, 9); wcout << L"   Press Enter to Play   " << endl;


}

void CScene_Title::Destroy()
{
}
