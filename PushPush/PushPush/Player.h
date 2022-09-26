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
    virtual void Render() override;


private:
    void inputprocess();


};

