#pragma once

#include "Type.h"
#include "Tier.h"
#include "Players.h"
#include "Attribute.h"
#include "Count.h"

class DamagePending{
private:
	static Attribute damagePending[PLAYER_COUNT][TYPE_COUNT][TIER_COUNT];

public:
	static void reset() {
		for (unsigned int player = 0; player < PLAYER_COUNT; player++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
					damagePending[player][type][tier] = 0;
	}

	static void reset(const Player player) {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				damagePending[player][type][tier] = 0;
	}

	// Getters
	static const Count get(const Player player,
		const Type type, const unsigned int tier) {
		return damagePending[player][type][tier];
	}

	// Setters
	static void set(const Player player, const Type type, 
		const unsigned int tier, const Attribute value) {
		damagePending[player][type][tier] = value;
	}

	static void add(const Player player, const Type type,
		const unsigned int tier, const Attribute value) {
		damagePending[player][type][tier] += value;
	}

} damage;