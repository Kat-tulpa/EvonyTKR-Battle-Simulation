#pragma once

#include "Type.h"
#include "Players.h"
#include "Damage.h"
#include "Tier.h"
#include "InRange.h"

class AttackPhase {
private:

public:
	void attackPhaseAttackerSiege() {
		if (!attacker.hasSiege())
			return;

		const Type targetType = acquireAttackerTargetType(TYPE_SIEGE, tier);

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
		
		}
	}

	const Type acquireAttackerTargetType(const unsigned int tier) {
		return resolveAttackerSiegeTargetPriority(tier);
	}

	const Type acquireDefenderTargetType(const unsigned int tier) {
		return resolveDefenderSiegeTargetPriority(tier);
	}

	const Type resolveAttackerSiegeTargetPriority(const unsigned int tier) {
		// Siege Prioritizes Other Siege
		if (defender.hasSiege())
			if (inRangeOfAttackerSiegeDefenderSiege(tier))
				return TYPE_SIEGE;

		// Then Ranged
		if (defender.hasRanged())
			if (inRangeOfAttackerSiegeDefenderRanged(tier))
				return TYPE_RANGED;

		// Then Mounted
		if (defender.hasMounted())
			if (inRangeOfAttackerSiegeDefenderMounted(tier))
				return TYPE_MOUNTED;

		// And Lastly Ground
		if (defender.hasGround())
			if (inRangeOfAttackerSiegeDefenderGround(tier))
				return TYPE_GROUND;
	}

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


	void attackPhaseAttackerRanged() {
		if (!attacker.hasRanged())
			return;

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
			// Target Acquisition
			if (defender.hasMounted()
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasRanged()
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_RANGED,
					defender.highestTier(TYPE_RANGED));
			else if (defender.hasSiege()
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_SIEGE,
					defender.highestTier(TYPE_SIEGE));
			else if (defender.hasGround()
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_GROUND,
					defender.highestTier(TYPE_GROUND));
		}
	}

	void attackPhaseAttackerMounted() {
		if (!attacker.hasMounted())
			return;

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
			// Target Acquisition
			if (defender.hasGround()
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_GROUND,
					defender.highestTier(TYPE_GROUND));
			else if (defender.hasMounted()
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasRanged()
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasSiege()
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_SIEGE,
					defender.highestTier(TYPE_SIEGE));
		}
	}

	void attackPhaseAttacker() {
		attackPhaseAttackerSiege();
		attackPhaseAttackerRanged();
		attackPhaseAttackerMounted();
		attackPhaseAttackerGround();
	}

	void attackPhaseDefender() {
		attackPhaseDefenderSiege();
		attackPhaseDefenderRanged();
		attackPhaseDefenderMounted();
		attackPhaseDefenderGround();
	}

	void attackPhase() {
		resetDamageTaken();
		attackPhaseAttacker();
		attackPhaseDefender();

		if (attackerHasRanged) {
			// Ranged Target Acquisition
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
				if (defenderHasMounted && inRangeAttackerDefender(TYPE_RANGED, tierRange))
					Type target = TYPE_SIEGE;
				else if (defenderHasRanged && inRangeAttackerDefender(TYPE_RANGED, tierRange))
					Type target = TYPE_RANGED;
				else if (defenderHasMounted && inRangeAttackerDefender(TYPE_MOUNTED, tierRange))
					Type target = TYPE_MOUNTED;
				else if (defenderHasGround && inRangeAttackerDefender(TYPE_GROUND, tierRange))
					Type target = TYPE_GROUND;

				else
					break;

				dealDamageAttackerDefender(TYPE_RANGED, tier, target, defender.highestTier(target));
			}
		}
		if (attackerHasMounted) {
			// Mounted Target Acquisition
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
				Type target;
			}
			if (attackerHasGround) {
				// Ground Target Acqusition
				for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
					Type target;
				}


				for (unsigned int type = 0; type < TYPE_COUNT; type++) {
					if (inRangeAttackerDefender(type, TYPE_MOUNTED))
				}
			}
		}
	}
} attackPhase;