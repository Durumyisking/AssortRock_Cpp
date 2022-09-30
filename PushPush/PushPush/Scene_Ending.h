#pragma once
#include "Scene.h"
class CScene_Ending :
    public CScene
{
public:
	CScene_Ending();
	~CScene_Ending();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual void Enter() override;
	virtual void Exit() override;

private:
	int m_bt;
	int m_ct;
	int m_iLine;
	int m_iRendertext;
	bool m_bIsTextChanged;

};

