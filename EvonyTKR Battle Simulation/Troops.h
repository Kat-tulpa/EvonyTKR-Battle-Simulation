#pragma once

#include "defs.h"
#include "Type.h"
#include "Tier.h"
#include "Stats.h"

class Troops {
private:
	class TypeTier {
		Count count;
		Stats stats;
		Type type;
		Tier tier;
	};

	Count count;
	TypeTier typeTiers[TYPE_COUNT][TIER_COUNT];

public:
	const bool has() {
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

	class TypeTier {

	};
};