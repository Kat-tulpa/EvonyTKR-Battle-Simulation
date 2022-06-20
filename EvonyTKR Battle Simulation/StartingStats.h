#pragma once

#include "Defs.h"

class StartingStats {
private:

	static ATTRIBUTE values[TYPE_COUNT][TIER_COUNT][ATTRIBUTE_COUNT];

	void set(TIER tier, TYPE type, ATTRIBUTE atk,
		ATTRIBUTE def, ATTRIBUTE hp) {
		values[type][tier][ATTRIBUTE_ATTACK] = atk;
		values[type][tier][ATTRIBUTE_DEFENSE] = def;
		values[type][tier][ATTRIBUTE_HP] = hp;
	}

	void initGround() {
		//  TIER   TYPE      ATK    DEF   HP
		set(T1, TYPE_GROUND, 100, 300, 600);
		set(T2, TYPE_GROUND, 140, 410, 810);
		set(T3, TYPE_GROUND, 190, 550, 1090);
		set(T4, TYPE_GROUND, 260, 740, 1470);
		set(T5, TYPE_GROUND, 350, 1000, 1980);
		set(T6, TYPE_GROUND, 470, 1350, 2670);
		set(T7, TYPE_GROUND, 630, 1820, 3600);
		set(T8, TYPE_GROUND, 850, 2460, 4860);
		set(T9, TYPE_GROUND, 1150, 3320, 6560);
		set(T10, TYPE_GROUND, 1550, 4480, 8860);
		set(T11, TYPE_GROUND, 1940, 5600, 11080);
		set(T12, TYPE_GROUND, 2425, 7000, 13850);
		set(T13, TYPE_GROUND, 2910, 8400, 16620);
		set(T14, TYPE_GROUND, 3570, 10330, 20440);
		set(T15, TYPE_GROUND, 4230, 11760, 24260);
	}

	void initMounted() {
		//  TIER   TYPE       ATK   DEF   HP
		set(T1, TYPE_MOUNTED, 220, 150, 400);
		set(T2, TYPE_MOUNTED, 300, 200, 540);
		set(T3, TYPE_MOUNTED, 410, 270, 730);
		set(T4, TYPE_MOUNTED, 550, 360, 990);
		set(T5, TYPE_MOUNTED, 740, 490, 1340);
		set(T6, TYPE_MOUNTED, 1000, 660, 1810);
		set(T7, TYPE_MOUNTED, 1350, 890, 2440);
		set(T8, TYPE_MOUNTED, 1820, 1200, 3290);
		set(T9, TYPE_MOUNTED, 2460, 1620, 4440);
		set(T10, TYPE_MOUNTED, 3320, 2190, 5990);
		set(T11, TYPE_MOUNTED, 4150, 2740, 7490);
		set(T12, TYPE_MOUNTED, 5187, 3425, 9362);
		set(T13, TYPE_MOUNTED, 5800, 3830, 10480);
		set(T14, TYPE_MOUNTED, 6670, 4400, 12050);
		set(T15, TYPE_MOUNTED, 7540, 4970, 13620);
	}

	void initRanged() {
		//  TIER   TYPE      ATK   DEF   HP
		set(T1, TYPE_RANGED, 130, 100, 250);
		set(T2, TYPE_RANGED, 180, 140, 340);
		set(T3, TYPE_RANGED, 240, 190, 460);
		set(T4, TYPE_RANGED, 320, 260, 620);
		set(T5, TYPE_RANGED, 430, 350, 840);
		set(T6, TYPE_RANGED, 580, 470, 1130);
		set(T7, TYPE_RANGED, 780, 630, 1530);
		set(T8, TYPE_RANGED, 1050, 850, 2070);
		set(T9, TYPE_RANGED, 1420, 1150, 2790);
		set(T10, TYPE_RANGED, 1920, 1550, 3770);
		set(T11, TYPE_RANGED, 2400, 1940, 4720);
		set(T12, TYPE_RANGED, 3000, 2425, 5900);
		set(T13, TYPE_RANGED, 3450, 2780, 6780);
		set(T14, TYPE_RANGED, 4070, 3280, 8000);
		set(T15, TYPE_RANGED, 4690, 3780, 9220);
	}

	void initSiege() {
		//  TIER   TYPE     ATK    DEF   HP
		set(T1, TYPE_SIEGE, 100, 50, 100);
		set(T2, TYPE_SIEGE, 140, 70, 140);
		set(T3, TYPE_SIEGE, 190, 90, 190);
		set(T4, TYPE_SIEGE, 260, 120, 260);
		set(T5, TYPE_SIEGE, 350, 160, 350);
		set(T6, TYPE_SIEGE, 470, 220, 470);
		set(T7, TYPE_SIEGE, 630, 300, 630);
		set(T8, TYPE_SIEGE, 850, 410, 850);
		set(T9, TYPE_SIEGE, 1150, 550, 1150);
		set(T10, TYPE_SIEGE, 1550, 740, 1550);
		set(T11, TYPE_SIEGE, 1940, 930, 1940);
		set(T12, TYPE_SIEGE, 2425, 1162, 2425);
		set(T13, TYPE_SIEGE, 2780, 1330, 2780);
		set(T14, TYPE_SIEGE, 3280, 1560, 3280);
		set(T15, TYPE_SIEGE, 3780, 1790, 3780);
	}

public:

	StartingStats() {
		initMounted();
		initGround();
		initRanged();
		initSiege();
	}

	LENGTH getRange(TYPE type) {
		if (type == TYPE_RANGED)
			return 500;
		return 50;
	}

	LENGTH getSiegeRange(TIER tier) {
		switch (tier) {
		case T15:
		case T14:
		case T13:
			return 2178;
		case T12:
		case T11:
			return 1867;
		case T10:
		case T9:
			return 1711;
		case T8:
		case T7:
		case T6:
		case T5:
			return 1556;
		default:
			return 1400;
		}
	}
	
};

static StartingStats startingStats = StartingStats();