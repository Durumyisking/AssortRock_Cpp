#include "Scene_StageSelect.h"
#include "Application.h"


CScene_StageSelect::CScene_StageSelect()
	: m_iArrowLine(0)
{
}

CScene_StageSelect::~CScene_StageSelect()
{
}

void CScene_StageSelect::Init()
{
}

void CScene_StageSelect::Update()
{
	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		case '\r':
			system("cls");
			if (0 == m_iArrowLine)
			{
				CApplication::GetInst()->SetDifficulty(STAGE_TYPE::EASY);
				CApplication::GetInst()->ChangeScene(SCENE_TYPE::PLAY);
			}
			else if (3 == m_iArrowLine)
			{
				CApplication::GetInst()->SetDifficulty(STAGE_TYPE::HARD);
				CApplication::GetInst()->ChangeScene(SCENE_TYPE::PLAY);
			}
			break;
		case 'W': case 'w':
			system("cls");
			if(3 == m_iArrowLine)
				m_iArrowLine -= 3;
			break;
		case 'S': case 's':
			system("cls");
			if (0 == m_iArrowLine)
				m_iArrowLine += 3;
			break;
		default:
			break;
		}
	}

}

void CScene_StageSelect::Render()
{

	void* p = new int();
	srand((int)p);
	SetColor(static_cast<WINCOLOR>(rand() % 15 + 1));

	_SetCursor(PRINT_GAP_X, (6)); 	 wcout << L"┌───────────────────────┐" << endl;
	_SetCursor(PRINT_GAP_X, (7));	 wcout << L"│   Select  Difficulty  │" << endl;
	_SetCursor(PRINT_GAP_X, (8));	 wcout << L"└───────────────────────┘" << endl;


	SetColor(WINCOLOR::WHITE);
	_SetCursor(PRINT_GAP_X, (10));	 wcout << L"위 : W  아래 : S  선택 : ENTER" << endl;



	SetColor(WINCOLOR::GREEN);
	_SetCursor(PRINT_GAP_X - 5, (15));	 wcout << L"♣♣♣♣♣♣♣♣♣EASY♣♣♣♣♣♣♣♣♣" << endl;
	SetColor(WINCOLOR::RED);
	_SetCursor(PRINT_GAP_X - 5, (18));	 wcout << L"♨♨♨♨♨♨♨♨♨HARD♨♨♨♨♨♨♨♨♨" << endl;

	SetColor(WINCOLOR::WHITE);
	_SetCursor(PRINT_GAP_X - 7, (15 + m_iArrowLine));	 wcout << L"▶";

}

void CScene_StageSelect::Destroy()
{
}

void CScene_StageSelect::Enter()
{
	system("cls");
}

void CScene_StageSelect::Exit()
{
	system("cls");
}
