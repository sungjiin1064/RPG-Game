#include <stdio.h>

int playerX;
int playerY;
int monsterX;
int monsterY;

int playerHealth;
int monsterHealth;
int playerAttack;
int monsterAttack;

void playerWin(int x, int y);
void playerDie(int x, int y);

void monsterWin(int x, int y);
void monsterDie(int x, int y);