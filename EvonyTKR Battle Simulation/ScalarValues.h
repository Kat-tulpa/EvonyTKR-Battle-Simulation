#pragma once

class ScalarValues {
private:
	double values[TYPE_COUNT][ATTRIBUTE_COUNT];

public:
	// Getters
	const double get(const Type type, const Attribute attribute) {
		return values[type][attribute];
	}

	const double getATK(const Type type) {
		return values[type][ATTRIBUTE_ATTACK];
	}

	const double getDEF(const Type type) {
		return values[type][ATTRIBUTE_DEFENSE];
	}

	const double getHP(const Type type) {
		return values[type][ATTRIBUTE_HP];
	}

	// Setters
	void set(const Type type, const double atk, const double def, const double hp) {
		values[type][ATTRIBUTE_ATTACK] = atk;
		values[type][ATTRIBUTE_DEFENSE] = def;
		values[type][ATTRIBUTE_HP] = hp;
	}

	void set(const Type type, const ATTRIBUTE attribute, const double buff) {
		values[type][attribute] = buff;
	}

	void setATK(const Type type, const double atk) {
		values[type][ATTRIBUTE_ATTACK] = atk;
	}

	void setDEF(const Type type, const double def) {
		values[type][ATTRIBUTE_DEFENSE] = def;
	}

	void setHP(const Type type, const double hp) {
		values[type][ATTRIBUTE_HP] = hp;
	}
};