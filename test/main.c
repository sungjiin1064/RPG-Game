#include <stdio.h>
#include <Windows.h>

// Ŀ�� ��ġ ���� �Լ�
void setCursorPos(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ���� ����
int playerX = 10, playerY = 10; // �÷��̾� ��ġ
int monsterX = 60, monsterY = 10; // ���� ��ġ
int playerHealth = 100, monsterHealth = 50; // ü��
int playerAttack = 9, monsterAttack = 6; // ���ݷ�

// ���� �ʱ�ȭ �Լ�
void resetMonster() {
    monsterX = 60;
    monsterY = 10;
    monsterHealth = 50;
}

// ���� ���� �޽���
void gameOver() {
    setCursorPos(30, 15);
    printf("���� ����! �÷��̾ �й��߽��ϴ�.\n");
}

// ���� �ִϸ��̼� ���
void battleAnimation(int playerX, int playerY, int monsterX, int monsterY) {
    setCursorPos(playerX + 8, playerY - 5);
    printf("������...");
    setCursorPos(playerX + 11, playerY - 1);
    printf("VS");
}

// ���� �Լ�
int main() {
    while (1) {
        // ȭ�� �ʱ�ȭ
        system("cls");

        // UI ���
        setCursorPos(playerX - 4, playerY - 2);
        printf("�÷��̾� ü��: %d", playerHealth);
        setCursorPos(monsterX + 2, monsterY - 2);
        printf("���� ü�� : %d", monsterHealth);
        setCursorPos(monsterX, monsterY);
        printf("�ѣ�( '' )"); // ����
        setCursorPos(playerX, playerY);
        printf("( ' ' )��E"); // �÷��̾�

        // ���� �̵� �� ����
        if (monsterX > playerX + 13) {
            monsterX--;
            Sleep(100); // ���� �̵� ������
        }
        else {
            // ���� �ִϸ��̼�
            battleAnimation(playerX, playerY, monsterX, monsterY);

            // ���Ϳ� �÷��̾� ü�� ����
            monsterHealth -= playerAttack;
            if (monsterHealth < 0) monsterHealth = 0;

            playerHealth -= monsterAttack;
            if (playerHealth < 0) playerHealth = 0;

            // ���� ü���� 0�� �Ǹ� ǥ�� �� ����
            if (monsterHealth <= 0) {
                setCursorPos(monsterX, monsterY - 2);
                printf("MONSTER DOWN! (���)");
                Sleep(1000); // ��� ���

                setCursorPos(monsterX, monsterY);
                printf("                   "); // ���� �ؽ�Ʈ ����
                resetMonster(); // ���� ����
            }

            // �÷��̾� ü���� 0�� �Ǹ� ���� ����
            if (playerHealth <= 0) {
                gameOver();
                break;
            }
            Sleep(500); // ���� �� ������
        }
    }
    return 0;
}
