#include "Scene_Play.h"
#include "Application.h"

CScene_Play::CScene_Play()
{
}

CScene_Play::~CScene_Play()
{
}

void CScene_Play::Init()
{

}

void CScene_Play::Update()
{
	
	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		case 'D': case 'd':
			m_pApplication->ChangeScene(SCENE_TYPE::DEAD);
			break;
		default:
			break;
		}
	}
}

void CScene_Play::Render()
{
	SetColor(WINCOLOR::DARK_SKY_BLUE);
	_SetCursor(12, 5); wcout << L"��������������������������������������������������" << endl;
	_SetCursor(12, 6); wcout << L"��      PLAY             ��" << endl;
	_SetCursor(12, 7); wcout << L"��            SCENE      ��" << endl;
	_SetCursor(12, 8); wcout << L"��������������������������������������������������" << endl;
	_SetCursor(12, 9); wcout << L"   Press D to be Dad!?   " << endl;
}

void CScene_Play::Destroy()
{
}
