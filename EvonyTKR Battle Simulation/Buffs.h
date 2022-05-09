#pragma once

#include "ScalarBuffs.h"
#include "FlatBuffs.h"
#include "Players.h"

class Buffs {
private:
	ScalarBuffs scalarBuffs;
	FlatBuffs flatBuffs;

public:
	// Init
	void init(Player side) {
		if (isAttacker(side)) {
			// Attacker Scalar %
			setScalar(TYPE_MOUNTED, 0.0, 0.0, 0.0);
			setScalar(TYPE_GROUND, 0.0, 0.0, 0.0);
			setScalar(TYPE_RANGED, 0.0, 0.0, 0.0);
			setScalar(TYPE_SIEGE, 0.0, 0.0, 0.0);

			// Attacker Flat +
			setFlat(TYPE_MOUNTED, 0, 0, 0);
			setFlat(TYPE_GROUND, 0, 0, 0);
			setFlat(TYPE_RANGED, 0, 0, 0);
			setFlat(TYPE_SIEGE, 0, 0, 0);
		}
		else {
			// Defender Scalar %
			setScalar(TYPE_MOUNTED, 0.0, 0.0, 0.0);
			setScalar(TYPE_GROUND, 0.0, 0.0, 0.0);
			setScalar(TYPE_RANGED, 0.0, 0.0, 0.0);
			setScalar(TYPE_SIEGE, 0.0, 0.0, 0.0);

			// Defender Flat +
			setFlat(TYPE_MOUNTED, 0, 0, 0);
			setFlat(TYPE_GROUND, 0, 0, 0);
			setFlat(TYPE_RANGED, 0, 0, 0);
			setFlat(TYPE_SIEGE, 0, 0, 0);
		}
	}

	// Getters
	ScalarBuffs scalar() {
		return scalarBuffs;
	}

	FlatBuffs flat() {
		return flatBuffs;
	}

	const Attribute getFlat(const Type type, const ATTRIBUTE attribute) {
		return flatBuffs.get(type, attribute);
	}

	const double getScalar(const Type type, const ATTRIBUTE attribute) {
		return scalarBuffs.get(type, attribute);
	}

	// Setters
	void setScalar(const Type type, const double atk, 
		const double def, const double hp) {
		scalarBuffs.set(type, atk, def, hp);
	}

	void setScalar(const Type type, const ATTRIBUTE attribute, const double val) {
		scalarBuffs.set(type, attribute, val);
	}

	void setScalarATK(const Type type, const double atk) {
		scalarBuffs.set(type, ATTRIBUTE_ATTACK, atk);
	}

	void setScalarDEF(const Type type, const double def) {
		scalarBuffs.set(type, ATTRIBUTE_DEFENSE, def);
	}

	void setScalarHP(const Type type, const double hp) {
		scalarBuffs.set(type, ATTRIBUTE_HP, hp);
	}

	void setFlat(const Type type, const Attribute atk, 
		const Attribute def, const Attribute hp) {
		flatBuffs.set(type, atk, def, hp);
	}

	void setFlatATK(const Type type, const Attribute atk) {
		flatBuffs.set(type, ATTRIBUTE_ATTACK, atk);
	}

	void setFlatDEF(const Type type, const Attribute def) {
		flatBuffs.set(type, ATTRIBUTE_DEFENSE, def);
	}

	void setFlatHP(const Type type, const Attribute hp) {
		flatBuffs.set(type, ATTRIBUTE_HP, hp);
	}
};