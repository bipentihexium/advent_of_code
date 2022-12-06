#include <iostream>

int main() {
	unsigned int start_a, end_a, start_b, end_b;
	unsigned int contains = 0;
	unsigned int overlaps = 0;
	char null;
	do {
		std::cin >> start_a >> null >> end_a >> null >> start_b >> null >> end_b;
		if (!std::cin) break;
		if ((start_a >= start_b && end_a <= end_b) || (start_b >= start_a && end_b <= end_a)) contains++;
		if (end_a >= start_b && end_b >= start_a) overlaps++;
	} while(1);
	std::cout << "Contains: " << contains << std::endl;
	std::cout << "Overlaps: " << overlaps << std::endl;
	return 0;
}
