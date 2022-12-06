#include <iostream>

constexpr unsigned int result_lookup[] = {
	4, 1, 7,
	8, 5, 2,
	3, 9, 6
};
constexpr unsigned int result2_lookup[] = {
	3, 1, 2,
	4, 5, 6,
	8, 9, 7
};

int main() {
	unsigned int score, score2;
	char opponent, self;
	while (1) {
		std::cin >> opponent >> self;
		if (!std::cin)
			break;
		unsigned int lookup_index = (opponent - 'A') + 3 * (self - 'X');
		score += result_lookup[lookup_index];
		score2 += result2_lookup[lookup_index];
	}
	std::cout << "part one (X rock, Y paper, Z siccors): " << score << std::endl;
	std::cout << "part two (X loss, Y draw, Z win): " << score2 << std::endl;
	return 0;
}
