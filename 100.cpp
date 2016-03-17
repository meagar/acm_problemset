// 100.cpp http://acm.uva.es/p/v1/100.html
//
// Solution to ACM problem #100 - "3n + 1"
//
// Matthew Eagar - meagar@gmail.com
// Verified to work as of Feb 19 / 2005

#include <iostream>
#include <vector>

typedef unsigned long ulong;

int main() {

	ulong min, max; // our bounds as read from stdin

	std::vector<ulong> cache(1000000, 0);

	while (std::cin >> min >> max) {

		ulong lbound, ubound;
		if (min < max) {
			lbound = min; ubound = max;
		} else {
			lbound = max; ubound = min;
		}

		ulong n, cycles, maxCycles = 0;
		// check each number in our given range (n1..n2)
		for (ulong i = lbound; i <= ubound; ++i) {
			n = i, cycles = 0;

			// loop until we hit 1
			while (n != 1) {
				++cycles;
				n = (n % 2 ? 3 * n + 1 : n / 2);
				if (n < cache.size() && cache[n]) {
					cycles += cache[n];
					break;
				}
			}

			cache[i] = cycles;
			if (cycles >= maxCycles)
				maxCycles = cycles;
		}

		// write results, using origional version of lbound and ubound
		// I haven't taken the time to figure out why I have an off-by-one error...
		std::cout << min << " " << max << " " << maxCycles + 1 << std::endl;
	}
}

