#include "Scene_Play.h"
#include "Application.h"
#include "Map.h"

#include "Player.h"

CScene_Play::CScene_Play()
	: m_pPlayer(nullptr)
{
}

CScene_Play::~CScene_Play()
{
}

void CScene_Play::Init()
{
	InitPlayer();
	InitMap(m_pPlayer);
}

void CScene_Play::Update()
{
	m_pPlayer->Update();
//	stage1->SetObj(m_pPlayer->GetPos(), m_pPlayer->GetRenderwc());

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
	_SetCursor(12, 5); wcout <<		L"忙式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	_SetCursor(12, 6); wcout <<		L"弛      PLAY             弛" << endl;
	_SetCursor(12, 7); wcout <<		L"弛            SCENE      弛" << endl;
	_SetCursor(12, 8); wcout <<		L"戌式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	_SetCursor(12, 20); wcout <<	L"Press Enter to be Dead !?" << endl;

	stage1->Render();

}

void CScene_Play::Destroy()
{
	delete stage1;
}

void CScene_Play::InitMap(CPlayer* _pPlayer)
{
	stage1 = new CMap(8, 8);
	stage1->SetPlayer(_pPlayer);
	m_pPlayer->SetMap(stage1);
	wstring Stage1Data = L"";

	//Stage1Data += L"﹛﹛﹥﹥﹥﹛﹛﹛";
	//Stage1Data += L"﹛﹛﹥﹛﹥﹛﹛﹛";
	//Stage1Data += L"﹛﹛﹥﹛﹥﹥﹥﹥";
	//Stage1Data += L"﹥﹥﹥﹛﹛﹛﹛﹥";
	//Stage1Data += L"﹥﹛﹛﹛﹛﹥﹥﹥";
	//Stage1Data += L"﹥﹥﹥﹥﹛﹥﹛﹛";
	//Stage1Data += L"﹛﹛﹛﹥﹛﹥﹛﹛";
	//Stage1Data += L"﹛﹛﹛﹥﹥﹥﹛﹛";

	Stage1Data += L"﹛﹛十十十﹛﹛﹛";
	Stage1Data += L"﹛﹛十﹛十﹛﹛﹛";
	Stage1Data += L"﹛﹛十﹛十十十十";
	Stage1Data += L"十十十﹛﹛﹛﹛十";
	Stage1Data += L"十﹛﹛﹛﹛十十十";
	Stage1Data += L"十十十十﹛十﹛﹛";
	Stage1Data += L"﹛﹛﹛十﹛十﹛﹛";
	Stage1Data += L"﹛﹛﹛十十十﹛﹛";

	stage1->Init(Stage1Data);

}

void CScene_Play::InitPlayer()
{
	m_pPlayer = new CPlayer();
	m_pPlayer->SetPos(Vector2{ 4,4 });
	m_pPlayer->SetRenderwc(L'Ⅴ');
}
