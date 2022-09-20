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

};

