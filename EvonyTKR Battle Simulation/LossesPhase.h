#pragma once

#include "Count.h"
#include "Players.h"
#include "Type.h"
#include "Tier.h"

class LossesPhase {
private:
	static Count lossCounts[PLAYER_COUNT][TYPE_COUNT][TIER_COUNT] = { 0 };

public:

	// Core Loss Methods
	static void phase() {
		update();
		stats.update();
	}

	static void update() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
				const Type castedType = Type(type);
				transformPendingIntoLosses(PLAYER_ATTACKER, castedType, tier);
				transformPendingIntoLosses(PLAYER_DEFENDER, castedType, tier);
			}
	}

	static void transformPendingIntoLosses(const Player player,
		const Type type, const unsigned int tier) {
		if (isAttacker(player)) {
			if (attacker.hasTroops(type, tier)) {
				const Count troopCount = attacker.getCount(type, tier);
				const double health = attacker.getHP(type, tier);
				const Count losses = getPending(PLAYER_ATTACKER, type, tier) * troopCount;
				attacker.setCount(type, tier, std::max(
					Count(0), troopCount - losses));
			}
			return;
		}

		if (defender.hasTroops(type, tier)) {
			const Count troopCount = defender.getCount(type, tier);
			const double health = defender.getHP(type, tier);
			const Count losses = getDamageTaken(PLAYER_DEFENDER,
				type, tier) * troopCount;
			defender.setCount(type, tier, std::max(
				Count(0), troopCount - losses));
		}
	}
} losses;