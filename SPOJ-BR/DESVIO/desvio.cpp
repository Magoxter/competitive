#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>

int N, M, C, K; // Number of cities, roads, cities in the route and the starting point
typedef std::map<int, std::vector<std::pair<int, int>>> Graph;
const int INT_MAX = std::numeric_limits<int>::max();

struct comp {
    bool operator() (const std::pair<int, int> &x, const std::pair<int, int> &y) {
        return x.second > y.second;
    }
};

int dijkstra(Graph graph, int start, int end) {
    // Already visited nodes
    int visited[N+1];
    
    // Distance from node start
    int dist[N+1];

    // Initilizing both vectors
    for (int i = 0; i <= N; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Queue ordered by the distance
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> queue;
    queue.push(std::make_pair(start, dist[start]));

    while (!queue.empty()) {
        int v = queue.top().first;
        queue.pop();
        visited[v] = 1;

        // Reached our goal
        if (v == end) break;

        for (int i = 0; i < graph[v].size(); i++) {
            int x = graph[v][i].first;  // other vertex
            int w = graph[v][i].second; // weight
            int newDist = dist[v] + w;

            if (!visited[x] && (newDist < dist[x])) {
                dist[x] = newDist;
                queue.push(std::make_pair(x, dist[x]));
            }
        }
    }

    if (dist[end] == INT_MAX) return -1;
    return dist[end];
}

int main() {
    std::cin >> N >> M >> C >> K;
    while (N != 0) {
        // Map of vector of pairs.
        Graph graph;

        // Reading adjacency list
        for (int i = 0; i < M; i++) {
            int v1, v2, weight;
            std::cin >> v1 >> v2 >> weight;

            // if there is a route between a city in the route and a city not in the route, we dont need it.
            if (!((v1 < C-1) && (v2 != v1 + 1))) graph[v1].push_back(std::make_pair(v2, weight));
            if (!((v2 < C-1) && (v1 != v2 + 1))) graph[v2].push_back(std::make_pair(v1, weight));
        }

        std::cout << dijkstra(graph, K, C-1) << std::endl;

        std::cin >> N >> M >> C >> K;
    }

    return 0;
}