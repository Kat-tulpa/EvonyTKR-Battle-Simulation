#pragma once

#include "Distance.h"
#include "InRange.h"
#include "AttackPhase.h"
#include "MovementPhase.h"
#include "LossesPhase.h"

#include <iostream>

class Battlefield {
private:
	Distance length;
	Distance speeds[2][TYPE_COUNT];
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
			movementPhase();
			attackPhase();
			lossesPhase();
			printCounts();
			roundCount++;
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
} battlefield;
