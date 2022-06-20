#pragma once

struct SingleUnit {
	ATTRIBUTE ATK;
	ATTRIBUTE DEF;
	ATTRIBUTE HP;

	const ATTRIBUTE getATK() {
		return ATK;
	}

	const ATTRIBUTE getDEF() {
		return DEF;
	}

	const ATTRIBUTE getHP() {
		return HP;
	}

	void setATK(ATTRIBUTE atk) {
		ATK = atk;
	}

	void setDEF(ATTRIBUTE def) {
		DEF = def;
	}

	void setHP(ATTRIBUTE hp) {
		HP = hp;
	}

	void addATK(ATTRIBUTE atk) {
		setATK(getATK() + atk);
	}

	void addDEF(ATTRIBUTE def) {
		setDEF(getDEF() + def);
	}

	void addHP(ATTRIBUTE hp) {
		setHP(getHP() + hp);
	}
};