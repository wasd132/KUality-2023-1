#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define SIZE 10

int main() {
    int x, y;  // �÷��̾� ��ġ
    int sx, sy; // ���� ��ġ
    char map[SIZE][SIZE]; // ��
    char input; // Ű �Է�
    int found; // seeker found flag
    int cnt = 0; // �������� ī��Ʈ

    // �����Լ�
    srand((unsigned)time(NULL));

    // �� �ʱ�ȭ
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = '.';
        }
    }

    // �÷��̾� ����
    x = rand() % SIZE;
    y = rand() % SIZE;
    map[x][y] = 'P';

    // ���� ����
    do {
        sx = rand() % SIZE;
        sy = rand() % SIZE;
    } while (sx == x && sy == y);
    map[sx][sy] = 'S';

    // ����
    while (1) {
        // ���� ���
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // ����������
        if (x == sx && y == sy) {
            found = 1;
            break;
        }

        // �÷��̾� ������Ʈ
        map[x][y] = '.';
        input = _getch();//Ű�� �޾���
        switch (input) {
        case 'w': x--; break;
        case 's': x++; break;
        case 'a': y--; break;
        case 'd': y++; break;
        }
        if (x < 0)
        {
            x = 0;
        }
        if (x >= SIZE) 
        { 
            x = SIZE - 1;
        }
        if (y < 0)
        {
            y = 0;
        }
        if (y >= SIZE) 
        {
            y = SIZE - 1;
        }
        map[x][y] = 'P';

        // ���� ������Ʈ
        map[sx][sy] = '.';
        if (sx < x)
        {
            sx++;
        }
        else if (sx > x)
        {
            sx--;
        }
        if (sy < y)
        {
            sy++;
        }
        else if (sy > y)
        {
            sy--;
        }
        map[sx][sy] = 'S';

        // ������ ī��Ʈ
        cnt++;

        // ī��Ʈ üũ
        if (cnt == 50) {
            found = 0;
            break;
        }
        system("CLS");
    }

    // ������
    if (found)
    {
        printf("\nYou lose!\n");
    }
    else {
        printf("\nYou win!\n");
    }
}