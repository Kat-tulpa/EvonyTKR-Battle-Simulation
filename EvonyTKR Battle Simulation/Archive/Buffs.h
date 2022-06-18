#pragma once

#include "ScalarValues.h"
#include "FlatBuffs.h"
#include "Defs.h"

class Buffs {
private:
	ScalarValues SCALAR;
	FlatBuffs FLAT;

public:
	ScalarValues& scalar() {
		return SCALAR;
	}

	FlatBuffs& flat() {
		return FLAT;
	}
};