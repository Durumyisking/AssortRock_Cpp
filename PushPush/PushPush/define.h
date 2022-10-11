#pragma once

#define PRINT_GAP_X 48
#define PRINT_GAP_Y 3

#define EASYSTAGE 5
#define HARDSTAGE 5



enum class WINCOLOR
{
	BLACK, /* 0 : ��� */
	DARK_BLUE, /* 1 : ��ο� �Ķ� */
	DARK_GREEN, /* 2 : ��ο� �ʷ� */
	DARK_SKY_BLUE, /* 3 : ��ο� �ϴ� */
	DARK_RED, /* 4 : ��ο� ���� */
	DARK_VIOLET, /* 5 : ��ο� ���� */
	DARK_YELLOW, /* 6 : ��ο� ��� */
	GRAY, /* 7 : ȸ�� */
	DARK_GRAY, /* 8 : ��ο� ȸ�� */
	BLUE, /* 9 : �Ķ� */
	GREEN, /* 10 : �ʷ� */
	SKY_BLUE, /* 11 : �ϴ� */
	RED, /* 12 : ���� */
	VIOLET, /* 13 : ���� */
	YELLOW, /* 14 : ��� */
	WHITE, /* 15 : �Ͼ� */
};

enum class SCENE_TYPE
{
	INTRO,
	TITLE,
	STAGE_SELECT,
	PLAY,
	CLEAR,
	ENDING,
	DEAD,

	END,

};

enum class DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	END,

};

enum class OBJ_TYPE
{
	WALL = 0,
	HOUSE,
	BALL,
	PLAYER,
	END,

};


enum class STAGE_TYPE
{
	EASY,
	HARD,
	END,

};
