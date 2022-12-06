#include <iostream>
#include <string>
#include <unordered_set>

unsigned int priority_sum = 0;
unsigned int badge_priority_sum = 0;

constexpr unsigned int priority(char c) {
	return c >= 'a' ? c - ('a' - 1) : c - ('A' - 27);
}

void count_priority(const std::string &ln) {
	std::unordered_set<char> first_compartment;
	for (size_t i = 0; i < ln.size() / 2; i++) {
		first_compartment.emplace(ln[i]);
	}
	for (size_t i = ln.size() / 2; i < ln.size(); i++) {
		if (first_compartment.contains(ln[i])) {
			priority_sum += priority(ln[i]);
			break;
		}
	}
}

int main() {
	std::string ln;
	while (std::getline(std::cin, ln)) {
		std::unordered_set<char> group, common_1_2;
		for (const char &c : ln) { group.emplace(c); }
		count_priority(ln);
		std::getline(std::cin, ln);
		for (const char &c : ln) { if (group.contains(c)) common_1_2.emplace(c); }
		count_priority(ln);
		std::getline(std::cin, ln);
		for (const char &c : ln) { if (common_1_2.contains(c)) { badge_priority_sum += priority(c); break; } }
		count_priority(ln);

	}
	std::cout << "Wrong items: " << priority_sum << std::endl;
	std::cout << "Badges: " << badge_priority_sum << std::endl;
	return 0;
}
