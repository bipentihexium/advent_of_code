#include <deque>
#include <iostream>
#include <unordered_set>

int main() {
	std::deque<char> prev;
	char in;
	bool found_packet = false;
	unsigned int at = 4;
	{
		char b, c, d;
		std::cin >> in >> b >> c >> d;
		prev.insert(prev.end(), { in, b, c, d });
	}
	do {
		if (!found_packet) {
			std::unordered_set<char> present(prev.end() - 4, prev.end());
			if (present.size() == 4) {
				std::cout << "Packet starts at: " << at << "; there's {" << std::string(prev.begin(), prev.end()) << "} before" << std::endl;
				found_packet = true;
			}
		}
		if (prev.size() > 13) {
			std::unordered_set<char> present(prev.begin(), prev.end());
			if (present.size() == 14) {
				std::cout << "Message starts at: " << at << "; there's {" << std::string(prev.begin(), prev.end()) << "} before" << std::endl;
				return 0;
			}
		}
		std::cin >> in;
		prev.push_back(in);
		if (prev.size() > 14) {
			prev.pop_front();
		}
		at++;
	} while (std::cin);
	return 1;
}
