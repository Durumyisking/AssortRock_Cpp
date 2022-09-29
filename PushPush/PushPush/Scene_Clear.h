#pragma once
#include "Scene.h"
class CScene_Clear :
    public CScene
{

public:
	CScene_Clear();
	~CScene_Clear();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual void Enter() override;
	virtual void Exit() override;

};

