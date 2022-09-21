#include "Player.h"
#include "Map.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	inputprocess();
}

void CPlayer::inputprocess()
{
	if (_kbhit())
	{
		char input = _getch();
		wchar_t** WallData = m_pMap->GetWall();
		switch (input)
		{
		case 'W': case 'w':
			if(L'¢Ì' != WallData[m_vPos.iy - 1][m_vPos.ix])
				--m_vPos.iy;
			break;
		case 'S': case 's':
			if (L'¢Ì' != WallData[m_vPos.iy + 1][m_vPos.ix])
				++m_vPos.iy;
			break;
		case 'A': case 'a':
			if (L'¢Ì' != WallData[m_vPos.iy][m_vPos.ix - 1])
				--m_vPos.ix;
			break;
		case 'D': case 'd':
			if (L'¢Ì' != WallData[m_vPos.iy][m_vPos.ix + 1])
				++m_vPos.ix;
			break;

		default:
			break;
		}

	}
}

void CPlayer::SetMap(CMap* _pMap) { m_pMap = _pMap; }

