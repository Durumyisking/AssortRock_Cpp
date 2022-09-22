#include "Scene_Play.h"
#include "Application.h"
#include "Map.h"

#include "Player.h"
#include "Ball.h"

CScene_Play::CScene_Play()
	: m_pPlayer(nullptr)
	, m_Stage(nullptr)
{
}

CScene_Play::~CScene_Play()
{
	delete m_Stage;
}

void CScene_Play::Init()
{
	initplayer();
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
	SetColor(WINCOLOR::DARK_SKY_BLUE);
	_SetCursor(12, 5); wcout <<		L"┌───────────────────────┐" << endl;
	_SetCursor(12, 6); wcout <<		L"│      PLAY             │" << endl;
	_SetCursor(12, 7); wcout <<		L"│            SCENE      │" << endl;
	_SetCursor(12, 8); wcout <<		L"└───────────────────────┘" << endl;
	_SetCursor(12, 20); wcout <<	L"Press Enter to be Dead !?" << endl;

	m_pMap->Render();

}

void CScene_Play::Destroy()
{
	delete m_pMap;
}

void CScene_Play::initmap()
{
	m_pMap = new CMap(8, 8);
	m_pMap->AddGameObject(m_pPlayer);
	m_pPlayer->SetMap(m_pMap);

	CGameObject* pBallObj = new CBall(Pos(3, 4));
	m_pMap->AddGameObject(pBallObj);

	// stage메모장 파일을 읽어서 그걸 맵으로 쓸꺼임
	CStage* stage = new CStage();
	stage->SetMap(m_pMap);
	stage->Load();
	//m_pMap->Init();
}

void CScene_Play::initplayer()
{
	m_pPlayer = new CPlayer();
	m_pPlayer->SetPos(Vector2(4, 4));
}
