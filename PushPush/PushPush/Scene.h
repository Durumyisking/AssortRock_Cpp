#pragma once
#include "Map.h"


class CApplication;

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void SetDifficulty(STAGE_TYPE _eType) { g_eCurrentDifficulty = _eType; }


protected:
	// easy개수 hard개수 + 튜토리얼스테이지
	CMap* m_pMap[EASYSTAGE + HARDSTAGE + 1];
	STAGE_TYPE g_eCurrentDifficulty;

};

	