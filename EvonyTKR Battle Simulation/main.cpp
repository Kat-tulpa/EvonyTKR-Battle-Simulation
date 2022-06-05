#include "Battlefield.h"
#include "InitialStats.h"


void init() {
	initialStats.init();
	battlefield.init();
	battlefield.battleLoop();
}

int main() {
	init();

	return 0;
}


