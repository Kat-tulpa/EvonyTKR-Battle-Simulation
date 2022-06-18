#pragma once

#include "Defs.h"
#include "Players.h"
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

public:

	// Init
	void init() {
		initalizePlayers();
		playersApplyBuffsToThemselves();
		playersApplyDebuffsToEachOther();
		setupBattle();
	}

	void initalizePlayers() {
		attacker.init(PLAYER_ATTACKER);
		defender.init(PLAYER_DEFENDER);
	}

	void playersApplyBuffsToThemselves() {
		attacker.buffs().apply(attacker);
		defender.buffs().apply(defender);
	}

	void playersApplyDebuffsToEachOther() {
		attacker.debuffs().apply(defender);
		defender.debuffs().apply(attacker);
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

} battlefield;
