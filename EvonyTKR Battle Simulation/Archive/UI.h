#pragma once

#include "Players.h"

class UI {
private:
	// Options
	const bool showRoundLosses = true;
	const bool showRoundDamage = true;

public:
	static void attackerDefaults() {
		// BUFF FORMAT: ATK, DEF, HP
		// Init Attacker % Buffs
		attacker.buffs().scalar().setMounted(0.0f, 0.0f, 0.0f);
		attacker.buffs().scalar().setGround(0.0f, 0.0f, 0.0f);
		attacker.buffs().scalar().setRanged(0.0f, 0.0f, 0.0f);
		attacker.buffs().scalar().setSiege(0.0f, 0.0f, 0.0f);

		// Init Attacker % Buffs
		attacker.buffs().flat().setMounted(0, 0, 0);
		attacker.buffs().flat().setGround(0, 0, 0);
		attacker.buffs().flat().setRanged(0, 0, 0);
		attacker.buffs().flat().setSiege(0, 0, 0);
	}

	static void defenderDefaults() {
		// BUFF FORMAT: ATK, DEF, HP
		// Init Defender % Buffs
		defender.buffs().scalar().setMounted(0.0f, 0.0f, 0.0f);
		defender.buffs().scalar().setGround(0.0f, 0.0f, 0.0f);
		defender.buffs().scalar().setRanged(0.0f, 0.0f, 0.0f);
		defender.buffs().scalar().setSiege(0.0f, 0.0f, 0.0f);

		// Init Defender % Buffs
		defender.buffs().flat().setMounted(0, 0, 0);
		defender.buffs().flat().setGround(0, 0, 0);
		defender.buffs().flat().setRanged(0, 0, 0);
		defender.buffs().flat().setSiege(0, 0, 0);
	}
} ui;