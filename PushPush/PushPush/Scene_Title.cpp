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
			system("cls");													// ȭ�� Ŭ����
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::STAGE_SELECT);
			break;
		default:
			break;
		}
	}

}

void CScene_Title::Render()
{


	SetColor(static_cast<WINCOLOR>(rand() % 15));
	_SetCursor(PRINT_GAP_X, (10)); 	 wcout << L"������������������������������������������������������������������" << endl;
	_SetCursor(PRINT_GAP_X, (11));	 wcout << L"��  Ư��!!                       ��" << endl;
	_SetCursor(PRINT_GAP_X, (12));	 wcout << L"��                               ��" << endl;
	_SetCursor(PRINT_GAP_X, (13));	 wcout << L"��          �͸��������         ��" << endl;
	_SetCursor(PRINT_GAP_X, (14));	 wcout << L"��                               ��" << endl;
	_SetCursor(PRINT_GAP_X, (15));	 wcout << L"��                      ���ƶ�!! ��" << endl;
	_SetCursor(PRINT_GAP_X, (16));	 wcout << L"������������������������������������������������������������������" << endl;
	_SetCursor(PRINT_GAP_X, (18));   wcout << L"        Press Enter to Play   " << endl;


}

void CScene_Title::Destroy()
{
}

void CScene_Title::Enter()
{
	PlaySoundA("..\\Sounds\\title.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
}

void CScene_Title::Exit()
{
	system("cls");
}
