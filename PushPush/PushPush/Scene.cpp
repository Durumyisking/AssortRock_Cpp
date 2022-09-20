#include "Scene.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}



void CScene::Init(CApplication* _pApplication)
{
	m_pApplication = _pApplication;
	m_Map.Init();
}

void CScene::Init()
{
}

void CScene::Update()
{
	m_Map.Render();
}

void CScene::Render()
{
}

void CScene::Destroy()
{
}

