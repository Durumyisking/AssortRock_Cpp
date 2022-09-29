#include "Scene_Play.h"
#include "Application.h"
#include "Map.h"

#include "Player.h"
#include "Ball.h"

CScene_Play::CScene_Play()
	: m_Stage{}
	, m_pPlayer(nullptr)
	, m_iCurrentStage(0)
{
}

CScene_Play::~CScene_Play()
{
	for (int i = 0; i < STAGECOUNT; ++i)
	{
		delete m_Stage[i];
		m_Stage[i] = nullptr;
	}
	Destroy();
}

void CScene_Play::Init()
{
	initmap();

}

void CScene_Play::Update()
{
	m_pMap[m_iCurrentStage]->Update();

	if (m_pMap[m_iCurrentStage]->IsClear())
		++m_iCurrentStage;
}

void CScene_Play::Render()
{
	int y = 3;
	SetColor(WINCOLOR::DARK_SKY_BLUE);
	_SetCursor(PRINT_GAP_X, (y + 2)); wcout << L"┌───────────────────────┐" << endl;
	_SetCursor(PRINT_GAP_X, (y + 3)); wcout << L"│      PLAY             │" << endl;
	_SetCursor(PRINT_GAP_X, (y + 4)); wcout << L"│            SCENE      │" << endl;
	_SetCursor(PRINT_GAP_X, (y + 5)); wcout << L"└───────────────────────┘" << endl;

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
	_SetCursor((PRINT_GAP_X + 35), y++); printf("[ PAGE_UP ] : Next stage");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("[ PAGE_DOWN ] : Previous");

	m_pMap[m_iCurrentStage]->Render();
}

void CScene_Play::Destroy()
{
	for (int i = 0; i < STAGECOUNT; ++i)
	{
		m_pMap[i]->~CMap();
		delete m_pMap[i];
		m_pMap[i] = nullptr;
	}
}

void CScene_Play::Enter()
{
	system("cls");
}

void CScene_Play::Exit()
{
	system("cls");
}

void CScene_Play::initmap()
{
	// stage메모장 파일을 읽어서 그걸 맵으로 쓸꺼임

	for (int i = 0; i < STAGECOUNT; ++i)
	{
		m_Stage[i] = new CStage();
		m_pMap[i] = m_Stage[i]->Load(i + 1);
		m_pMap[i]->Init();
		m_pPlayer = m_pMap[i]->GetPlayer();
	}	
}

