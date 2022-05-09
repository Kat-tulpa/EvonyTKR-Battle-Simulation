#pragma once

#include "Type.h"
#include "Tier.h"
#include "Attribute.h"
#include "Count.h"
#include "Stats.h"

class TypeTier {
private:
	Count count;
	Stats stats;
	Type type;
	Tier tier;

public:

	// Getters
	const Type getType() {
		return type;
	}

	const Tier getTier() {
		return tier;
	}

	const Attribute get(const ATTRIBUTE attribute) {
		return stats.get(attribute);
	}

	const Attribute getATK() {
		return stats.getATK();
	}

	const Attribute getDEF() {
		return stats.getDEF();
	}

	const Attribute getHP() {
		return stats.getHP();
	}

	const Count getCount() {
		return count;
	}

	// Setters
	void setType(Type _type) {
		type = _type;
	}

	void setTier(Tier _tier) {
		tier = _tier;
	}

	void set(const Attribute atk, const Attribute def, const Attribute hp) {
		stats.set(atk, def, hp);
	}

	void set(const ATTRIBUTE attribute, const Attribute val) {
		stats.set(attribute, val);
	}

	void setATK(Attribute atk) {
		stats.setATK(atk);
	}

	void setDEF(Attribute def) {
		stats.setDEF(def);
	}

	void setHP(Attribute hp) {
		stats.setHP(hp);
	}

	void setCount(Count _count) {
		count = _count;
	}
};