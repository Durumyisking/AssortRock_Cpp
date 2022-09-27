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


protected:
	CMap* m_pMap;


};

	