#include <iostream>
#include <vector>
#include <algorithm>

/* Calculate the number of distinct equilateral triangles that can be constructed 
 * using the given points as vertices.
 */
int calculateTriangles(const std::vector<int> &distances) {
	if (distances.size() < 3) return 0;

	int numTri = 0;

	/* Build a vector with positions, and not arc distances
	 * Also gets the circunference of the circle.
	 * If it isn't divisible by 3, it's impossible to have equilateral triangles in it.
	 */
	std::vector<int> pos(distances.size());

	pos[0] = 0;
	for (int i = 1; i < distances.size(); i++) {
		pos[i] = pos[i-1] + distances[i-1]; 
	}

	int cir = pos[pos.size()-1] + distances[distances.size()-1];
	//std::cout << "Cir " << cir << std::endl; 

	/*for (int i = 0; i < distances.size(); i++) {
		std::cout << pos[i] << " ";
	}
	std::cout << std::endl;*/

	if ((cir % 3) != 0) return 0;
	
	// We have to have points that are circunference/3 apart so we can build the triangle
	int rate = cir/3;

	// Find the triangles
	for (int i = 0; i < pos.size(); i++) {
		int secondPoint = pos[i] + rate;
		int thirdPoint = secondPoint + rate;

		//std::cout << "Second " << secondPoint << " Third " << thirdPoint << std::endl; 

		if(std::binary_search(pos.begin(), pos.end(), secondPoint) && std::binary_search(pos.begin(), pos.end(), thirdPoint))
			numTri++;
	}

	return numTri;
}

int main() {
	int N;

	while (std::cin >> N) {
		// Lengths of the circular arcs that have adjacent points as extremes
		std::vector<int> distances(N);

		for (int i = 0; i < N; i++) {
			std::cin >> distances[i];
		}

		std::cout << calculateTriangles(distances) << std::endl;
	}

	return 0;
}