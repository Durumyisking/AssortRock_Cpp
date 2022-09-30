#include "Scene_Play.h"
#include "Application.h"
#include "Map.h"

#include "Player.h"
#include "Ball.h"

CScene_Play::CScene_Play()
	: m_StageEasy{}
	, m_StageHard{}
	, m_iCurrentStage(0)
{
}

CScene_Play::~CScene_Play()
{
	for (int i = 0; i < EASYSTAGE; ++i)
	{
		delete m_StageEasy[i];
		m_StageEasy[i] = nullptr;
	}
	for (int i = 0; i < HARDSTAGE; ++i)
	{
		delete m_StageHard[i];
		m_StageHard[i] = nullptr;
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

	// 클리어 확인
	if (m_pMap[m_iCurrentStage]->IsClear())
		++m_iCurrentStage;


	if (STAGE_TYPE::EASY == g_eCurrentDifficulty)	
		if (EASYSTAGE <= m_iCurrentStage)
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::ENDING);

	else if (STAGE_TYPE::HARD == g_eCurrentDifficulty)
		if (HARDSTAGE + EASYSTAGE <= m_iCurrentStage)
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::ENDING);




	if (_kbhit())
	{
		char chInput = 0;
		chInput = _getch();

		switch (chInput)
		{
		// Player Move
		case 'W': case 'w': 
			m_pMap[m_iCurrentStage]->GetPlayer()->InputProcess('W');
			break;
		case 'S': case 's':
			m_pMap[m_iCurrentStage]->GetPlayer()->InputProcess('S');
			break;
		case 'A': case 'a':
			m_pMap[m_iCurrentStage]->GetPlayer()->InputProcess('A');
			break;
		case 'D': case 'd':
			m_pMap[m_iCurrentStage]->GetPlayer()->InputProcess('D');
			break;

		case 'n': case 'N':
			for (size_t i = 0; i < 3; i++)		
				Beep(2500, 200);		
			save();
			break;
		case 'm': case 'M':
			for (size_t i = 0; i < 3; i++)
				Beep(850, 200);
			load();
			break;
		case 'q': case 'Q':
		
			Beep(3000, 100);
			undo();
			break;
		case 'r': case 'R':
		
			Beep(3000, 300);
			restart();
			break;
		case 't': case 'T':
			restart();
			CApplication::GetInst()->ChangeScene(SCENE_TYPE::TITLE);
			break;
		case 27 : // esc(ASCII 27)키 눌렀을때 프로그램 종료
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
	_SetCursor(PRINT_GAP_X, (y + 2));				wcout << L"┌───────────────────────┐"<< endl;
	_SetCursor(PRINT_GAP_X, (y + 3));				wcout << L"│         Stage";
	_SetCursor(PRINT_GAP_X + 15, (y + 3));			wcout <<      m_iCurrentStage + 1;
	_SetCursor(PRINT_GAP_X + 16, (y + 3));			wcout <<                L"        │" << endl;
	_SetCursor(PRINT_GAP_X, (y + 4));				wcout << L"└───────────────────────┘"<< endl;

	SetColor(WINCOLOR::DARK_GREEN);
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Q ] : undo\n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Reset ] : R \n");
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ Esc ] : Exit \n"); // 프로그램 종료
	SetColor(WINCOLOR::BLUE);
	y++;
	_SetCursor((PRINT_GAP_X - 35), y++); printf("[ T ] : Go to Title\n"); //타이틀씬으로


	SetColor(WINCOLOR::GRAY);
	y = 5;
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      ⓦ      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      ↑      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("ⓐ ←    → ⓢ ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      ↓      ");
	_SetCursor((PRINT_GAP_X + 35), y++); printf("      ⓓ      ");

	y++;
	y++;
	SetColor(WINCOLOR::WHITE); 
	_SetCursor((PRINT_GAP_X + 35), y); printf("[ MOVE ] : ");
	SetColor(WINCOLOR::GREEN);
	_SetCursor((PRINT_GAP_X + 47), y++); printf("%d", m_pMap[m_iCurrentStage]->GetPlayer()->GetMove());
	SetColor(WINCOLOR::DARK_BLUE);
	_SetCursor((PRINT_GAP_X + 36), y + 3); printf("[ N ] : Save");
	_SetCursor((PRINT_GAP_X + 36), y + 4); printf("[ M ] : Load");


	m_pMap[m_iCurrentStage]->Render();
}

void CScene_Play::Destroy()
{
	for (int i = 0; i < EASYSTAGE + HARDSTAGE; ++i)
	{
		m_pMap[i]->~CMap();
		delete m_pMap[i];
		m_pMap[i] = nullptr;
	}
}

void CScene_Play::Enter()
{

	if (g_eCurrentDifficulty == STAGE_TYPE::EASY)
		m_iCurrentStage = 0;
	if (g_eCurrentDifficulty == STAGE_TYPE::HARD)
		m_iCurrentStage = 4;

	PlaySoundA("..\\Sounds\\ingame.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
}

void CScene_Play::Exit()
{
	system("cls");
}

/** 각 stage마다 맵 데이터 넣어줌 */
void CScene_Play::initmap()
{
	// stage메모장 파일을 읽어서 그걸 맵으로 쓸꺼임


	for (int i = 0; i < EASYSTAGE; ++i)
	{
		m_StageEasy[i] = new CStage();
		m_pMap[i] = m_StageEasy[i]->Load(STAGE_TYPE::EASY, i + 1);
		m_pMap[i]->Init();
	}	
	for (int i = 0; i < HARDSTAGE; ++i)
	{
		m_StageHard[i] = new CStage();
		m_pMap[i + EASYSTAGE] = m_StageHard[i]->Load(STAGE_TYPE::HARD, i + 1);
		m_pMap[i + EASYSTAGE]->Init();
	}
}

/** player과 Ball의 현재 pos를 prevpos로 */
void CScene_Play::undo()
{
	// Player의 movecount 1줄임
	int iPlayerMove = m_pMap[m_iCurrentStage]->GetPlayer()->GetMove();
	if(iPlayerMove > 0)
		m_pMap[m_iCurrentStage]->GetPlayer()->SetMove(iPlayerMove - 1);


	for (int i = 0; i < m_pMap[m_iCurrentStage]->GetObj(OBJ_TYPE::PLAYER).size(); i++)
	{
		CGameObject* pTemp = m_pMap[m_iCurrentStage]->GetObj(OBJ_TYPE::PLAYER)[i];
		pTemp->SetPos(pTemp->GetPrevPos());
	}
	for (int i = 0; i < m_pMap[m_iCurrentStage]->GetObj(OBJ_TYPE::BALL).size(); i++)
	{
		CGameObject* pTemp = m_pMap[m_iCurrentStage]->GetObj(OBJ_TYPE::BALL)[i];
		pTemp->SetPos(pTemp->GetPrevPos());
	}
}

/** 현재 스테이지에 해당하는 파일을 다시 불러옵니다. */
void CScene_Play::restart()
{
	if (STAGE_TYPE::EASY == g_eCurrentDifficulty)
	{
		m_pMap[m_iCurrentStage] = m_StageEasy[m_iCurrentStage]->Load(STAGE_TYPE::EASY, m_iCurrentStage + 1);
		m_pMap[m_iCurrentStage]->Init();
	}
	else if (STAGE_TYPE::HARD == g_eCurrentDifficulty)
	{
		m_pMap[m_iCurrentStage + EASYSTAGE] = m_StageHard[m_iCurrentStage]->Load(STAGE_TYPE::HARD, m_iCurrentStage + 1);
		m_pMap[m_iCurrentStage + EASYSTAGE]->Init();
	}
}

