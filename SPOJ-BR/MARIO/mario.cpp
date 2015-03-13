#include <iostream>
#include <vector>
#include <algorithm>

int swapLockers(std::vector<int> available, int N) {
	int min = 100000000;

	for (int i = 0; i < available.size(); i++) {
		auto it = std::lower_bound(available.begin() + i, available.end(), (available[i] + N - 1));
		//std::cout << (it - available.begin()) << std::endl;

		// If we found the empty space, the number of swaps is going to be the number minus
		// the index in the array. (because we know we have that number of occupied spaces in that range).
		// If what we have know is best that what we had, update it
		int temp = (i + N - 1) - (it - available.begin());
		if (temp < min && temp >= 0) {
			if (*it == (available[i] + N - 1)) {
				min = temp;
			} else {
				min = temp + 1;
			}
		}
	}

	return min;
}

int main() {
	int N, L;

	std::cin >> N >> L;
	while (N != 0 && L != 0) {
		std::vector<int> available(L);

		for (int i = 0; i < L; i++) {
			std::cin >> available[i];
		}

		std::cout << swapLockers(available, N) << std::endl;

		std:: cin >> N >> L;
	}

	return 0;
}