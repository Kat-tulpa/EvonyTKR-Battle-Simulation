#pragma once

// Tier
static constexpr unsigned int TIER_COUNT = 15;
static enum TIER { T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TNULL };
static TIER& operator++(TIER& tier) {
	// static_cast required because enum + int -> int
	tier = static_cast<TIER>(tier + 1);
	return tier;
}
static TIER& operator--(TIER& tier) {
	// static_cast required because enum + int -> int
	tier = static_cast<TIER>(tier - 1);
	return tier;
}

// Type
static constexpr unsigned int TYPE_COUNT = 4;
static enum TYPE { TYPE_MOUNTED, TYPE_GROUND, TYPE_RANGED, TYPE_SIEGE, TYPE_NULL };
static TYPE& operator++(TYPE& type) {
	// static_cast required because enum + int -> int
	type = static_cast<TYPE>(type + 1);
	return type;
}
static TYPE& operator--(TYPE& type) {
	// static_cast required because enum + int -> int
	type = static_cast<TYPE>(type - 1);
	return type;
}

// Player
static constexpr unsigned int PLAYER_COUNT = 2;
static enum PLAYER_ROLE { PLAYER_ATTACKER, PLAYER_DEFENDER };
static PLAYER_ROLE& operator--(PLAYER_ROLE& player) {
	// static_cast required because enum + int -> int
	player = static_cast<PLAYER_ROLE>(player - 1);
	return player;
}

// Count
typedef long long COUNT;

// Length
typedef long long LENGTH;

// Attribute
static enum ATTRIBUTE_TYPE { ATTRIBUTE_ATTACK, ATTRIBUTE_DEFENSE, ATTRIBUTE_HP };
static unsigned int constexpr ATTRIBUTE_COUNT = 3;
typedef unsigned long long ATTRIBUTE;
