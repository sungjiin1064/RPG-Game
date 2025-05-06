
#include "Image.h"

char SwordIdle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"         :    "},
	{"         +    "},
	{"       0/     "},
	{"      /|      "},
	{"      / \\    "}
};
char SwordrMove[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"         :    "},
	{"         +    "},
	{"     __0/     "},
	{"       |      "},
	{"      / \\    "}
};
char SwordBattle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"       0__ +--"},
	{"      /|_     "},
	{"      /  |    "}
};

char ArrowIdle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"       0__|\\ "},
	{"      /|  |/  "},
	{"      / \\    "}
};
char ArrowMove[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"            "},
	{"             "},
	{"     __0/     "},
	{"       |      "},
	{"      / \\    "}
};
char ArrowBattle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"       0__|\\ "},
	{"       |_ |/  "},
	{"      /  |    "}
};

char SlimeIdle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"              "},
	{"              "},
	{"  ( ''  )     "}
};
char SlimeMove[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"              "},
	{"              "},
	{"  ( ''  ) ..  "}  //¡£
};
char SlimeBattle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"              "},
	{"              "},
	{"( ''    )     "}
};

char KingSlimeIdle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"    _ _       "},
	{"  _     _     "},
	{" _ ..     _   "},
	{"_ _ _ _ _ _ _ "}
};
char KingSlimeMove[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"    _ _       "},
	{"  _     _     "},
	{" _ ..     _   "},
	{" _ _ _ _ _ _ _"}
};
char KingSlimeBattle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"   _ _        "},
	{" _     _      "},
	{"_ ..     _    "},
	{" _ _       _  "},
	{"    -- --_ _ _"}
};

