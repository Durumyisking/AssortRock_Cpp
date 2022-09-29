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
	void* p = new int();
	srand((int)p);
	SetColor(static_cast<WINCOLOR>(rand() % 15 + 1));

	_SetCursor(PRINT_GAP_X, (10)); 	 wcout << L"��������������������������������������������������" << endl;
	_SetCursor(PRINT_GAP_X, (11));	 wcout << L"��                       ��" << endl;
	_SetCursor(PRINT_GAP_X, (12));	 wcout << L"��        Clear!!        ��" << endl;
	_SetCursor(PRINT_GAP_X, (13));	 wcout << L"��                       ��" << endl;
	_SetCursor(PRINT_GAP_X, (14));	 wcout << L"��������������������������������������������������" << endl;
	_SetCursor(PRINT_GAP_X, (15));   wcout <<  L"   Enter ====> NextStage " << endl;
}

void CScene_Clear::Destroy()
{
}

void CScene_Clear::Enter()
{
	PlaySoundA("..\\Sounds\\clear.wav", 0, SND_FILENAME | SND_ASYNC);
	system("cls");
}

void CScene_Clear::Exit()
{
	system("cls");
}
