#pragma once

#include "Players.h"

class LossesPhase {
private:


public:

	// Core Loss Methods
	static void phase() {
		lossesPending.update();
		lossesPending.push();
		attacker.side.stats.update();
		defender.side.stats.update();
	}

	static void transformPendingIntoLosses(const PlayerType player,
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
} lossesPhase;