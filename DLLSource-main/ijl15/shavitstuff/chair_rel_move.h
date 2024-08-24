#pragma once
#include <tuple>

static std::tuple<int, int> get_chair_rel_move(int itemId) {
	switch (itemId) {
	case 3012006:
		return { 0, 0 };
	case 3012005:
		return { 0, 0 };
	case 3012001:
		return { 0, 0 };
	default:
		return { 0, 0 };
	}
}