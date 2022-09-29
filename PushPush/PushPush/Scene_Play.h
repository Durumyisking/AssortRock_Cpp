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
	virtual void Enter() override;
	virtual void Exit() override;


private:
	void initmap();

private:
	CPlayer* m_pPlayer;
	CStage* m_Stage[2];
	
	int		m_iCurrentStage;
};

