#pragma once
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

const int MATRIX_SIZE = 4;

void cls() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moveUp(int matrix[][MATRIX_SIZE]) {
	for (int i = MATRIX_SIZE - 1;i >= 1;i--) {
		for (int j = 0;j < MATRIX_SIZE;j++) {
			if (matrix[i - 1][j] == 0) {
				matrix[i - 1][j] = matrix[i][j];
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0;i < MATRIX_SIZE - 1;i++) {
		for (int j = 0;j < MATRIX_SIZE;j++) {
			if (matrix[i + 1][j] == matrix[i][j]) {
				matrix[i][j] = matrix[i][j] * 2;
				matrix[i + 1][j] = 0;
			}
		}
	}

}
void moveDown(int matrix[][MATRIX_SIZE]) {
	for (int i = 0;i < MATRIX_SIZE - 1;i++) {
		for (int j = 0;j < MATRIX_SIZE;j++) {
			if (matrix[i + 1][j] == 0) {
				matrix[i + 1][j] = matrix[i][j];
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = MATRIX_SIZE - 1;i >= 1;i--) {
		for (int j = 0;j < MATRIX_SIZE;j++) {
			if (matrix[i - 1][j] == matrix[i][j]) {
				matrix[i][j] = matrix[i][j] * 2;
				matrix[i - 1][j] = 0;
			}
		}
	}
}
void moveLeft(int matrix[][MATRIX_SIZE]) {
	for (int i = 0;i < MATRIX_SIZE;i++) {
		for (int j = MATRIX_SIZE - 1;j >= 1;j--) {
			if (matrix[i][j - 1] == 0) {
				matrix[i][j - 1] = matrix[i][j];
				matrix[i][j] = 0;
			}
		}
		for (int j = 0;j < MATRIX_SIZE - 1;j++) {
			if (matrix[i][j + 1] == matrix[i][j]) {
				matrix[i][j] = matrix[i][j] * 2;
				matrix[i][j + 1] = 0;
			}
		}
	}
}
void moveRight(int matrix[][MATRIX_SIZE]) {
	for (int i = 0;i < MATRIX_SIZE;i++) {
		for (int j = 0;j < MATRIX_SIZE - 1;j++) {
			if (matrix[i][j + 1] == 0) {
				matrix[i][j + 1] = matrix[i][j];
				matrix[i][j] = 0;
			}
		}
		for (int j = MATRIX_SIZE - 1;j >= 1;j--) {
			if (matrix[i][j - 1] == matrix[i][j]) {
				matrix[i][j] = matrix[i][j] * 2;
				matrix[i][j - 1] = 0;
			}
		}
	}
}


int input() {
	int c = 0;
	while (1)
	{
		c = 0;

		switch ((c = _getch())) {
		case KEY_UP:
			return KEY_UP;
			break;
		case KEY_DOWN:
			return KEY_DOWN;
			break;
		case KEY_LEFT:
			return KEY_LEFT;
			break;
		case KEY_RIGHT:
			return KEY_RIGHT;
			break;
		}
	}
	return -1;
}

void draw(int matrix[][MATRIX_SIZE]) {
	for (int i = 0;i < MATRIX_SIZE;i++) {
		for (int j = 0;j < MATRIX_SIZE;j++) {
			if (matrix[i][j] == 0) {
				cout << setw(5) << "|";
			}
			else {
				cout << setw(4) << matrix[i][j] << "|";
			}
		}
		cout << endl;
		for (int j = 0;j < MATRIX_SIZE * 5;j++) {
			cout << '-';
		}
		cout << endl;
	}
}

void fill(int matrix[][MATRIX_SIZE]) {

	unsigned int num = (rand() % (2 + 1)) * 2;

	int p = (int)log2(num);
	num = (int)pow(2, p);

	int row, column;

	srand((unsigned int)time(NULL));

	do {
		row = rand() % (MATRIX_SIZE);
		column = rand() % (MATRIX_SIZE);

		if (matrix[row][column] == 0) {
			matrix[row][column] = num;
		}

	} while (matrix[row][column] != num);

}

int play(int matrix[][MATRIX_SIZE]) {
	int inp;
	fill(matrix);
	draw(matrix);

	while (true) {
		cls();
		inp = input();
		switch (inp) {
		case KEY_UP:
			moveUp(matrix);
			break;
		case KEY_DOWN:
			moveDown(matrix);
			break;
		case KEY_LEFT:
			moveLeft(matrix);
			break;
		case KEY_RIGHT:
			moveRight(matrix);
			break;
		}
		fill(matrix);
		draw(matrix);
	}
	return 0;
}
