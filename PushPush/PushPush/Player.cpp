#include "Player.h"
#include "Map.h"

CPlayer::CPlayer()
{
	m_wcRender = L'¢½';
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update()
{
	inputprocess();
}

void CPlayer::Render()
{
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
			movecheck(WallData[m_vPos.iy - 1][m_vPos.ix], DIR::UP);
			break;
		case 'S': case 's':
			movecheck(WallData[m_vPos.iy + 1][m_vPos.ix], DIR::DOWN);
			break;
		case 'A': case 'a':
			movecheck(WallData[m_vPos.iy][m_vPos.ix - 1], DIR::LEFT);
			break;
		case 'D': case 'd':
			movecheck(WallData[m_vPos.iy][m_vPos.ix + 1], DIR::RIGHT);
			break;

		default:
			break;
		}

	}
}




