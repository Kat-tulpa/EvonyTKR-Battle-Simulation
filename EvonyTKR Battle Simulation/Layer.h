#pragma once

#include <iostream>

#include "Defs.h"
#include "StartingStats.h"
#include "SingleUnit.h"

struct Layer {
	SingleUnit singleUnit;
	PLAYER_ROLE owner;
	TYPE type;
	TIER tier;
	int position;
	long long count;

	Layer(PLAYER_ROLE _owner, TYPE _type, 
		TIER _tier, unsigned int _count) {
		owner = _owner; type = _type;
		tier = _tier; count = _count;
		init();
	}

	void init() {
		// Apply Starting Stats
		singleUnit.setATK(
			startingStats.getATK(type, tier));
		singleUnit.setDEF(
			startingStats.getDEF(type, tier));
		singleUnit.setHP(
			startingStats.getHP(type, tier));

		// Apply Scalar Buffs
		singleUnit.addATK(getATK() * )

		// Apply Flat Buffs
		singleUnit.addATK(
			flatBuffs.getATK(owner, type));
		singleUnit.addDEF(
			getBuffFlatDEF(owner, type));
		singleUnit.addHP(
			getBuffFlatHP(owner, type));
	}

	void initPosition() {
		if (owner == PLAYER_ATTACKER)
			setPosition(0);
		else
			setPosition(battlefield.getSize());
	}

	const int getRange() {
		if (type == TYPE_SIEGE)
			return startingStats.getSiegeRange(tier);
		return startingStats.getRange(type);
	}

	const int getSpeed() {
		return startingStats.getSpeed(type);
	}

	const TYPE getType() {
		return type;
	}

	const TIER getTier() {
		return tier;
	}

	const LENGTH getPosition() {
		return position;
	}

	const PLAYER_ROLE getOwner() {
		return owner;
	}

	const PLAYER_ROLE getEnemy() {
		if (owner == PLAYER_ATTACKER)
			return PLAYER_DEFENDER;
		return PLAYER_ATTACKER;
	}

	Layer& nearestEnemy() {
		LENGTH smallestDistance = battlefield.getSize();
		Layer* closestEnemy;
		for (TYPE type = TYPE_MOUNTED; type < TYPE_NULL; type++)
		for (TIER tier = T1; tier < TIER_COUNT; tier++) {
			const PLAYER_ROLE enemyOwner = getEnemy();
			Layer& thisEnemy = layers[enemyOwner].getLayer(type, tier);
			const LENGTH enemyPosition = thisEnemy.getPosition();
			const LENGTH distanceTo = abs(enemyPosition - getPosition());
			if (distanceTo < smallestDistance) {
				closestEnemy = &thisEnemy;
				smallestDistance = distanceTo;
			}
			//return clos
		}

		std::cout << "Error: Layer::nearestEnemy() wasn't able to find a nearest enemy?!" << std::endl;
		throw;
	}

	const LENGTH distanceToNearestEnemy() {
		return nearestEnemy().getPosition();
	}

	bool enemyInRange() {
		if (distanceToNearestEnemy() <= getRange())
			return true;
		return false;
	}

	void setPosition(LENGTH _position) {
		position = _position;
	}

	void setOwner(PLAYER_ROLE _owner) {
		owner = _owner;
	}
};