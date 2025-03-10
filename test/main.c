#include <stdio.h>
#include <Windows.h>

// 커서 위치 설정 함수
void setCursorPos(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 전역 변수
int playerX = 10, playerY = 10; // 플레이어 위치
int monsterX = 60, monsterY = 10; // 몬스터 위치
int playerHealth = 100, monsterHealth = 50; // 체력
int playerAttack = 9, monsterAttack = 6; // 공격력

// 몬스터 초기화 함수
void resetMonster() {
    monsterX = 60;
    monsterY = 10;
    monsterHealth = 50;
}

// 게임 종료 메시지
void gameOver() {
    setCursorPos(30, 15);
    printf("게임 종료! 플레이어가 패배했습니다.\n");
}

// 전투 애니메이션 출력
void battleAnimation(int playerX, int playerY, int monsterX, int monsterY) {
    setCursorPos(playerX + 8, playerY - 5);
    printf("전투중...");
    setCursorPos(playerX + 11, playerY - 1);
    printf("VS");
}

// 메인 함수
int main() {
    while (1) {
        // 화면 초기화
        system("cls");

        // UI 출력
        setCursorPos(playerX - 4, playerY - 2);
        printf("플레이어 체력: %d", playerHealth);
        setCursorPos(monsterX + 2, monsterY - 2);
        printf("몬스터 체력 : %d", monsterHealth);
        setCursorPos(monsterX, monsterY);
        printf("ㅡ０( '' )"); // 몬스터
        setCursorPos(playerX, playerY);
        printf("( ' ' )ㅡE"); // 플레이어

        // 몬스터 이동 및 전투
        if (monsterX > playerX + 13) {
            monsterX--;
            Sleep(100); // 몬스터 이동 딜레이
        }
        else {
            // 전투 애니메이션
            battleAnimation(playerX, playerY, monsterX, monsterY);

            // 몬스터와 플레이어 체력 감소
            monsterHealth -= playerAttack;
            if (monsterHealth < 0) monsterHealth = 0;

            playerHealth -= monsterAttack;
            if (playerHealth < 0) playerHealth = 0;

            // 몬스터 체력이 0이 되면 표시 후 리젠
            if (monsterHealth <= 0) {
                setCursorPos(monsterX, monsterY - 2);
                printf("MONSTER DOWN! (사망)");
                Sleep(1000); // 사망 대기

                setCursorPos(monsterX, monsterY);
                printf("                   "); // 이전 텍스트 지움
                resetMonster(); // 몬스터 리젠
            }

            // 플레이어 체력이 0이 되면 게임 종료
            if (playerHealth <= 0) {
                gameOver();
                break;
            }
            Sleep(500); // 전투 후 딜레이
        }
    }
    return 0;
}
