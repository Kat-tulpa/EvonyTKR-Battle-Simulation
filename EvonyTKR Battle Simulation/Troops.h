#pragma once

#include "Stats.h"
#include "Defs.h"

class Troops {
private:

	class TypeTier {
		Stats stats;
		Count count;
		Type type;
		Tier tier;
	};

	Count COUNT;
	TypeTier TYPETIERS[TYPE_COUNT][TIER_COUNT];
	Distance RANGES[TYPE_COUNT];

public:

	// Getters
	const bool has() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				if (TYPETIERS[tier][type].getCount() > 0)
					return true;
		return false;
	}

	const bool hasTroops(const Type type) {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			if (TYPETIERS[tier][type].getCount() > 0)
				return true;
		return false;
	}

	const bool hasTroops(const Type type, const unsigned int tier) {
		return TYPETIERS[tier][type].getCount() > 0;	}

	const Count getCount(const Type type, const unsigned int tier) {
		return TYPETIERS[tier][type].getCount();
	}

	const Attribute getHP(const Type type, const unsigned int tier) {
		return TYPETIERS[tier][type].getHP();
	}

	const unsigned int highestTier(const Type type) {
		unsigned int highTier = 0;
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			if (hasTroops(type, tier))
				highTier = tier;
		return highTier;
	}

	const bool hasSiege() {
		return hasTroops(TYPE_SIEGE);
	}

	const hasRanged() {
		return hasTroops(TYPE_RANGED);
	}

	const Distance siegeRange() {
		return RANGES[TYPE_SIEGE];
	}

	const Distance rangedRange() {
		return RANGES[TYPE_RANGED];
	}

	const Distance meleeRange() {
		return 50;
	}

	const Distance farthestRange() {
		if (hasSiege)
			return siegeRange();
		if (hasRanged)
			return rangedRange();
		return meleeRange();
	}

	if (hasTroops(TYPE_SIEGE))
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			if (hasTroops(TYPE_SIEGE, tier))
				furthestRange = initialStats.getRange(tier) + 200;
	if (hasTroops(TYPE_RANGED))
		furthestRange = 500 + 100;
	return furthestRange;

	// Setters
	void setCount(const Type type, const unsigned int tier, const Count count) {
		TYPETIERS[tier][type].setCount(count);
	}

	void updateStats(const Type type, const unsigned int tier) {
		const Attribute atk = initialStats.get(tier, type, ATTRIBUTE_ATTACK);
		const Attribute def = initialStats.get(tier, type, ATTRIBUTE_DEFENSE);
		const Attribute hp = initialStats.get(tier, type, ATTRIBUTE_HP);
		const Count count = getCount(type, tier);
		TYPETIERS[type][tier].set(atk * count, def * count, hp * count);
	}

	// Helper Functions
	void updateTypeTierStats() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				TYPETIERS[TYPE(type)][tier].updateStats();
	}
};