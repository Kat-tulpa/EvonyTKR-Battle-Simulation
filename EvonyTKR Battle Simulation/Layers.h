#pragma once

#include "Defs.h"
#include "Layer.h"

struct Layers {
	Layer layers[TYPE_COUNT][TIER_COUNT];
	Buffs buffs;

	LENGTH longestSiegeRange() {
		for (unsigned int tier = TIER_COUNT; tier > T0; tier--)
			if (hasSiege(tier))
				return startingStats.getSiegeRange(tier);
	}

	LENGTH longestTroopRange() {
		if (hasSiege())
			return longestSiegeRange();
		if (hasRanged())
			return startingStats.getRange(TYPE_RANGED);
		return startingStats.getMeleeRange();
	}

	bool hasSiege(const TIER tier) {
		return troops[TYPE_SIEGE][tier].getCount() > 0;
	}

	bool hasLayer(const TYPE type, const TIER tier) {
		return troops[type][tier].getCount() > 0;
	}

	bool hasLayer(const TYPE type) {
		for (unsigned int tier = T0; i < TIER_COUNT; i++)
			if (layers[type][tier].getCount() > 0)
				return true;
		return false;
	}

	Layer& getLayer(TYPE type, TIER tier) {
		return layer[type][tier];
	}

	bool hasMounted() {
		return hasLayer(TYPE_MOUNTED);
	}

	bool hasGround() {
		return hasLayer(TYPE_GROUND);
	}

	bool hasRanged() {
		return hasLayer(TYPE_RANGED);
	}

	bool hasSiege() {
		return hasLayer(TYPE_SIEGE);
	}
};