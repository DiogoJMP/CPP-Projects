#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <list>
#include <iterator>
#include "settings.h"

using namespace std;

typedef struct {
	int current_pos[2];
	int previous_pos[2];
} part;


void cls() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void fill(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH]) {

	for (int i = 0;i < MATRIX_WIDTH;i++) {
		matrix[0][i] = 'X';
	}
	for (int i = 1;i < MATRIX_HEIGHT - 1;i++) {
		matrix[i][0] = 'X';
		matrix[i][MATRIX_WIDTH - 1] = 'X';
		for (int j = 1;j < MATRIX_WIDTH - 1;j++) {
			matrix[i][j] = ' ';
		}
	}
	for (int i = 0;i < MATRIX_WIDTH;i++) {
		matrix[MATRIX_HEIGHT - 1][i] = 'X';
	}
}

void draw(char matrix[MATRIX_HEIGHT][MATRIX_WIDTH], int score) {
	for (int i = 0;i < MATRIX_HEIGHT;i++) {
		for (int j = 0;j < MATRIX_WIDTH;j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}

void input(bool arr[]) {
	char input;

	/*
	movingVertically = 0;
	movingHorizontally = 1;
	movingUp = 2;
	movingDown = 3;
	movingLeft = 4;
	movingRight = 5;
	*/

	input = _getch();

	if (arr[0]) {
		if (input == LEFT_KEY) {
			arr[0] = false;
			arr[1] = true;
			arr[2] = false;
			arr[3] = false;
			arr[4] = true;
			arr[5] = false;
		}
		if (input == RIGHT_KEY) {
			arr[0] = false;
			arr[1] = true;
			arr[2] = false;
			arr[3] = false;
			arr[4] = false;
			arr[5] = true;
		}
	}
	if (arr[1]) {
		if (input == UP_KEY) {
			arr[0] = true;
			arr[1] = false;
			arr[2] = true;
			arr[3] = false;
			arr[4] = false;
			arr[5] = false;
		}
		if (input == DOWN_KEY) {
			arr[0] = true;
			arr[1] = false;
			arr[2] = false;
			arr[3] = true;
			arr[4] = false;
			arr[5] = false;
		}
	}

}

int play(char playingArea[MATRIX_HEIGHT][MATRIX_WIDTH]) {
	int score = 0;

	system("cls");

	fill(playingArea);

	bool arr[6] = { true,false,true,false,false,false };

	list<part> snake;
	snake.push_front({ MATRIX_HEIGHT / 2, MATRIX_WIDTH / 2 });

	srand((unsigned int)time(NULL));
	int line = rand() % (MATRIX_HEIGHT - 2) + 1;
	int column = rand() % (MATRIX_WIDTH - 2) + 1;
	playingArea[line][column] = FRUIT;
	int tempx, tempy;

	char tempTail;

	draw(playingArea, score);

	while (true) {
		Sleep(20);
		cls();
		snake.front().previous_pos[0] = snake.front().current_pos[0];
		snake.front().previous_pos[1] = snake.front().current_pos[1];
		playingArea[snake.front().current_pos[0]][snake.front().current_pos[1]] = ' ';
		if (_kbhit()) {
			input(arr);
		}
		if (arr[2]) {
			tempTail = SNAKE_TAIL[2];
			snake.front().current_pos[0]--;
		}
		if (arr[3]) {
			tempTail = SNAKE_TAIL[3];
			snake.front().current_pos[0]++;
		}
		if (arr[4]) {
			tempTail = SNAKE_TAIL[0];
			snake.front().current_pos[1]--;
		}
		if (arr[5]) {
			tempTail = SNAKE_TAIL[1];
			snake.front().current_pos[1]++;
		}

		if (snake.front().current_pos[0] == line && snake.front().current_pos[1] == column) {
			score++;
			snake.push_back({ snake.back().previous_pos[0],snake.back().previous_pos[1] });
			do {
				line = rand() % (MATRIX_HEIGHT - 2) + 1;
				column = rand() % (MATRIX_WIDTH - 2) + 1;
				if (playingArea[line][column] != tempTail) {
					playingArea[line][column] = FRUIT;
				}
			} while (playingArea[line][column] != FRUIT);
		}

		if (playingArea[snake.front().current_pos[0]][snake.front().current_pos[1]] == 'X' ||
			playingArea[snake.front().current_pos[0]][snake.front().current_pos[1]] == tempTail) {
			system("cls");
			cout << "You lost! Your final score was: " << score << endl;
			return -1;
		}
		playingArea[snake.front().current_pos[0]][snake.front().current_pos[1]] = SNAKE_HEAD;
		tempx = snake.front().previous_pos[0];
		tempy = snake.front().previous_pos[1];

		for (list<part>::iterator it = snake.end();it != snake.begin();) {
			--it;
			if (it != snake.begin()) {

				it->previous_pos[0] = it->current_pos[0];
				it->previous_pos[1] = it->current_pos[1];
				it->current_pos[0] = tempx;
				it->current_pos[1] = tempy;
				tempx = it->previous_pos[0];
				tempy = it->previous_pos[1];

				playingArea[it->previous_pos[0]][it->previous_pos[1]] = ' ';
				playingArea[it->current_pos[0]][it->current_pos[1]] = tempTail;

			}
		}

		draw(playingArea, score);
	}
	return 0;
}
