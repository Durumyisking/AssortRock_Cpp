#include "Application.h"
#include "Scene.h"
#include "Scene_Title.h"
#include "Scene_Play.h"
#include "Scene_Dead.h"

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
	m_arrScene[static_cast<UINT>(SCENE_TYPE::TITLE)] = new CScene_Title();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::PLAY)] = new CScene_Play();
	m_arrScene[static_cast<UINT>(SCENE_TYPE::DEAD)] = new CScene_Dead();

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
	system("cls");													// È­¸é Å¬¸®¾î
	m_arrScene[static_cast<UINT>(m_eCurrentScene)]->Render();		// ÇöÀç¾À ·»´õ¸µ

	Sleep(200);														// cpu 0.5ÃÊµ¿¾È ¸ØÃã
}

void CApplication::Destroy()
{
	for (int i = 0; i < static_cast<int>(SCENE_TYPE::END); i++)
	{
		m_arrScene[i] = nullptr;
	}
}

void CApplication::ChangeScene(SCENE_TYPE _eType)
{
	m_eCurrentScene = _eType;
}

void CApplication::clear()
{
}
