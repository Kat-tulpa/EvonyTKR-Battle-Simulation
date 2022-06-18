#pragma once

#include "Defs.h"

class TargetingSystem {
private:
public:

	// Defender.target.getForSiege();
	// Targeting.getForDefenderSiege();

	const Type resolveDefenderSiegeTargetPriority(const unsigned int tier) {
		// Siege Prioritizes Other Siege
		if (attacker.hasSiege())
			if (inRangeOfDefenderSiegeAttackerSiege(tier))
				return TYPE_SIEGE;

		// Then Ranged
		if (attacker.hasRanged())
			if (inRangeOfDefenderSiegeAttackerRanged(tier))
				return TYPE_RANGED;

		// Then Mounted
		if (attacker.hasMounted())
			if (inRangeOfDefenderSiegeAttackerMounted(tier))
				return TYPE_MOUNTED;

		// And Lastly Ground
		if (attacker.hasGround())
			if (inRangeOfDefenderSiegeAttackerGround(tier))
				return TYPE_GROUND;
	}
} targetingSystem;