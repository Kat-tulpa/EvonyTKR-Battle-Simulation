#include "Position.h"

	// Get Positions Ranged Ground Mounted
	static const Distance Position::getPosition(
		const Player side, const Type type) {
		return positions[side][type];
	}

	static const Distance Position::getPositionAttacker(const Type type) {
		return positions[PLAYER_ATTACKER][type];
	}

	static const Distance Position::getPositionDefender(const Type type) {
		return positions[PLAYER_DEFENDER][type];
	}

	// Get Positions Siege
	static const Distance Position::getPosition(
		const Player side, const Type type, const unsigned int tier) {
		return positionsSiege[side][tier]
	}

	static const Distance Position::getPositionAttacker(
		const Type type, const unsigned int tier) {
		return positionsSiege[PLAYER_ATTACKER][tier];
	}

	static const Distance Position::getPositionDefender(
		const Type type, const unsigned int tier) {
		return positionsSiege[PLAYER_DEFENDER][tier];
	}

	// Has Crossed?
	static const bool
		Position::hasCrossed(const Type attackerType, const Type defenderType) {
		return getPositionDefender(defenderType)
			- getPositionAttacker(attackerType) < 0;
	}

	// Get Distances Siege
	static const Distance Position::distanceToDefenderSiege(
		const Type attackerType, const unsigned int defenderTier) {
		return getPositionDefender(TYPE_SIEGE, defenderTier)
			- getPositionAttacker(attackerType);
	}

	static const Distance Position::distanceToAttackerSiege(
		const Type defenderType, const unsigned int attackerTier) {
		return getPositionDefender(defenderType)
			- getPositionAttacker(TYPE_SIEGE, attackerTier);
	}

	// Get Distances Ranged Ground Mounted
	static const Distance Position::distanceToDefenderType(
		const Distance startDist, const Type type) {
		return positions[PLAYER_DEFENDER][type] - startDist;
	}

	static const Distance Position::distanceToAttackerType(
		const Distance startPos, const Type type) {
		return startPos - positions[PLAYER_ATTACKER][type];
	}

	// Distance To Nearest Enemy
	static const Distance Position::distanceToNearestEnemy(
		const Distance startPos, const Player player) {
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
	static void Position::positionAdd(const Type type, const Player player, const Distance length) {
		if (player == PLAYER_ATTACKER)
			positionAddAttacker(type, length);
		else
			positionAddDefender(type, length);
	}

	static void Position::positionAdd(const Type type, const Distance length) {
		positions[PLAYER_ATTACKER][type] += length;
	}

	static void 
		Position::positionAddDefender(const Type type, const Distance length) {
		positions[PLAYER_DEFENDER][type] -= length;
	}

	static void 
		Position::positionSet(const Player player,
		const Type type, const Distance pos) {
		positions[player][type] = pos;
	}

	static void 
		Position::setupPositions() {
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