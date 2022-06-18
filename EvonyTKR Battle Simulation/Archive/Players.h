#pragma once

#include "Buffs.h"
#include "Debuffs.h"
#include "Troops.h"
#include "Defs.h"

class Player {
private:
	Troops TROOPS;
	Buffs BUFFS;
	Debuffs DEBUFFS;

public:

	// Getters
	Buffs& buffs() {
		return BUFFS;
	}

	Debuffs& debuffs() {
		return DEBUFFS;
	}

	Troops& troops() {
		return TROOPS;
	}

	const Distance longestSiegeRange() {
		return troops.longestSiegeRange();
	}

	const Distance longestTroopRange() {
		if (hasSiege())
			return longestSiegeRange() + 200;
		if (hasRanged())
			return 500 + 100;
		return 50;
	}

	const bool hasType(const Type type) {
		return troops().hasType(type);
	}

	const bool hasMounted() {
		return troops().hasMounted();
	}

	const bool hasGround() {
		return troops().hasGround();
	}

	const bool hasRanged() {
		return troops().hasRanged();
	}

	const bool hasSiege() {
		return troops().hasSiege();
	}
};

static Player attacker;
static Player defender;

static void initPlayers() {
	// Attacker Scalar %
	attacker.buffs().scalar().set(TYPE_MOUNTED, 0.0, 0.0, 0.0);
	attacker.buffs().scalar().set(TYPE_GROUND, 0.0, 0.0, 0.0);
	attacker.buffs().scalar().set(TYPE_RANGED, 0.0, 0.0, 0.0);
	attacker.buffs().scalar().set(TYPE_SIEGE, 0.0, 0.0, 0.0);

	// Defender Scalar %
	defender.buffs().scalar().set(TYPE_MOUNTED, 0.0, 0.0, 0.0);
	defender.buffs().scalar().set(TYPE_GROUND, 0.0, 0.0, 0.0);
	defender.buffs().scalar().set(TYPE_RANGED, 0.0, 0.0, 0.0);
	defender.buffs().scalar().set(TYPE_SIEGE, 0.0, 0.0, 0.0);
}