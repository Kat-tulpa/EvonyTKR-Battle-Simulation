#pragma once

#include "InitialStats.h"
#include "Stats.h"
#include "Defs.h"

class Troops {
private:

	class TypeTier {
	private:
		Stats stats;
		Count count;
		Type type;
		Tier tier;

	public:
		const Count getCount() {
			return count;
		}

		const Attribute getATK() {
			return stats.getATK();
		}

		const Attribute getDEF() {
			return stats.getDEF();
		}

		const Attribute getHP() {
			return stats.getHP();
		}

		void setATK(Attribute value) {
			stats.setATK(value);
		}

		void setDEF(Attribute value) {
			stats.setDEF(value);
		}

		void setHP(Attribute value) {
			stats.setHP(value);
		}

		const bool hasSiege() {
			for (unsigned int tier = T1; tier < TIER_COUNT; tier++)
				if (TYPETIERS[TYPE_SIEGE][tier].getCount() > 0)
					return true;
			return false;
		}

		void updateStatsAfterLosses() {
			setATK(postBuffStats.getATK(type, tier) * count);
			setDEF(postBuffStats.getDEF(type, tier) * count);
			setHP(postBuffStats.getHP(type, tier) * count);
		}
	};

	Count COUNT;
	TypeTier TYPETIERS[TYPE_COUNT][TIER_COUNT];
	Distance RANGES[TYPE_COUNT];

public:

	// Getters
	const bool hasType(const Type type) {
		for (unsigned int tier = T1; tier < TIER_COUNT; tier++)
			if (TYPETIERS[type][tier].getCount() > 0)
				return true;
		return false;
	}

	const bool hasSiege() {
		return hasType(TYPE_SIEGE);
	}

	const bool hasRanged() {
		return hasType(TYPE_RANGED);
	}

	const bool hasGround() {
		return hasType(TYPE_GROUND);
	}

	const bool hasMounted() {
		return hasType(TYPE_MOUNTED);
	}

	const Count getCount(const Type type, const unsigned int tier) {
		return TYPETIERS[tier][type].getCount();
	}

	const Attribute getHP(const Type type, const unsigned int tier) {
		return TYPETIERS[tier][type].getHP();
	}

	const unsigned int highestTier() {
		return std::max(
			highestTier(TYPE_SIEGE),
			highestTier(TYPE_RANGED),
			highestTier(TYPE_GROUND),
			highestTier(TYPE_MOUNTED)
		);
	}

	const bool hasTypeTier(const Type type, const unsigned int tier) {
		return TYPETIERS[type][tier].getCount() > 0;
	}

	const unsigned int highestTier(const Type type) {
		for (unsigned int tier = TIER_COUNT; tier > T1; tier--)
			if (hasTypeTier(type, tier))
				return tier;
	}

	const bool Distance siegeRange() {
		return RANGES[TYPE_SIEGE];
	}

	const bool Distance rangedRange() {
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

	const Attribute getATKInitial(const Type type, const unsigned int tier) {
		return initalStats.get(type, tier, ATTRIBUTE_ATTACK);
	}

	const Attribute getDEFInitial(const Type type, const unsigned int tier) {
		return initialStats.get(type, tier, ATTRIBUTE_DEFENSE);
	}

	const Attribute getHPInitial(const Type type, const unsigned int tier) {
		return initalStats.get(type, tier, ATTRIBUTE_HP);
	}

	// Setters
	void setCount(const Type type, const unsigned int tier, const Count count) {
		TYPETIERS[tier][type].setCount(count);
	}

	void updateStatsAfterLosses() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = T1; tier < TIER_COUNT; tier++)
				TYPETIERS[type][tier].updateStatsAfterLosses();
	}

	// Helper Functions
	void updateTypeTierStats() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				TYPETIERS[TYPE(type)][tier].updateStats();
	}
};