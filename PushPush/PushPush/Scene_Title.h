#pragma once
#include "Scene.h"

class CScene_Title :
	public CScene
{
public:
	CScene_Title();
	~CScene_Title();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

};

