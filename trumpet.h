#pragma once
#include <iostream>
#include "utils.h"

class trumpet
{

public:
	trumpet();
	int id;
	static int MAX_ID;
	float length;
	float diam;
	bool repaired = false;

	friend std::ostream& operator << (std::ostream& out, const trumpet& pipe);
	friend std::istream& operator >> (std::istream& in, trumpet& pipe);
};