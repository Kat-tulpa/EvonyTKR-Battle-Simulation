#pragma once

static constexpr unsigned int PLAYER_COUNT = 2;
static Side attacker;
static Side defender;

enum Player {
	PLAYER_ATTACKER,
	PLAYER_DEFENDER
};

static const bool isAttacker(Player side) {
	if (side == PLAYER_ATTACKER)
		return true;
	return false;
}

static const bool isDefender(Player side) {
	return !isAttacker(side);
}