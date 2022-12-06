#include <algorithm>
#include <iostream>
#include <string>

int max, second, third;

void elf_sum(int carry) {
	if (carry > max) {
		third = second;
		second = max;
		max = carry;
	} else if (carry > second) {
		third = second;
		second = carry;
	} else if (carry > third) {
		third = carry;
	}
}

int main() {
	int csum;
	std::string temp;
	while (std::getline(std::cin, temp)) {
		if (temp.empty()) {
			elf_sum(csum);
			csum = 0;
		} else {
			csum += std::stoi(temp);
		}
	}
	elf_sum(csum);
	std::cout << "Top: " << max << std::endl;
	std::cout << "Top 3 sum: " << (max+second+third) << std::endl;
	return 0;
}
