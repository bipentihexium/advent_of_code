#include <deque>
#include <iostream>
#include <string>
#include <vector>

struct instruction {
	unsigned int count;
	unsigned int from;
	unsigned int to;
};

int main() {
	std::vector<std::deque<char>> crates;
	std::string line;
	std::getline(std::cin, line);
	for (unsigned int i = 1; i < line.size(); i += 4) {
		if (line[i] != ' ')
			crates.emplace_back(1, line[i]);
		else
			crates.emplace_back();
	}
	do {
		std::getline(std::cin, line);
		if (line[1] >= '0' && line[1] <= '9')
			break;
		for (unsigned int i = 1; i < line.size(); i += 4) {
			if (line[i] != ' ')
				crates[i/4].push_front(line[i]);
		}
	} while (1);
	std::cout << "Crates: " << std::endl;
	for (const auto &crate_stack : crates) {
		for (const char &c : crate_stack) {
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}
	std::vector<std::deque<char>> crates_cpy(crates);
	std::vector<instruction> instrs;
	std::string &null = line;
	do {
		unsigned int count, from, to;
		std::cin >> null >> count >> null >> from >> null >> to;
		if (!std::cin) {
			break;
		}
		instrs.push_back(instruction{ count-1, from-1, to-1 });
	} while(1);

	for (const auto &i : instrs) {
		crates[i.to].insert(crates[i.to].end(), crates[i.from].rbegin(), crates[i.from].rbegin() + i.count + 1);
		crates[i.from].erase(crates[i.from].end() - i.count - 1, crates[i.from].end());
	}
	std::cout << "CrateMover 9000 result: " << std::endl;
	for (const auto &crate_stack : crates) {
		for (const char &c : crate_stack) {
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Top crates: ";
	for (const auto &crate_stack : crates) {
		std::cout << crate_stack.back();
	}
	std::cout << std::endl;

	crates = crates_cpy;
	for (const auto &i : instrs) {
		crates[i.to].insert(crates[i.to].end(), crates[i.from].end() - i.count - 1, crates[i.from].end());
		crates[i.from].erase(crates[i.from].end() - i.count - 1, crates[i.from].end());
	}
	std::cout << "CrateMover 9001 result: " << std::endl;
	for (const auto &crate_stack : crates) {
		for (const char &c : crate_stack) {
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Top crates: ";
	for (const auto &crate_stack : crates) {
		std::cout << crate_stack.back();
	}
	std::cout << std::endl;
	return 0;
}
