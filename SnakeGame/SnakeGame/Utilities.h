#pragma once
#include <cstdlib>
#include <ctime>

namespace utilities
{
	const int k_width = 480;
	const int k_height = 320;
	const int k_blobAmount = 5;

	static int random_range(const int _min, const int _max) //range : [min, max)
	{
		static bool first = true;
		if (first) {
			srand(time(nullptr)); //seeding for the first time only!
			first = false;
		}
		return _min + rand() % ((_max + 1) - _min);
	}
}
