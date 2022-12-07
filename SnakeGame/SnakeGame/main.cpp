#pragma
#include <iostream>
#include <stdlib.h>
#include "game.h"

using namespace std;

int main() {

	char playingArea[MATRIX_HEIGHT][MATRIX_WIDTH];

	cout << "Press enter to start playing or q to exit" << endl;
	char input = _getch();
	while (1) {
		if (input == ENTER_KEY) {
			int result = play(playingArea);
			if (result == -1) {
				cout << "Press enter to start playing again or q to exit" << endl;
			}
		}
		if (input == QUIT_KEY) {
			break;
		}
		input = _getch();
	}

	return 0;
}



