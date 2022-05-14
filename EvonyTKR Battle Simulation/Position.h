#pragma once

#include "Players.h"
#include "Type.h"
#include "Distance.h"
#include "Tier.h"

class Position {
private:
	static Distance positions[2][TYPE_COUNT - 1];
	static Distance positionsSiege[2][TIER_COUNT];

public:
	
	// Getters
	static const Distance getPosition(const Player side, const Type type) {
		return positions[side][type];
	}

	static const Distance getPositionAttacker(const Type type) {
		return positions[PLAYER_ATTACKER][type];
	}

	static const Distance getPositionDefender(const Type type) {
		return positions[PLAYER_DEFENDER][type];
	}

	static const Distance distanceToDefenderType(const Distance startDist, const Type type) {
		return positions[PLAYER_DEFENDER][type] - startDist;
	}

	static const Distance distanceToAttackerType(const Distance startPos, const Type type) {
		return startPos - positions[PLAYER_ATTACKER][type];
	}

	static const Distance distanceToNearestEnemy(const Distance startPos, const Player player) {
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

	// Setters
	static void positionAdd(const Type type, const Player player, const Distance length) {
		if (player == PLAYER_ATTACKER)
			positionAddAttacker(type, length);
		else
			positionAddDefender(type, length);
	}

	static void positionAddAttacker(const Type type, const Distance length) {
		positions[PLAYER_ATTACKER][type] += length;
	}

	static void positionAddDefender(const Type type, const Distance length) {
		positions[PLAYER_DEFENDER][type] -= length;
	}

	static void positionSet(const Player player,
		const Type type, const Distance pos) {
		positions[player][type] = pos;
	}

	static void setupPositions() {
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
} position;