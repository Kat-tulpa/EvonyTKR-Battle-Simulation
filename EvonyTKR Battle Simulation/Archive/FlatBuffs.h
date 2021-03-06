#pragma once

#include "Defs.h"

class FlatBuffs {
private:
	Attribute flats[TYPE_COUNT][ATTRIBUTE_COUNT] = { 0 };

public:
	// Getters
	const Attribute get(Type type, Attribute attribute) {
		return flats[type][attribute];
	}

	const Attribute getAttack(Type type) {
		return flats[type][ATTRIBUTE_ATTACK];
	}

	const Attribute getDefense(Type type) {
		return flats[type][ATTRIBUTE_DEFENSE];
	}

	const Attribute getHP(Type type) {
		return flats[type][ATTRIBUTE_HP];
	}

	// Setters
	void set(const Type type, const Attribute atk,
		const Attribute def, const Attribute hp) {
		flats[type][ATTRIBUTE_ATTACK] = atk;
		flats[type][ATTRIBUTE_DEFENSE] = def;
		flats[type][ATTRIBUTE_HP] = hp;
	}

	void set(Type type, ATTRIBUTE attribute, Attribute val) {
		flats[type][attribute] = val;
	}

	void setATK(Type type, Attribute atk) {
		flats[type][ATTRIBUTE_ATTACK] = atk;
	}

	void setDEF(Type type, Attribute def) {
		flats[type][ATTRIBUTE_DEFENSE] = def;
	}

	void setHP(Type type, Attribute hp) {
		flats[type][ATTRIBUTE_HP] = hp;
	}
};