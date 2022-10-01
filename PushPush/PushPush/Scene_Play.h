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
			if (STAGE_TYPE::EASY == g_eCurrentDifficulty)
			{
				savestage << 'E';
			}
			else if (STAGE_TYPE::HARD == g_eCurrentDifficulty)
			{
				savestage << 'H';
			}

			savestage << m_iCurrentStage;
			savestage.close();
		
	}
	void load()
	{
	
			ifstream loadstage("Saved.txt");
			if (loadstage)
			{
				char c = '\0';
				loadstage >> c;
				if ('E' == c)
				{
					g_eCurrentDifficulty = STAGE_TYPE::EASY;
				}
				else if ('H' == c)
				{
					g_eCurrentDifficulty = STAGE_TYPE::HARD;
				}

				int i = 0;
				loadstage >> i;
				m_iCurrentStage = i;
			}
			loadstage.close();
		
	};
	void undo();
	void restart();
	void GotoDifficultySelect();
private:
	CStage* m_StageEasy[EASYSTAGE];
	CStage* m_StageHard[HARDSTAGE];
//	STAGE_TYPE m_eStageType;
	
	int		m_iCurrentStage;
	bool	m_bFirstStart;
};

