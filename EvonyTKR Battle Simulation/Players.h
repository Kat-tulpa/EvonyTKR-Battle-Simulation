#pragma once

#include "Buffs.h"
#include "Debuffs.h"
#include "Troops.h"

static Player attacker;
static Player defender;

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



	static const bool isAttacker(PlayerType side) {
		if (side == PLAYER_ATTACKER)
			return true;
		return false;
	}

	static const bool isDefender(PlayerType side) {
		return !isAttacker(side);
	}
};