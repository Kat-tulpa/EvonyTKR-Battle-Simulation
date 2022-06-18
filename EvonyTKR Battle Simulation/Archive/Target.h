#pragma once

#include "Defs.h"

class Target {
private:
	Type type;
	unsigned int tier;

public:
	const bool isNull() {
		return type == TYPE_NULL || tier == TNULL;
	}
};