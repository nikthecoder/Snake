#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <unistd.h>
using namespace std;

int height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

void generateFruit() {
    fruitx = 1 + rand() % (width - 2);
    fruity = 1 + rand() % (height - 2);
}

void setup() {
    gameover = 0;
    x = height / 2;
    y = width / 2;
    generateFruit();
    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                cout << "#";
            } else {
                if (i == x && j == y)
                    cout << "0";
                else if (i == fruitx && j == fruity)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
    cout << "score = " << score << endl;
    cout << "press X to quit the game" << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic() {
    sleep(0.01);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x >= height || y < 0 || y >= width)
        gameover = 1;

    if (x == fruitx && y == fruity) {
        generateFruit();
        score += 10;
    }
}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    return 0;
}