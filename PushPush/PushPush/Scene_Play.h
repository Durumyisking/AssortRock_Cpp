#pragma once
#include "Scene.h"
#include "Stage.h"
#include <fstream>

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
	virtual void Enter() override;
	virtual void Exit() override;


private:
	void initmap();
	void save()
	{
		ofstream savestage("Saved.txt");
		savestage << m_iCurrentStage;
		savestage.close();
	}
	void load()
	{
		ifstream loadstage("Saved.txt");
		if (loadstage)
		{
			int i = 0;
			loadstage >> i;
			m_iCurrentStage = i;
		}
		loadstage.close();
	};
	void undo();
	void restart();
private:
	CStage* m_Stage[STAGECOUNT];
	
	int		m_iCurrentStage;
};

