#include <iostream>

int main() {
	// Reading the size of the matrix
	int N, M;
	std::cin >> N >> M;

	// Allocating the Matrix
	int **matrix = new int*[N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];
	}

	// Reading the Matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> matrix[i][j];
		}
	}

	// To solve the problem we just have to iterate through all the rows
	// and columns to find the highest sum.
	int max = 0;

	// Iterating through the rows
	for (int i = 0; i < N; i++) {
		// Sum of the row
		int partialSum = 0;

		// Summing...
		for (int j = 0; j < M; j++) {
			partialSum += matrix[i][j];
		}

		// If the sum of that row is greater than what we have now, change it
		if (partialSum > max) max = partialSum;
	}

	// Iterating through the columns
	for (int j = 0; j < M; j++) {
		int partialSum = 0;

		for (int i = 0; i < N; i++) {
			partialSum += matrix[i][j]; 
		}

		if (partialSum > max) max = partialSum;
	}

	std::cout << max << std::endl;
}