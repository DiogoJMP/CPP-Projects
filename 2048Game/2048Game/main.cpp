#pragma once

#include <iostream>
#include <stdlib.h>
#include "game.h"

using namespace std;

int main() {
	char opt;
	cout << "Press ENTER key to start playing or q to quit" << endl;
	do {
		opt = _getch();
		if (opt == '\r') {
			system("cls");
			play();
			cout << "Press ENTER to play again or q to quit";
		}
	} while (opt != 'q');

	return 0;
}