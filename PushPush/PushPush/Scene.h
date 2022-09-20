#pragma once
#include "Map.h"


class CApplication;

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	void Init(CApplication* _pApplication);
	virtual void Init() = 0;
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
	

protected:
	CApplication* m_pApplication;
	CMap m_Map;

};

