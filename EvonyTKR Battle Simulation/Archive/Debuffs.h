#pragma once

#include <algorithm>
#include "ScalarValues.h"

class Debuffs {
private:
	ScalarValues scalarDebuffs;

public:

	// Getters
	const double get(Type type, Attribute attribute) {
		return scalarDebuffs.get(type, attribute);
	}

	// Setters
	void set(const Type type, const double atk,
		const double def, const double hp) {
		scalarDebuffs.set(type, atk, def, hp);
	}

	void setATK(const Type type, const double atk) {
		scalarDebuffs.set(type, ATTRIBUTE_ATTACK, atk);
	}

	void setDEF(const Type type, const double def) {
		scalarDebuffs.set(type, ATTRIBUTE_DEFENSE, def);
	}

	void setHP(const Type type, const double hp) {
		scalarDebuffs.set(type, ATTRIBUTE_HP, hp);
	}
};