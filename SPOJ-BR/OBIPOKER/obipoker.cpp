#include <iostream>
#include <map>
#include <algorithm>

int playHand(int *hand) {
	// Check for a straight
	std::sort(hand, hand+5); 
	if (hand[1] == hand[0] + 1 &&
		hand[2] == hand[0] + 2 &&
		hand[3] == hand[0] + 3 &&
		hand[4] == hand[0] + 4) {
		return hand[0] + 200; 
	}

	// Create a map with the cards so its easier to spot
	// repeated cards.
	std::map <int, int> mapHand;
	for (int i = 0; i < 5; i++) mapHand[hand[i]]++;

	/*for (auto it = mapHand.begin(); it != mapHand.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << std::endl;*/

	// Iterate through the map to find possible combinations
	for (auto it = mapHand.begin(); it != mapHand.end(); it++) {
		// Interator for the following for loops, starting at the next element.
		auto auxIt = it;
		auxIt++;

		switch (it->second) {
			// We have a pair
			case 2:
				// We can still have two pairs or a full house, so check
				for ( ; auxIt != mapHand.end(); auxIt++) {
					// Two pairs
					if (auxIt->second == 2) {
						return ((it->first)*2) + ((auxIt->first)*3) + 20;
					}
					// Full House
					if (auxIt->second == 3) return auxIt->first + 160;
				}

				return it->first;
			
			// We have a triple
			case 3:
				// We can still have a full house, so check
				for ( ; auxIt != mapHand.end(); auxIt++) {
					// Full House
					if (auxIt->second == 2) return it->first + 160;
				}

				return it->first + 140;

			// We have a four of a kind
			case 4:
				return it->first + 180;
		}
	}

	// We had nothing :(
	return 0;
}

int main() {
	// Number of hands
	int N;
	std::cin >> N;

	int hand[5];

	// Read hand, play it, and print the result.
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> hand[j];
		}

		std::cout << "Teste " << i << std::endl; 
		std::cout << playHand(hand) << std::endl << std::endl;
	}
}