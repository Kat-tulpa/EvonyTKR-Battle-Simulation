#include "Battlefield.h"
#include "InitialStats.h"

#include <iostream>
#include <algorithm>

void init() {
	initialStats.init();
	battlefield.init();
	battlefield.battleLoop();
}

int main() {
	init();

	return 0;
}


