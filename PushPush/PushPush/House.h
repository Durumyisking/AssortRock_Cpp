#pragma once
#include "GameObject.h"
class CHouse :
    public CGameObject
{
public:
    CHouse();
    CHouse(Pos _vPos);
    ~CHouse();

    virtual void Update() override;
    virtual void Render() override;
};

