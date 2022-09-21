#pragma once
#include "Scene.h"

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

	void InitMap(CPlayer* _pPlayer);
	void InitPlayer();

private:
	CPlayer* m_pPlayer;
};

