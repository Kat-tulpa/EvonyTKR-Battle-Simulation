#include "Defs.h"
#include "Battlefield.h"
#include "Layers.h"
#include "Buffs.h"

static FlatBuffs flatBuffs[PLAYER_COUNT];
static ScalarBuffs scalarBuffs[PLAYER_COUNT];

int main() {
	battlefield.battleLoop();
	return 0;
}

static LENGTH _abs(LENGTH value) {
	if (value < 0)
		return -value;
}

static LENGTH _min(LENGTH length1, LENGTH length2) {
	if (length1 < length2)
		return length1;
	return length2;
}

static LENGTH _max(LENGTH length1, LENGTH length2) {
	if (length1 > length2)
		return length1;
	return length2;
}
