#include "Util.h"

bool comp(const Edge &e1, const Edge &e2) {
	return e1.getCost() < e2.getCost();
}
