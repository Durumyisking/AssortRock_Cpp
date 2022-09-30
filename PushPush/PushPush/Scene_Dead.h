#pragma once
#include "Scene.h"
class CScene_Dead :
    public CScene
{
public:
	CScene_Dead();
	~CScene_Dead();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual void Enter() override;
	virtual void Exit() override;

private:
	int m_bt;
	int m_btRender;

	int m_ct;


};

