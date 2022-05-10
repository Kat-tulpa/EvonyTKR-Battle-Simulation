#pragma once

#include "Players.h"
#include "Type.h"
#include "Tier.h"
#include "Attribute.h"
#include "Count.h"

class Counts {
	Count counts[PLAYER_COUNT][TYPE_COUNT][TIER_COUNT] = { 0 };

	void setAttackerAndDefenderAllTypes(
		const unsigned int tier, const Count count) {
		for (unsigned int player = 0; player < PLAYER_COUNT; player++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				counts[player][type][tier] = count;
	}

	void setAttackerGround(const unsigned int tier, const Count count) {
		counts[PLAYER_ATTACKER][TYPE_GROUND][tier - 1] = count;
	}

	void setAttackerMounted(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_MOUNTED][tier - 1] = count;
	}

	void setAttackerRanged(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_RANGED][tier - 1] = count;
	}

	void setAttackerSiege(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_SIEGE][tier - 1] = count;
	}

	void setDefenderGround(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_GROUND][tier - 1] = count;
	}

	void setDefenderMounted(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_MOUNTED][tier - 1] = count;
	}

	void setDefenderRanged(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_RANGED][tier - 1] = count;
	}

	void setDefenderSiege(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_SIEGE][tier - 1] = count;
	}
} counts;