#pragma once
#include "Scene.h"
#include "Stage.h"

class CPlayer;

class CScene_Play : 
	public CScene
{
public:
	CScene_Play();
	~CScene_Play();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

private:
	void initmap();

private:
	CPlayer*	m_pPlayer;
	CStage*		m_Stage;
//	CStage*		m_Stage[3];
};

