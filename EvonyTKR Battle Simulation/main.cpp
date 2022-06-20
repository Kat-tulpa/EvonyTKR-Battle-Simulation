#include "Defs.h"
#include "Battlefield.h"
#include "Layers.h"
#include "Buffs.h"

static Layers layers[PLAYER_COUNT];
static FlatBuffs flatBuffs[PLAYER_COUNT];
static ScalarBuffs scalarBuffs[PLAYER_COUNT];
static Battlefield battlefield = Battlefield();

int main() {
	battlefield.battleLoop();
	return 0;
}

static void movementPhase() {
	// Fastest To Slowest
	for (TYPE type = TYPE_MOUNTED; type < TYPE_COUNT; type++) {
		if (attacker.hasTroops(type))
			if (defender.hasTroops(castedType))
				if (getSpeed(PLAYER_ATTACKER, castedType) >
					getSpeed(PLAYER_DEFENDER, castedType))
					tickAttackerDefender(castedType);
				else
					tickDefenderAttacker(castedType);
			else
				tickAttacker(castedType);
		else
			if (defender.hasTroops(castedType))
				tickDefender(castedType);
	}
}

static void move(PLAYER_ROLE player, Layer& layer) {
	if (layer.enemyInRange())
		return;

	troop.addMovement(std::min(distanceToNearestEnemy(player, troop) 
		- troop.getRange(), troop.getSpeed())));
}

static void tick() {
	movementPhase();
	attackPhase();
}

static LENGTH abs(LENGTH value) {
	if (value < 0)
		return -value;
}

