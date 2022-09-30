#include "Application.h"
#include "Scene.h"
#include "Scene_Title.h"
#include "Scene_Play.h"
#include "Scene_Clear.h"
#include "Scene_Dead.h"
#include "Scene_Intro.h"
#include "Scene_StageSelect.h"
#include "Scene_Tutorial.h"
#include "Scene_Ending.h"

CApplication* CApplication::m_Instance = nullptr;

CApplication::CApplication()
	: m_bIsRunning(true)
	, m_arrScene{}
	, m_eCurrentScene(SCENE_TYPE::TITLE)
{
}

CApplication::~CApplication()
{
}

bool CApplication::Init()
{
	m_arrScene[static_cast<UINT>(SCENE_TYPE::INTRO)] = new CScene_Intro();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::TITLE)] = new CScene_Title();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::TUTORIAL)] = new CScene_Tutorial();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::STAGE_SELECT)] = new CScene_StageSelect();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::PLAY)] = new CScene_Play();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::CLEAR)] = new CScene_Clear();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::DEAD)] = new CScene_Dead();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::ENDING)] = new CScene_Ending();



	for (size_t i = 0; i < static_cast<UINT>(SCENE_TYPE::END); i++)
	{
		m_arrScene[i]->Init();
	}



	return true;
}

void CApplication::Update()
{
	m_arrScene[static_cast<UINT>(m_eCurrentScene)]->Update();
}

void CApplication::Rendering()
{

	m_arrScene[static_cast<UINT>(m_eCurrentScene)]->Render();		// ÇöÀç¾À ·»´õ¸µ

	Sleep(200);														// cpu 0.5ÃÊµ¿¾È ¸ØÃã
}

void CApplication::Destroy()
{
	for (int i = 0; i < static_cast<int>(SCENE_TYPE::END); i++)
	{
		delete m_arrScene[i];
		m_arrScene[i] = nullptr;
	}
	delete m_Instance;
}

void CApplication::ChangeScene(SCENE_TYPE _eType)
{
	m_arrScene[static_cast<UINT>(m_eCurrentScene)]->Exit();
	m_eCurrentScene = _eType;
	m_arrScene[static_cast<UINT>(m_eCurrentScene)]->Enter();
}

void CApplication::SetDifficulty(STAGE_TYPE _eType)
{
	for (int i = 0; i < static_cast<int>(SCENE_TYPE::END); i++)
	{
		m_arrScene[i]->SetDifficulty(_eType);
	}
}

void CApplication::clear()
{
}
