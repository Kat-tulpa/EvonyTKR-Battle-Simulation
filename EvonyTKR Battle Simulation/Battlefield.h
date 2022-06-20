#pragma once

#include <iostream>
#include "Defs.h"

class Battlefield {
private:
	LENGTH length;
	unsigned int roundCount = 0;

public:
	Battlefield() {
		setupBattle();
	}

	void resetBattle() {
		layers[]
	}

	// Getters 
	const Distance getSpeed(const Player player, const Type type) {
		return speeds[player][type];
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
			movementPhase.tick();
			attackPhase.tick();
			lossesPhase.tick();
			ui.printCounts();
			roundCount++;
		}
	}

	void updatePlayersTroopStats() {
		attacker.updateTroopStats();
		defender.updateTroopStats();
	}

};
