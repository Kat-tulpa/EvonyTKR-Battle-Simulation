#pragma once

#include "ScalarValues.h"
#include "FlatBuffs.h"
#include "Players.h"

class Buffs {
private:
	ScalarValues scalarBuffs;
	FlatBuffs flatBuffs;

public:
	// Init
	void init(ScalarValues buffs, FlatBuffs flats) {
		scalarBuffs = buffs;
		flatBuffs = flats;
	}

	// Getters
	ScalarValues scalar() {
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

	// Flat Buffs
	void applyFlatBuffs() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
					// Just Some Shorthand Casts
					const Tier castedTier = Tier(tier); const Type castedType = Type(type);
					const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
					// Actual Logic
					const Attribute currentStats = typeTiers[tier][type].get(castedAttribute);
					const Attribute addedStats = buffs.getFlat(castedType, castedAttribute);
					typeTiers[tier][type].set(castedAttribute, currentStats + addedStats);
				}
	}

	void applyDebuffs(Debuffs debuffs) {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
				// Just Some Shorthand Casts
				const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
				const Type castedType = Type(type);
				// Actual Logic
				const double buff = buffs.getScalar(castedType, castedAttribute);
				const double debuff = debuffs.get(castedType, castedAttribute);
				buffs.setScalar(castedType, castedAttribute, std::max(buff / 2.0, buff - debuff));
			}
	}


	// Apply Buffs & Debuffs
	void applyBuffs() {
		applyScalarBuffs();
		applyFlatBuffs();
	}

	void calculateBuffS() {

	}

	void applyScalarBuffs() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
					// Just Some Shorthand Casts
					const Tier castedTier = Tier(tier); const Type castedType = Type(type);
					const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
					// Actual Logic
					const Attribute defaultStats =
						initialStats.get(castedTier, castedType, castedAttribute);
					const double multiplicationFactor =
						1.0 + buffs.getScalar(castedType, castedAttribute);
					typeTiers[tier][type].set(castedAttribute, defaultStats * multiplicationFactor);
				}
	}

};