#pragma once

#include "ScalarValues.h"
#include "Defs.h"

class Buffs {
private:
	ScalarValues SCALAR;
	FlatBuffs FLAT;

	class FlatBuffs {
		private:
			Attribute flats[TYPE_COUNT][ATTRIBUTE_COUNT] = { 0 };

		public:
			// Getters
			const Attribute get(Type type, Attribute attribute) {
				return flats[type][attribute];
			}

			// Setters
			void set(const Type type, const Attribute atk,
				const Attribute def, const Attribute hp) {
				flats[type][ATTRIBUTE_ATTACK] = atk;
				flats[type][ATTRIBUTE_DEFENSE] = def;
				flats[type][ATTRIBUTE_HP] = hp;
			}

			void set(Type type, ATTRIBUTE attribute, Attribute val) {
				flats[type][attribute] = val;
			}

			void setATK(Type type, Attribute atk) {
				flats[type][ATTRIBUTE_ATTACK] = atk;
			}

			void setDEF(Type type, Attribute def) {
				flats[type][ATTRIBUTE_DEFENSE] = def;
			}

			void setHP(Type type, Attribute hp) {
				flats[type][ATTRIBUTE_HP] = hp;
			}
		};

public:
	// Getters
	ScalarValues& scalar() {
		return SCALAR;
	}

	FlatBuffs& flat() {
		return FLAT;
	}

	// Flat Buffs
	void applyFlatBuffs() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
					// Just Some Shorthand Casts
					const Tier castedTier = Tier(tier); const Type castedType = Type(type);
					const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
					// Actual Logic
					const Attribute currentStats = typeTiers[tier][type].get(castedAttribute);
					const Attribute addedStats = buffs.getFlat(castedType, castedAttribute);
					typeTiers[tier][type].set(castedAttribute, currentStats + addedStats);
				}
	}

	void applyDebuffs(Debuffs debuffs) {
		for (unsigned int type = 0; type < TYPE_COUNT; type++)
			for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
				// Just Some Shorthand Casts
				const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
				const Type castedType = Type(type);
				// Actual Logic
				const double buff = buffs.getScalar(castedType, castedAttribute);
				const double debuff = debuffs.get(castedType, castedAttribute);
				buffs.setScalar(castedType, castedAttribute, std::max(buff / 2.0, buff - debuff));
			}
	}


	// Apply Buffs & Debuffs
	void applyBuffs() {
		applyScalarBuffs();
		applyFlatBuffs();
	}

	void calculateBuffS() {

	}

	void applyScalarBuffs() {
		for (unsigned int tier = 0; tier < TIER_COUNT; tier++)
			for (unsigned int type = 0; type < TYPE_COUNT; type++)
				for (unsigned int attribute = 0; attribute < ATTRIBUTE_COUNT; attribute++) {
					// Just Some Shorthand Casts
					const Tier castedTier = Tier(tier); const Type castedType = Type(type);
					const ATTRIBUTE castedAttribute = ATTRIBUTE(attribute);
					// Actual Logic
					const Attribute defaultStats =
						initialStats.get(castedTier, castedType, castedAttribute);
					const double multiplicationFactor =
						1.0 + buffs.getScalar(castedType, castedAttribute);
					typeTiers[tier][type].set(castedAttribute, defaultStats * multiplicationFactor);
				}
	}

};