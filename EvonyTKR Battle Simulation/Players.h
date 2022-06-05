#pragma once

//#include "Buffs.h"
//#include "Debuffs.h"
//#include "Troops.h"

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

	void updateTroopStats() {
		TROOPS.updateTypeTierStats();
	}

	void tick() {
		siegeTick();
		rangedTick();
		groundTick();
		mountedTick();
	}

	void siegeTick() {

	}

	void rangedTick() {

	}

	void groundTick() {

	}

	void mountedTick() {

	}
};

static Player attacker;
static Player defender;