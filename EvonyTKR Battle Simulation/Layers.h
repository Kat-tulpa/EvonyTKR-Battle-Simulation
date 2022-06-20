#pragma once

#include "Defs.h"
#include "Layer.h"
#include "Buffs.h"

struct Layers {
	Layer layer[TYPE_COUNT][TIER_COUNT];

	LENGTH longestSiegeRange() {
		for (TIER tier = T15; tier > T1; tier--)
			if (hasSiege(tier))
				return startingStats.getSiegeRange(tier);
	}

	LENGTH longestTroopRange() {
		if (hasSiege())
			return longestSiegeRange();
		if (hasRanged())
			return startingStats.getRange(TYPE_RANGED);
		return 50;
	}

	bool hasTroops() {
		for (TYPE type = TYPE_MOUNTED; type < TYPE_COUNT; type++)
			for (TIER tier = T1; tier < TIER_COUNT; tier++)
				if (hasLayer(type, tier))
					return true;
		return false;
	}

	bool hasLayer(const TYPE type, const TIER tier) {
		return layer[type][tier].getCount() > 0;
	}

	bool hasLayer(const TYPE type) {
		for (TIER tier = T1; tier < TIER_COUNT; tier++)
			if (hasLayer(type, tier))
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

	bool hasSiege(const TIER tier) {
		return hasLayer(TYPE_SIEGE, tier);
	}

	bool hasSiege() {
		return hasLayer(TYPE_SIEGE);
	}

	void printCounts() {
		for (TYPE type = TYPE_MOUNTED; type < TYPE_COUNT; type++)
			for (TIER tier = T1; tier < TIER_COUNT; tier++)
				getLayer(type, tier).printCount();
	}
};

static Layers& getLayers(const PLAYER_ROLE player) {
	return layers[player];
}

static bool hasType(const PLAYER_ROLE player, const TYPE type) {
	return layers[player].hasLayer(type);
}

static Layers layers[PLAYER_COUNT];