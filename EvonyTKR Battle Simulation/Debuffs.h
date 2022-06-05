#pragma once

#include <algorithm>

class Debuffs {
private:
	ScalarBuffs scalarDebuffs;

public:
	// Init
	void init(Player side) {
		if (isAttacker(side)) {
			// Attacker Scalar %
			setScalar(TYPE_MOUNTED, 0.0, 0.0, 0.0);
			setScalar(TYPE_GROUND , 0.0, 0.0, 0.0);
			setScalar(TYPE_RANGED , 0.0, 0.0, 0.0);
			setScalar(TYPE_SIEGE  , 0.0, 0.0, 0.0);
		}
		else {
			// Defender Scalar %
			setScalar(TYPE_MOUNTED, 0.0, 0.0, 0.0);
			setScalar(TYPE_GROUND , 0.0, 0.0, 0.0);
			setScalar(TYPE_RANGED , 0.0, 0.0, 0.0);
			setScalar(TYPE_SIEGE  , 0.0, 0.0, 0.0);
		}
	}

	// Getters
	const double get(Type type, Attribute attribute) {
		return scalarDebuffs.get(type, attribute);
	}

	// Setters
	void setScalar(const Type type, const double atk,
		const double def, const double hp) {
		scalarDebuffs.set(type, atk, def, hp);
	}

	void setScalarATK(const Type type, const double atk) {
		scalarDebuffs.set(type, ATTRIBUTE_ATTACK, atk);
	}

	void setScalarDEF(const Type type, const double def) {
		scalarDebuffs.set(type, ATTRIBUTE_DEFENSE, def);
	}

	void setScalarHP(const Type type, const double hp) {
		scalarDebuffs.set(type, ATTRIBUTE_HP, hp);
	}
};