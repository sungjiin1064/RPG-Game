#include "Image.h"

char PlayerIdle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"         :    "},
	{"         +    "},
	{"       0/     "},
	{"      /|      "},
	{"      / \\    "}
};
char PlayerMove[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"         :    "},
	{"         +    "},
	{"     __0/     "},
	{"       |      "},
	{"      / \\    "}
};
char PlayerBattle[UNIT_HEIGHT][UNIT_WIDTH + 1] =
{
	{"              "},
	{"              "},
	{"       0__ +--"},
	{"      /|_     "},
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