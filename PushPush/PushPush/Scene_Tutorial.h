#pragma once
#include "Scene.h"
class CScene_Tutorial :
    public CScene
{
public:
	CScene_Tutorial();
	~CScene_Tutorial();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual void Enter() override;
	virtual void Exit() override;

};

