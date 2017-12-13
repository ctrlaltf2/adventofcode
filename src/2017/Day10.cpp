#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void y17day10(std::ostream& os, std::istream& is, bool part2) {
	const int kMax = 256;
	char ignore;
	std::vector<int> list(kMax, 0);
	std::iota(list.begin(), list.end(), 0);

	int pos{0}, skip{0};
	for(int length; is >> length;) {
		is >> ignore;
		std::rotate(list.begin(), std::next(list.begin(), pos), list.end());
		std::reverse(list.begin(), std::next(list.begin(), length));
		std::rotate(list.rbegin(), std::next(list.rbegin(), pos), list.rend());
		pos += length + skip++;
		pos %= kMax;
	}
	os << list[0] * list[1] << std::endl;
}