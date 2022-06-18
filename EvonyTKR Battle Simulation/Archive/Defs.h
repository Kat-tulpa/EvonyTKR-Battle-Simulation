#pragma once

// Tier
enum Tier { T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TNULL };
static constexpr unsigned int TIER_COUNT = 15;

// Type
enum Type { TYPE_MOUNTED, TYPE_GROUND, TYPE_RANGED, TYPE_SIEGE, TYPE_NULL };
static constexpr unsigned int TYPE_COUNT = 4;

// Player
enum PlayerType { PLAYER_ATTACKER, PLAYER_DEFENDER };
static constexpr unsigned int PLAYER_COUNT = 2;

// Count
typedef long long Count;

// Distance
typedef long long Distance;

// Attribute
enum ATTRIBUTE { ATTRIBUTE_ATTACK, ATTRIBUTE_DEFENSE, ATTRIBUTE_HP };
static unsigned int constexpr ATTRIBUTE_COUNT = 3;
typedef unsigned long long Attribute;
