#pragma once

#include "Players.h"
#include "Type.h"
#include "Position.h"

class MovementPhase {
private:

public:

	static void tickAttackerDefender(const Type type) {
		tickAttacker(type);
		tickDefender(type);
	}

	static void tickDefenderAttacker(const Type type) {
		tickDefender(type);
		tickAttacker(type);
	}

	static void tickAttacker(const Type type) {
		const Distance pos = position.getAttacker(type);
		const Distance distanceToTarget = distanceToNearestEnemy(position, PLAYER_ATTACKER);
		const Distance moved = std::min(distanceToTarget, getSpeed(PLAYER_ATTACKER, type));
		positionAddAttacker(type, moved);
	}

	static void tickDefender(const Type type) {
		const Distance position = getPositionDefender(type);
		const Distance distanceToTarget = distanceToNearestEnemy(position, PLAYER_DEFENDER);
		const Distance moved = std::min(distanceToTarget, getSpeed(PLAYER_DEFENDER, type));
		positionAddDefender(type, moved);
	}

	static void phase() {
		// Fastest To Slowest
		for (unsigned int type = 0; type < TYPE_COUNT; type++) {
			const Type castedType = Type(type);
			if (attacker.hasTroops(castedType))
				if (defender.hasTroops(castedType))
					if (getSpeed(PLAYER_ATTACKER, castedType) >
						getSpeed(PLAYER_DEFENDER, castedType))
						tickAttackerDefender(castedType);
					else
						tickDefenderAttacker(castedType);
				else
					tickAttacker(castedType);
			else
				if (defender.hasTroops(castedType))
					tickDefender(castedType);
		}
	}
} movement;