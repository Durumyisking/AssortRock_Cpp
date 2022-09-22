#pragma once
#include "GameObject.h"
class CBall :
    public CGameObject
{
public:
    CBall();
    CBall(Pos _vPos);
    ~CBall();

    virtual void Update() override;
    virtual void Render() override;

};

