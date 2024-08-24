#pragma once
#include "Assert.h"
#include "ZtlSecure.h"

class SECRECT {
public:
	int GetLeft() {
		try {
			return this->left.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetTop() {
		try {
			return this->top.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetRight() {
		try {
			return this->right.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetBottom() {
		try {
			return this->bottom.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}
private:
	ZtlSecure<int> left;
	ZtlSecure<int> top;
	ZtlSecure<int> right;
	ZtlSecure<int> bottom;
};

static_assert_size(sizeof(SECRECT), 0x30);