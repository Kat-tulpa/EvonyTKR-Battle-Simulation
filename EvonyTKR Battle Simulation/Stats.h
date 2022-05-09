#pragma once

#include "Attribute.h"

class Stats {
private:
	Attribute ATK = 0;
	Attribute DEF = 0;
	Attribute HP = 0;

public:

	// Getters
	const Attribute get(const ATTRIBUTE attribute) {
		switch (attribute) {
		case ATTRIBUTE_ATTACK:
			return getATK();
		case ATTRIBUTE_DEFENSE:
			return getDEF();
		case ATTRIBUTE_HP:
			return getHP();
		}
	}

	const Attribute getATK() {
		return ATK;
	}

	const Attribute getDEF() {
		return DEF;
	}

	const Attribute getHP() {
		return HP;
	}

	// Setters
	void setAll(Attribute val) {
		setATK(val);
		setDEF(val);
		setHP(val);
	}

	void set(const ATTRIBUTE attribute, const Attribute val) {
		switch (attribute) {
		case ATTRIBUTE_ATTACK:
			setATK(val);
		case ATTRIBUTE_DEFENSE:
			setDEF(val);
		case ATTRIBUTE_HP:
			setHP(val);
		}
	}

	void set(Attribute atk, Attribute def, Attribute hp) {
		ATK = atk;
		DEF = def;
		HP = hp;
	}

	void setATK(Attribute atk) {
		ATK = atk;
	}

	void setDEF(Attribute def) {
		DEF = def;
	}

	void setHP(Attribute hp) {
		HP = hp;
	}

};