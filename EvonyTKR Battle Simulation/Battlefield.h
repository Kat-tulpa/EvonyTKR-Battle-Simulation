#pragma once

#include "Distance.h"
#include "InRange.h"
#include "Side.h"

#include <iostream>

class Battlefield {
private:
	Distance length;
	Side attacker;
	Side defender;

	Distance positions[2][TYPE_COUNT - 1];
	Distance positionsSiege[2][TIER_COUNT];

	Distance speeds[2][TYPE_COUNT];
	Attribute damageTaken[2][TYPE_COUNT][TIER_COUNT];
	Count roundCount = 0;

// Options
bool showRoundLosses = true;
bool showRoundDamage = true;

public:

	// Init
	void init() {
		attacker.init(PLAYER_ATTACKER);
		defender.init(PLAYER_DEFENDER);
		attacker.applyDebuffs(defender.getDebuffs());
		defender.applyDebuffs(attacker.getDebuffs());
		attacker.applyBuffs();
		defender.applyBuffs();
		setupBattle();
	}

	void setupBattle() {
		setupPositions();
	}

	void positionSet(const Player player, 
		const Type type, const Distance pos) {
		positions[player][type] = pos;
	}

	void setupPositions() {
		Distance attackerStartPos = attacker.farthestRange();
		Distance defenderStartPos = defender.farthestRange();
		const Distance battlefieldLength =
			attackerStartPos + defenderStartPos;
		attackerStartPos = 0;
		defenderStartPos = battlefieldLength;

		// Set Starting Positions For Mounted And Ground
		for (unsigned int type = 0; type < TYPE_RANGED; type++) {
			positionSet(PLAYER_ATTACKER, Type(type), attackerStartPos);
			positionSet(PLAYER_DEFENDER, Type(type), defenderStartPos);
		}


	}

	// Getters 
	const Distance getSpeed(const Player player, const Type type) {
		return speeds[player][type];
	}
	// Position
	const Distance getPosition(const Player side, const Type type) {
		return positions[side][type];
	}

	const Distance getPositionAttacker(const Type type) {
		return positions[PLAYER_ATTACKER][type];
	}

	const Distance getPositionDefender(const Type type) {
		return positions[PLAYER_DEFENDER][type];
	}

	void positionAdd(const Type type, const Player player, const Distance length) {
		if (player == PLAYER_ATTACKER)
			positionAddAttacker(type, length);
		else
			positionAddDefender(type, length);
	}

	void positionAddAttacker(const Type type, const Distance length) {
		positions[PLAYER_ATTACKER][type] += length;
	}

	void positionAddDefender(const Type type, const Distance length) {
		positions[PLAYER_DEFENDER][type] -= length;
	}

	const Distance distanceToDefenderType(const Distance startDist, const Type type) {
		return positions[PLAYER_DEFENDER][type] - startDist;
	}

	const Distance distanceToAttackerType(const Distance startPos, const Type type) {
		return startPos - positions[PLAYER_ATTACKER][type];
	}

	const Distance distanceToNearestEnemy(const Distance startPos, const Player player) {
		if (isAttacker(player))
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				if (defender.hasTroops(Type(type)))
					if (distanceToDefenderType(startPos, Type(type)) >= 0)
						return distanceToDefenderType(startPos, Type(type));
		// If Is Defender
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			if (attacker.hasTroops(Type(type)))
				if (distanceToAttackerType(startPos, Type(type)) >= 0)
					return distanceToAttackerType(startPos, Type(type));
	}

	// Movement
	void movementTickAttackerDefender(const Type type) {
		movementTickAttacker(type);
		movementTickDefender(type);
	}

	void movementTickDefenderAttacker(const Type type) {
		movementTickDefender(type);
		movementTickAttacker(type);
	}

	void movementTickAttacker(const Type type) {
		const Distance position = getPositionAttacker(type);
		const Distance distanceToTarget = distanceToNearestEnemy(position, PLAYER_ATTACKER);
		const Distance moved = std::min(distanceToTarget, getSpeed(PLAYER_ATTACKER, type));
		positionAddAttacker(type, moved);
	}

	void movementTickDefender(const Type type) {
		const Distance position = getPositionDefender(type);
		const Distance distanceToTarget = distanceToNearestEnemy(position, PLAYER_DEFENDER);
		const Distance moved = std::min(distanceToTarget, getSpeed(PLAYER_DEFENDER, type));
		positionAddDefender(type, moved);
	}

	void movementPhase() {
		// Fastest To Slowest
		for (unsigned int type = 0; type < TYPE_COUNT; type++) {
			const Type castedType = Type(type);
			if (attacker.hasTroops(castedType))
				if (defender.hasTroops(castedType))
					if (getSpeed(PLAYER_ATTACKER, castedType) > 
						getSpeed(PLAYER_DEFENDER, castedType))
						movementTickAttackerDefender(castedType);
					else
						movementTickDefenderAttacker(castedType);
				else
					movementTickAttacker(castedType);
			else
				if (defender.hasTroops(castedType))
					movementTickDefender(castedType);
		}
	}

