#pragma once

#include "Defs.h"
#include "Target.h"

class Attack {
private:
	class Phase {
	private:
		class Pending {
		private:
		public:
		};

	public:

	};
};

class AttackPhase {
private:
	
public:

	void tick() {
		attackerTick();
		defenderTick();
	}

	void attackerTick() {
		attackerSiegeTick();
		attackerRangedTick();
		attackerGroundTick();
		attackerMountedTick();
	}

	void defenderTick() {
		defenderSiegeTick();
		defenderRangedTick();
		defenderGrundTick();
		defenderMountedTick();
	}

	const bool validTargetAttackerSiegeDefenderSiege(
		const unsigned int attackerTier, const unsigned int defenderTier) {


	}

	// Attacker Siege

	// Get Target

	// Siege
	const Target getTargetAttackerSiegeDefenderSiegeT12() {
		// T12 Prioritizes High->Low
		for (unsigned int defenderTier = TIER_COUNT; defenderTier > T1; defenderTier--)
			if (validTargetAttackerSiegeDefenderSiege(attackerTier, defenderTier))
				return { TYPE_SIEGE, defenderTier };
		return { TYPE_NULL, TNULL };
	}

	const Target getTargetAttackerSiegeDefenderSiege(const unsigned int attackerTier) {
		// Loop Through All Defenders Siege Tiers Low->High
		for (unsigned int defenderTier = T1; defenderTier < TIER_COUNT; defenderTier++)
			if (validTargetAttackerSiegeDefenderSiege(attackerTier, defenderTier))
				return { TYPE_SIEGE, defenderTier };
		return { TYPE_NULL, TNULL };
	}

	// Ranged
	const Target getTargetAttackerSiegeDefenderRangedT12() {
		// T12 Prioritizes High->Low
		for (unsigned int defenderTier = TIER_COUNT; defenderTier > T1; defenderTier--)
			if (validTargetAttackerSiegeDefenderRanged(attackerTier))
				return { TYPE_RANGED, defenderTier };
		return { TYPE_NULL, TNULL };
	}

	const Target getTargetAttackerSiegeDefenderRanged(const unsigned int attackerTier) {
		// Loop Through All Defenders Siege Tiers Low->High
		for (unsigned int defenderTier = T1; defenderTier < TIER_COUNT; defenderTier++)
			if (validTargetAttackerSiegeDefenderRanged(attackerTier))
				return { TYPE_RANGED, defenderTier };
		return { TYPE_NULL, TNULL };
	}

	const Target getTargetAttackerSiegeT12() {
		Target target = getTargetAttackerSiegeDefenderSiegeT12();
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderRangedT12();
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderGroundT12();
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderMountedT12();
		return target;
	}

	const Target getTargetAttackerSiege(const unsigned int tier) {
		Target target = getTargetAttackerSiegeDefenderSiege(tier);
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderRanged(tier);
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderGround(tier);
		if (!target.isNull())
			return target;
		target = getTargetAttackerSiegeDefenderMounted(tier);
		return target;
	}

	// Tick
	void attackerSiegeTick() {
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

	void attackerSiegeTick() {
		if (defenderHasSiege)
			performAttackerSiegeAgainstSiege

	}

	void attackerGroundTick() {
		battlefield.
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