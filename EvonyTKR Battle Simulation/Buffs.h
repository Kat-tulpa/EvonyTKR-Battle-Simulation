#pragma once

#include "Defs.h"

struct FlatBuffs {
	ATTRIBUTE flatBuffs[TYPE_COUNT][ATTRIBUTE_COUNT];

	// Member Functions
	ATTRIBUTE getATK(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_ATTACK];
	}

	ATTRIBUTE getDefenseScalar(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_DEFENSE];
	}

	ATTRIBUTE getHPScalar(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_HP];
	}

	void setATK(TYPE type, ATTRIBUTE atk) {
		flatBuffs[type][ATTRIBUTE_ATTACK] = atk;
	}

	void setDEF(TYPE type, ATTRIBUTE def) {
		flatBuffs[type][ATTRIBUTE_DEFENSE] = def;
	}

	void setHP(TYPE type, ATTRIBUTE hp) {
		flatBuffs[type][ATTRIBUTE_HP] = hp;
	}

	void addATK(TYPE type, ATTRIBUTE atk) {
		flatBuffs[type][ATTRIBUTE_ATTACK] 
			= getATK(type) + atk;
	}

	void addDEF(TYPE type, ATTRIBUTE def) {
		flatBuffs[type][ATTRIBUTE_DEFENSE] 
			= getDEF(type) + def;
	}

	void addHP(TYPE type, ATTRIBUTE hp) {
		flatBuffs[type][ATTRIBUTE_HP]
			= getHP(type) + hp;
	}

	// Static Functions
	static ATTRIBUTE getATK(PLAYER_ROLE player, TYPE type) {
		return flatBuffs[player].getATK(type);
	}

	static ATTRIBUTE getDEF(PLAYER_ROLE player, TYPE type) {
		return flatBuffs[player].getDEF(type);
	}

	static ATTRIBUTE getHP(PLAYER_ROLE player, TYPE type) {
		return flatBuffs[player].getHP(type);
	}

	static void setATK(PLAYER_ROLE player, TYPE type, ATTRIBUTE atk) {
		flatBuffs[player].setATK(type) = atk;
	}

	static void setDEF(PLAYER_ROLE player, TYPE type, ATTRIBUTE def) {
		flatBuffs[player].setDEF(type) = def;
	}

	static void setHP(PLAYER_ROLE player, TYPE type, ATTRIBUTE hp) {
		flatBuffs[player].setHP(type) = hp;
	}
};

struct ScalarBuffs {
	ATTRIBUTE flatBuffs[PLAYER_COUNT][TYPE_COUNT][ATTRIBUTE_COUNT];

	ATTRIBUTE getATK(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_ATTACK];
	}

	ATTRIBUTE getDefenseScalar(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_DEFENSE];
	}

	ATTRIBUTE getHPScalar(TYPE type) {
		return scalarBuffs[type][ATTRIBUTE_HP];
	}

	void setATK(PLAYER_ROLE player, TYPE type, ATTRIBUTE atk) {
		flatBuffs[player][type][ATTRIBUTE_ATTACK] = atk;
	}

	void setDEF(PLAYER_ROLE player, TYPE type, ATTRIBUTE def) {
		flatBuffs[player][type][ATTRIBUTE_DEFENSE] = def;
	}

	void setHP(PLAYER_ROLE player, TYPE type, ATTRIBUTE hp) {
		flatBuffs[player][type][ATTRIBUTE_HP] = hp;
	}

};

static FlatBuffs flatBuffs[PLAYER_COUNT];
static ScalarBuffs scalarBuffs[PLAYER_COUNT];