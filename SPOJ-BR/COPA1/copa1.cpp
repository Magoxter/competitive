#include <iostream>
#include <utility> // To use pair

int main() {
    // Reading the games
    std::pair<int, int> games[15];

    for (int i = 0; i < 15; i++) {
        std::cin >> games[i].first >> games[i].second;
    }

    // To solve this, we have a pool of teams still running to be champion
    // At each stage, we go linearly through the vector of games and remove from our pool
    // all the loosers until there is only one team left.

    // Each round we have a number of games. This is the range of the loop.
    // For example, in the round of 16s we have 8 games and in the semi finals 2.

    // Then, we check which team won the game and add that team to the new pool
    // (using the last pool and the index variable that represents the appropriate indexes
    // in the last pool)

    // Finally, we will end with just one game left to check and we will have a winner.

    char teams[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                        'M', 'N', 'O', 'P'};

    // Round of 16
    char quarter[8];
    for (int i = 0; i < 8; i++) {
        int index = i*2;

        if (games[i].first > games[i].second) {
            quarter[i] = teams[index];
        }
        else {
            quarter[i] = teams[index+1];
        }
    }

    // Quarter Finals
    char semi[4];
    for (int i = 0; i < 4; i++) {
        int index = i*2;

        if (games[i+8].first > games[i+8].second) {
            semi[i] = quarter[index];
        }
        else {
            semi[i] = quarter[index+1];
        }
    }

    // Semi Finals
    char final[2];
    for (int i = 0; i < 2; i++) {
        int index = i*2;

        if (games[i+12].first > games[i+12].second) {
            final[i] = semi[index];
        }
        else {
            final[i] = semi[index+1];
        }
    }

    // Winner
    char winner;
    if (games[14].first > games[14]. second) winner = final[0];
    else winner = final[1];

    std::cout << winner << std::endl;

	return 0;
}