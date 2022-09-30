#pragma once
#include "GameObject.h"

class CMap;

class CPlayer :
    public CGameObject
{
public:
    CPlayer();
    CPlayer(Pos _vPos);
public:
    virtual void Update() override;
    virtual void Render() override;

    int GetMove() const { return m_iMove; }

private:
    void inputprocess();

private:
    int m_iMove;
};

