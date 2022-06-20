#pragma once

#include "Defs.h"

	void tick() {
		tick(TYPE_SIEGE);
		tick(TYPE_RANGED);
		tick(TYPE_GROUND);
		tick(TYPE_MOUNTED);
	}

	// Tick
	void tick(Type type) {
		switch (type) {
		case TYPE_MOUNTED:
			if (enemyTroopInRange(ATTACKER_MOUNTED, DEFENDER_GROUND))
				for 
		}
	}

	void tick(TYPE_SIEFGE) {
		Target target;
		for (unsigned int tier = T1; tier < TIER_COUNT; tier++)
			if (attacker.hasSiege(tier))
				if (tier == T12)
					target = getTargetAttackerSiegeT12();
				else
					target = getTargetAttackerSiege();
	}













	const bool hasValidDefendingSiegeTarget(const Type attackerType, const unsigned int siegeTier) {
		if (defenderHasSiege())
			if (!position.hasCrossed(attackerType, siegeTier))
				if (position.getDistance(attackerType, siegeTier))
					return position.getDistance(attackerType, siegeTier) 
					<= attacker.getRange(attackerType);
	}

	void applyDamageAttackerSiegeAgainstDefendingSiege(
		const unsigned int attackerTier, const unsigned int defenderTier) {

	}

	const unsigned int getAttackerTier() {
		return attackerTier;
	}

	bool trySetAttackerTargetsAll() {

	}

	bool tryResolveAttackerSiegeTarget() {
		// Try To Set Valid Defending Siege Targets By Priority

		// Siege First ----------------------------------------
		// T12 Targets Troop Tiers Top->Bottom
		if (getAttackerTier() == T12)
			for (unsigned int defenderTier = TIER_COUNT; defenderTier > T1; defenderTier--)
				if (trySetAttackingSiegeTarget(defenderTier))
					break;

			if (trySetAttackingSiegeTarget(defender.highestTierSiege()))

		if (hasValidDefendingSiegeTarget())
			if (getAttackerSiegeTier() == T12)
				setAttackerSiegeTarget(
			switch (attackerTier) {
				// T12 Targets Troop Tiers Top->Down
			case T12:
				for (unsigned int defenderTier = TIER_COUNT; defenderTier > T1; defenderTier--)
					if (defenderHasSiege(defenderTier)) {
						dealAttackerSiegeDamageToDefenderSiege(defenderTier);
						break;
					}
				break;
			}
		// Everything Else Targets Troop Tiers Bottom->Up
				default:
					for (unsigned int defenderTier = T1; defenderTier < TIER_COUNT; defenderTier++)
						if (defenderHasSiege(defenderTier))
							if (inRange.attackerSiegeToDefenderSiege())
	}

	void tryPerformAttackingSiegeAgainstDefendingSiege() {
		for (unsigned int attackerTier = T1; attackerTier < TIER_COUNT; attackerTier++) {
			setAttackerTier(attackerTier);

		}
	}

	void acquireAttackerGroundTarget() {
		if ()
	}

	void attack(PLAYER_ROLE player, &TypeTier troop) {
		switch (troop.getType())
	}

	void siegeTick() {
		if (defenderHasSiege)
			performAttackerSiegeAgainstSiege

	}

	void attackerGroundTick() {
		battlefield.
	}

	