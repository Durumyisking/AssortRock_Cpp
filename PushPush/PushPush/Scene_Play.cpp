#include "Scene_Play.h"
#include "Application.h"
#include "Map.h"

#include "Player.h"
#include "Ball.h"

CScene_Play::CScene_Play()
	: m_Stage(nullptr)
	, m_pPlayer(nullptr)
{
}

CScene_Play::~CScene_Play()
{
	delete m_Stage;
}

void CScene_Play::Init()
{
	initmap();

}

void CScene_Play::Update()
{
	m_pPlayer->Update();

	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		case '\r':
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::DEAD);
			break;
		default:
			break;
		}
	}
}

void CScene_Play::Render()
{
	int y = 3;
	SetColor(WINCOLOR::DARK_SKY_BLUE);
	_SetCursor(PRINT_GAP_X, (y + 2)); wcout << L"忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	_SetCursor(PRINT_GAP_X, (y + 3)); wcout << L"弛      PLAY             弛" << endl;
	_SetCursor(PRINT_GAP_X, (y + 4)); wcout << L"弛            SCENE      弛" << endl;
	_SetCursor(PRINT_GAP_X, (y + 5)); wcout << L"戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	_SetCursor(PRINT_GAP_X, (y + 6)); wcout << L"Press Enter to be Dead !?" << endl;

	SetColor(WINCOLOR::DARK_GREEN);
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Backspace ] : undo\n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Reset ] : R \n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Esc ] : EPRINT_GAP_Xit \n");
	SetColor(WINCOLOR::BLUE);
	y++;
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ H ] : Replay\n"); //顫檜ぎ壁戲煎


	SetColor(WINCOLOR::GRAY);
	y = 5;
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      W      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("     ∟      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf(" A ∠   ⊥ S ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("     ⊿      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      D      ");

	y++;
	y++;
	SetColor(WINCOLOR::DARK_BLUE);
	_SetCursor((PRINT_GAP_X + 35), y++); printf("[ PAGE_UP ] : NePRINT_GAP_Xt stage");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("[ PAGE_DOWN ] : Previous");

	m_pMap->Render();

}

void CScene_Play::Destroy()
{
	delete m_pMap;
}

void CScene_Play::initmap()
{

	m_pMap = new CMap(8, 8);