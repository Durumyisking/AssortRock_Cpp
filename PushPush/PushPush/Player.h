#pragma once
#include "GameObject.h"

class CMap;

class CPlayer :
    public CGameObject
{
public:
    CPlayer();
   ~CPlayer();

public:
    virtual void Update() override;

    void SetMap(CMap* _pMap);

private:
    void inputprocess();


private:
    CMap* m_pMap;
};

