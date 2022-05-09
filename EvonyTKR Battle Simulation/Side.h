#pragma once

#include "Buffs.h"
#include "Debuffs.h"
#include "TypeTier.h"
#include "InitialStats.h"

#include <stdint.h>

struct Side {
private:
	TypeTier typeTiers[TIER_COUNT][TYPE_COUNT];
	Buffs buffs;
	Debuffs debuffs;

public:

	// Init
	void init(Player player) {
		buffs.init(player);
		debuffs.init(player);
	}

	// Getters
	Buffs getBuffs() {
		return buffs;
	}

	Debuffs getDebuffs() {
		return debuffs;
	}

	const bool hasTroops() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				if (typeTiers[tier][type].getCount() > 0)
					return true;
		return false;
	}

	const bool hasTroops(const Type type) {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			if (typeTiers[tier][type].getCount() > 0)
				return true;
		return false;
	}

	const bool hasTroops(const Type type, const unsigned int tier) {
		if (typeTiers[tier][type].getCount() > 0)
			return true;
		return false;
	}

	const Count getCount(const Type type, const unsigned int tier) {
		return typeTiers[tier][type].getCount();
	}

	const Attribute getHP(const Type type, const unsigned int tier) {
		return typeTiers[tier][type].getHP();
	}

	const unsigned int highestTier(const Type type) {
		unsigned int highTier = 0;
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			if (hasTroops(type, tier))
				highTier = tier;
		return highTier;
	}

	// Setters
	void setCount(const Type type, const unsigned int tier, const Count count) {
		typeTiers[tier][type].setCount(count);
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

	void updateStats(const Type type, const unsigned int tier) {
		const Attribute atk = initialStats.get(tier, type, ATTRIBUTE_ATTACK);
		const Attribute def = initialStats.get(tier, type, ATTRIBUTE_DEFENSE);
		const Attribute hp = initialStats.get(tier, type, ATTRIBUTE_HP);
		const Count count = getCount(type, tier);
		typeTiers[type][tier].set(atk * count, def * count, hp * count);
	}

	const Distance farthestRange() {
		unsigned int furthestRange = 50;
		if (hasTroops(TYPE_SIEGE))
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				if (hasTroops(TYPE_SIEGE, tier))
					furthestRange = initialStats.getRange(tier) + 200;
		if (hasTroops(TYPE_RANGED))
			furthestRange = 500 + 100;
		return furthestRange;
	}
};