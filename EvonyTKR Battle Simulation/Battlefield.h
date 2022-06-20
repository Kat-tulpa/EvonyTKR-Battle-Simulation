#pragma once

#include <iostream>
#include "Defs.h"

class Battlefield {
private:
	LENGTH length;

public:
	Battlefield() {
		setLength(getLongestRange());
	}

	const LENGTH getLongestRange() {
		return _max(
			getLayers(PLAYER_ATTACKER).longestTroopRange(),
			getLayers(PLAYER_DEFENDER).longestTroopRange());
	}

	void setLength(LENGTH _length) {
		length = _length;
	}

	const LENGTH getLength() {
		return length;
	}

	void reset() {
		setLength(getLongestRange());
		roundCount = 0;
	}

	void battleLoop() {
		while (bothPlayersHaveTroops()) {
			movementPhase();
			attackPhase();
			roundCount++;
		}
	}

	void printCounts() {
		std::cout << "Round : " << roundCount << std::endl;
		layers[PLAYER_ATTACKER].printCounts();
		layers[PLAYER_DEFENDER].printCounts();
	}

	bool bothPlayersHaveTroops() {
		return attackerHasTroops() && defenderHasTroops();
	}

	bool attackerHasTroops() {
		return layers[PLAYER_ATTACKER].hasTroops();
	}

	bool defenderHasTroops() {
		return layers[PLAYER_DEFENDER].hasTroops();
	}

	//defender == ground, mounted
	//attacker == ground, mounted
	//defender mounted, attacker mounted, defender ground, attacker ground

	// Movement Phase
	void movementPhase() {
		for (TYPE type = TYPE_MOUNTED; type < TYPE_COUNT; type++)
			for (PLAYER_ROLE player = PLAYER_DEFENDER; player > PLAYER_ATTACKER; player--)
					if(getLayers(player).hasLayer(type))
						get
					



			if (hasType[)
				if ()
					for (TYPE type = TYPE_MOUNTED; type < TYPE_COUNT; type++) {
						if (attacker.hasTroops(type))
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

	static void move(PLAYER_ROLE player, Layer& layer) {
		if (layer.enemyInRange())
			return;
		layer.move(_min(layer.distanceToNearestEnemy()
			- layer.getRange(), layer.getSpeed()));
	}

	// Attack Phase

};

static Battlefield battlefield = Battlefield();
static unsigned int roundCount = 0;