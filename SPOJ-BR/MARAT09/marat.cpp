#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    // +1 so we can include the finish line
    int posts[N+1];

    for (int i = 0; i < N; i++) {
        std::cin >> posts[i];
    }
    // Including the finish line
    posts[N] = 42195;

    // Solve the problem
    for (int i = 1; i < N+1; i++) {
        if ((posts[i] - posts[i-1]) > M) {
            std::cout << "N" << std::endl;
            return 0;
        }
    }
 
    std::cout << "S" << std::endl;

    return 0; 
}