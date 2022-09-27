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
	_SetCursor(PRINT_GAP_X, (y + 2)); wcout << L"┌───────────────────────┐" << endl;
	_SetCursor(PRINT_GAP_X, (y + 3)); wcout << L"│      PLAY             │" << endl;
	_SetCursor(PRINT_GAP_X, (y + 4)); wcout << L"│            SCENE      │" << endl;
	_SetCursor(PRINT_GAP_X, (y + 5)); wcout << L"└───────────────────────┘" << endl;
	_SetCursor(PRINT_GAP_X, (y + 6)); wcout << L"Press Enter to be Dead !?" << endl;

	SetColor(WINCOLOR::DARK_GREEN);
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Backspace ] : undo\n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Reset ] : R \n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Esc ] : EPRINT_GAP_Xit \n");
	SetColor(WINCOLOR::BLUE);
	y++;
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ H ] : Replay\n"); //타이틀씬으로


	SetColor(WINCOLOR::GRAY);
	y = 5;
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      W      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("     ↑      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf(" A ←   → S ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("     ↓      ");
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



	// stage메모장 파일을 읽어서 그걸 맵으로 쓸꺼임
	CStage* stage = new CStage();
	stage->SetMap(m_pMap);
	stage->Load();
	m_pMap->Init();
	m_pPlayer = m_pMap->GetPlayer();
}

