#pragma once

#include "Defs.h"
#include "Players.h"

class Position {

private:
	static Distance positions[PLAYER_COUNT][TYPE_COUNT - 1];
	static Distance positionsSiege[PLAYER_COUNT][TIER_COUNT];

public:
	
	// Get Positions
	static const Distance getPosition(const Player, const Type);
	static const Distance getPositionAttacker(const Type);
	static const Distance getPositionDefender(const Type);

	// Get Distance
	static const Distance distanceToNearestEnemy(const Distance, const Player);
	static const Distance distanceToDefenderSiege(const Type, const unsigned int);
	static const Distance distanceToAttackerSiege(const Type, const unsigned int);
	static const Distance distanceToDefenderType(const Distance, const Type);
	static const Distance distanceToAttackerType(const Distance, const Type);

	static void positionSet(const Player, const Type, const Distance);
	static void Add(const Type, const Player, const Distance);
	static const bool hasCrossed(const Type, const Type);
	static void setupPositions();

} position;