	void resetDamageTaken() {
		for (unsigned int player = 0; player < PLAYER_COUNT; player++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
					damageTaken[player][type][tier] = 0;
	}



	void dealDamageToDefender(const Type attackingType,
		const unsigned int attackingTier, const Type defendingType, 
		const unsigned int defendingTier) {

	}

	void dealDamageToAttacker(const Type attackingType,
		const unsigned int attackingTier, const Type defendingType,
		const unsigned int defendingTier) {

	}

	

	void attackPhaseAttackerSiege() {
		if (!attacker.hasTroops(TYPE_SIEGE))
			return;

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
			// Target Acquisition
			if (defender.hasTroops(TYPE_SIEGE) 
				&& inRangeSiegeTargetDefender(TYPE_SIEGE, tier))
					dealDamageToDefender(TYPE_SIEGE, tier, TYPE_SIEGE, 
						defender.highestTier(TYPE_SIEGE));
			else if (defender.hasTroops(TYPE_RANGED) 
				&& inRangeSiegeTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_SIEGE, tier, TYPE_RANGED,
					defender.highestTier(TYPE_RANGED));
			else if (defender.hasTroops(TYPE_MOUNTED) 
				&& inRangeSiegeTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_SIEGE, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasTroops(TYPE_GROUND)
				&& inRangeSiegeTargetDefender(TYPE_GROUND, tier))
				dealDamageToDefender(TYPE_SIEGE, tier, TYPE_GROUND,
					defender.highestTier(TYPE_GROUND));
		}
	}

	void attackPhaseAttackerRanged() {
		if (!attacker.hasTroops(TYPE_RANGED))
			return;

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
			// Target Acquisition
			if (defender.hasTroops(TYPE_MOUNTED)
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasTroops(TYPE_RANGED)
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_RANGED,
					defender.highestTier(TYPE_RANGED));
			else if (defender.hasTroops(TYPE_SIEGE)
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_SIEGE,
					defender.highestTier(TYPE_SIEGE));
			else if (defender.hasTroops(TYPE_GROUND)
				&& inRangeRangedTargetDefender(TYPE_RANGED, tier))
				dealDamageToDefender(TYPE_RANGED, tier, TYPE_GROUND,
					defender.highestTier(TYPE_GROUND));
		}
	}

	void attackPhaseAttackerMounted() {
		if (!attacker.hasTroops(TYPE_MOUNTED))
			return;

		for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
			// Target Acquisition
			if (defender.hasTroops(TYPE_GROUND)
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_GROUND,
					defender.highestTier(TYPE_GROUND));
			else if (defender.hasTroops(TYPE_MOUNTED)
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasTroops(TYPE_RANGED)
				&& inRangeMountedTargetDefender(TYPE_MOUNTED, tier))
				dealDamageToDefender(TYPE_MOUNTED, tier, TYPE_MOUNTED,
					defender.highestTier(TYPE_MOUNTED));
			else if (defender.hasTroops(TYPE_SIEGE)
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

	void updateStats() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
				const Type castedType = Type(type);
				attacker.updateStats(castedType, tier);
				defender.updateStats(castedType, tier);
			}
		attacker.applyBuffs();
		defender.applyBuffs();
	}

	const Count getDamageTaken(const Player player, 
		const Type type, const unsigned int tier) {
		return damageTaken[player][type][tier];
	}

	void calculateSetLosses(const Player player, 
		const Type type, const unsigned int tier) {
		if (isAttacker(player)) {
			if (attacker.hasTroops(type, tier)) {
				const Count troopCount = attacker.getCount(type, tier);
				const double health = attacker.getHP(type, tier);
				const Count losses = getDamageTaken(PLAYER_ATTACKER,
					type, tier) * troopCount;
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

	void lossesPhase() {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++) {
				const Type castedType = Type(type);
				calculateSetLosses(PLAYER_ATTACKER, castedType, tier);
				calculateSetLosses(PLAYER_DEFENDER, castedType, tier);
			}
		updateStats();
	}

	void printCounts() {
		std::cout << "ATTACKER: " << std::endl;
		for (unsigned int type = 0; type < TYPE_COUNT; type++) {
			std::cout << "Type " << type << std::endl;
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				std::cout << " Tier: " << tier
				<< attacker.getCount(Type(type), tier) << std::endl;
		}
		std::cout << std::endl << "DEFENDER: " << std::endl;
		for (unsigned int type = 0; type < TYPE_COUNT; type++) {
			std::cout << "Type " << type << std::endl;
			for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
				std::cout << " Tier: " << tier
				<< defender.getCount(Type(type), tier) << std::endl;
		}
	}

	void battleLoop() {
		while (attacker.hasTroops() && defender.hasTroops()) {
			movementPhase();
			attackPhase();
			lossesPhase();
			printCounts();
			roundCount++;
		}
	}
} battlefield;
