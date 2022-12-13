#pragma once

#include <iostream>
#include <stdlib.h>
#include "game.h"

using namespace std;

int main() {
	int playingArea[MATRIX_SIZE][MATRIX_SIZE] = { 0 };
	play(playingArea);
	return 0;
}