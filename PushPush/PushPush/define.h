#pragma once

#define PRINT_GAP_X 48
#define PRINT_GAP_Y 3

#define EASYSTAGE 5
#define HARDSTAGE 5



enum class WINCOLOR
{
	BLACK, /* 0 : 까망 */
	DARK_BLUE, /* 1 : 어두운 파랑 */
	DARK_GREEN, /* 2 : 어두운 초록 */
	DARK_SKY_BLUE, /* 3 : 어두운 하늘 */
	DARK_RED, /* 4 : 어두운 빨강 */
	DARK_VIOLET, /* 5 : 어두운 보라 */
	DARK_YELLOW, /* 6 : 어두운 노랑 */
	GRAY, /* 7 : 회색 */
	DARK_GRAY, /* 8 : 어두운 회색 */
	BLUE, /* 9 : 파랑 */
	GREEN, /* 10 : 초록 */
	SKY_BLUE, /* 11 : 하늘 */
	RED, /* 12 : 빨강 */
	VIOLET, /* 13 : 보라 */
	YELLOW, /* 14 : 노랑 */
	WHITE, /* 15 : 하양 */
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
