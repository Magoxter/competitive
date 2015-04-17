#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>


int N, M;

typedef std::pair<int, int> Position;

int solve(std::vector<std::vector<int>> graph, Position start) {
    // Queue to use in the BFS
    std::queue<Position> queue;
    // Distance for that node to the beginning vertex
    std::map<Position, int> cost;
    // Visited vertices
    std::set<Position> visited;

    // Put the starting vertex in the queue
    queue.push(start);
    visited.insert(start);

    while (queue.size() != 0) {
        Position v = queue.front();
        queue.pop();


        // Mark as visit
        visited.insert(v);

        int line = v.first; // Current line
        int col = v.second; // Current column

        int up = v.first - 1;
        int down = v.first + 1;
        int left = v.second - 1;
        int right = v.second + 1;

        if (up >= 0) {

            // We can finish the program, this position is the exit
            if (graph[up][col] == 0) {
                return cost[v] + 1;
            }

            // We can go there
            if (graph[up][col] == 1) {
                Position aux = std::make_pair(up, col);

                if (visited.find(aux) == visited.end()) {
                    cost[aux] = cost[v] + 1;
                    queue.push(aux);
                }
            }
        }

        // <--
        if (left >= 0) {

            // We can finish the program, this position is the exit
            if (graph[line][left] == 0) {
                return cost[v] + 1;
            }

            // We can go there
            if (graph[line][left] == 1) {
                Position aux = std::make_pair(line, left);
                
                if (visited.find(aux) == visited.end()) {
                    cost[aux] = cost[v] + 1;
                    queue.push(aux);
                }
            }
        }

        // \/
        if (down < N) {

            // We can finish the program, this position is the exit
            if (graph[down][col] == 0) {
                return cost[v] + 1;
            }

            // We can go there
            if (graph[down][col] == 1) {
                Position aux = std::make_pair(down, col);
                
                if (visited.find(aux) == visited.end()) {
                    cost[aux] = cost[v] + 1;
                    queue.push(aux);
                }
            }
        }

        // -->
        if (right < M) {
            // We can finish the program, this position is the exit
            if (graph[line][right] == 0) {
                return cost[v] + 1;
            }

            // We can go there
            if (graph[line][right] == 1) {
                Position aux = std::make_pair(line, right);
                
                if (visited.find(aux) == visited.end()) {
                    cost[aux] = cost[v] + 1;
                    queue.push(aux);
                }
            }
        }


    }

    return 0;
}

int main() {
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N);
    Position start;

    for (int i = 0; i < N; i++) {
        graph[i].resize(M);
        for (int j = 0; j < M; j++) {
            std::cin >> graph[i][j];

            if (graph[i][j] == 3) {
                start.first = i;
                start.second = j;
            }
        }
    }

    std::cout << solve(graph, start) << std::endl;
    return 0;
}