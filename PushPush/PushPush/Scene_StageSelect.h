#pragma once
#include "Scene.h"


class CScene_StageSelect :
    public CScene
{
public:
	CScene_StageSelect();
	~CScene_StageSelect();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual void Enter() override;
	virtual void Exit() override;

private:
	int m_iArrowLine;


};

