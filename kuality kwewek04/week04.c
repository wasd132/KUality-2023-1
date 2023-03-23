#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define SIZE 10

int main() {
    int x, y;  // player's position
    int sx, sy; // seeker's position
    char map[SIZE][SIZE]; // game map
    char input; // player input
    int found; // seeker found flag
    int cnt = 0; // count number of moves
    int key = 0;

    // initialize random seed
    srand(time(NULL));

    // initialize game map
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = '. ';
        }
    }

    // set player's position
    x = rand() % SIZE;
    y = rand() % SIZE;
    map[x][y] = 'P';

    // set seeker's position
    do {
        sx = rand() % SIZE;
        sy = rand() % SIZE;
    } while (sx == x && sy == y);
    map[sx][sy] = 'S';

    // game loop
    while (1) {
        // print game map
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // check if seeker found player
        if (x == sx && y == sy) {
            found = 1;
            break;
        }

        // get player input
        printf("Move: ");
        scanf_s(" %c", &input);

        // update player's position
        map[x][y] = '.';
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

        // update seeker's position
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

        // increase move count
        cnt++;

        // check move count
        if (cnt == 50) {
            found = 0;
            break;
        }
        system("CLS");
    }

    // print game result
    if (found)
    {
        printf("\nYou lose!\n");
    }
    else {
        printf("\nYou win!\n");
    }
}