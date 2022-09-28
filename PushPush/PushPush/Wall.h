#pragma once
#include "GameObject.h"
class CWall :
    public CGameObject
{
public:
    CWall();
    CWall(Pos _vPos);
    ~CWall();

    virtual void Update() override;
    virtual void Render() override;
};

