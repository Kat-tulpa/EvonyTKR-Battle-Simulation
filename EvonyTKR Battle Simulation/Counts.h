#pragma once

#include "Players.h"
#include "Type.h"
#include "Tier.h"
#include "Attribute.h"
#include "Count.h"

class Counts {
	Count counts[PLAYER_COUNT][TYPE_COUNT][TIER_COUNT];

	void init() {

		// Attacker Ground
		setCountAttackerGround(1, 0);
		setCountAttackerGround(2, 0);
		setCountAttackerGround(3, 0);
		setCountAttackerGround(4, 0);
		setCountAttackerGround(5, 0);
		setCountAttackerGround(6, 0);
		setCountAttackerGround(7, 0);
		setCountAttackerGround(8, 0);
		setCountAttackerGround(9, 0);
		setCountAttackerGround(10, 0);
		setCountAttackerGround(11, 158323 + 247707);
		setCountAttackerGround(12, 31100);
		setCountAttackerGround(13, 0);
		setCountAttackerGround(14, 0);
		setCountAttackerGround(15, 0);

		// Attacker Mounted
		setCountAttackerMounted(1, 0);
		setCountAttackerMounted(2, 0);
		setCountAttackerMounted(3, 0);
		setCountAttackerMounted(4, 0);
		setCountAttackerMounted(5, 0);
		setCountAttackerMounted(6, 0);
		setCountAttackerMounted(7, 0);
		setCountAttackerMounted(8, 0);
		setCountAttackerMounted(9, 0);
		setCountAttackerMounted(10, 0);
		setCountAttackerMounted(11, 0);
		setCountAttackerMounted(12, 0);
		setCountAttackerMounted(13, 0);
		setCountAttackerMounted(14, 0);
		setCountAttackerMounted(15, 0);
		
		// Atacker Ranged
		setCountAttackerRanged(1, 0);
		setCountAttackerRanged(2, 0);
		setCountAttackerRanged(3, 0);
		setCountAttackerRanged(4, 0);
		setCountAttackerRanged(5, 0);
		setCountAttackerRanged(6, 0);
		setCountAttackerRanged(7, 0);
		setCountAttackerRanged(8, 0);
		setCountAttackerRanged(9, 0);
		setCountAttackerRanged(10, 0);
		setCountAttackerRanged(11, 0);
		setCountAttackerRanged(12, 0);
		setCountAttackerRanged(13, 0);
		setCountAttackerRanged(14, 0);
		setCountAttackerRanged(15, 0);

		// Attacker Siege
		setCountAttackerSiege(1, 0);
		setCountAttackerSiege(2, 0);
		setCountAttackerSiege(3, 0);
		setCountAttackerSiege(4, 0);
		setCountAttackerSiege(5, 0);
		setCountAttackerSiege(6, 0);
		setCountAttackerSiege(7, 0);
		setCountAttackerSiege(8, 0);
		setCountAttackerSiege(9, 0);
		setCountAttackerSiege(10, 0);
		setCountAttackerSiege(11, 0);
		setCountAttackerSiege(12, 0);
		setCountAttackerSiege(13, 0);
		setCountAttackerSiege(14, 0);
		setCountAttackerSiege(15, 0);

		// Defender Ground
		setCountDefenderGround(1, 0);
		setCountDefenderGround(2, 0);
		setCountDefenderGround(3, 0);
		setCountDefenderGround(4, 0);
		setCountDefenderGround(5, 0);
		setCountDefenderGround(6, 0);
		setCountDefenderGround(7, 0);
		setCountDefenderGround(8, 0);
		setCountDefenderGround(9, 0);
		setCountDefenderGround(10, 0);
		setCountDefenderGround(11, 0);
		setCountDefenderGround(12, 0);
		setCountDefenderGround(13, 0);
		setCountDefenderGround(14, 0);
		setCountDefenderGround(15, 0);

		// Defender Mounted
		setCountDefenderMounted(1, 0);
		setCountDefenderMounted(2, 0);
		setCountDefenderMounted(3, 0);
		setCountDefenderMounted(4, 0);
		setCountDefenderMounted(5, 0);
		setCountDefenderMounted(6, 0);
		setCountDefenderMounted(7, 0);
		setCountDefenderMounted(8, 0);
		setCountDefenderMounted(9, 0);
		setCountDefenderMounted(10, 0);
		setCountDefenderMounted(11, 264413);
		setCountDefenderMounted(12, 0);
		setCountDefenderMounted(13, 0);
		setCountDefenderMounted(14, 0);
		setCountDefenderMounted(15, 0);

		// Atacker Ranged
		setCountDefenderRanged(1, 0);
		setCountDefenderRanged(2, 0);
		setCountDefenderRanged(3, 0);
		setCountDefenderRanged(4, 0);
		setCountDefenderRanged(5, 0);
		setCountDefenderRanged(6, 0);
		setCountDefenderRanged(7, 0);
		setCountDefenderRanged(8, 0);
		setCountDefenderRanged(9, 0);
		setCountDefenderRanged(10, 0);
		setCountDefenderRanged(11, 0);
		setCountDefenderRanged(12, 0);
		setCountDefenderRanged(13, 0);
		setCountDefenderRanged(14, 0);
		setCountDefenderRanged(15, 0);

		// Defender Siege
		setCountDefenderSiege(1, 0);
		setCountDefenderSiege(2, 0);
		setCountDefenderSiege(3, 0);
		setCountDefenderSiege(4, 0);
		setCountDefenderSiege(5, 0);
		setCountDefenderSiege(6, 0);
		setCountDefenderSiege(7, 0);
		setCountDefenderSiege(8, 0);
		setCountDefenderSiege(9, 0);
		setCountDefenderSiege(10, 0);
		setCountDefenderSiege(11, 0);
		setCountDefenderSiege(12, 0);
		setCountDefenderSiege(13, 0);
		setCountDefenderSiege(14, 0);
		setCountDefenderSiege(15, 0);

	}

	void setCountAttackerGround(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_GROUND][tier - 1] = count;
	}

	void setCountAttackerMounted(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_MOUNTED][tier - 1] = count;
	}

	void setCountAttackerRanged(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_RANGED][tier - 1] = count;
	}

	void setCountAttackerSiege(unsigned int tier, unsigned int count) {
		counts[PLAYER_ATTACKER][TYPE_SIEGE][tier - 1] = count;
	}

	void setCountDefenderGround(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_GROUND][tier - 1] = count;
	}

	void setCountDefenderMounted(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_MOUNTED][tier - 1] = count;
	}

	void setCountDefenderRanged(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_RANGED][tier - 1] = count;
	}

	void setCountDefenderSiege(unsigned int tier, unsigned int count) {
		counts[PLAYER_DEFENDER][TYPE_SIEGE][tier - 1] = count;
	}
} counts;