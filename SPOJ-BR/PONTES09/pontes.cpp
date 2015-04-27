#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>

int N, M;
const int INT_MAX = std::numeric_limits<int>::max();

typedef std::map<int, std::vector<std::pair<int, int>>> Graph;

struct comp {
    bool operator() (const std::pair<int, int> &x, const std::pair<int, int> &y) {
        return x.second > y.second;
    }
};

int dijkstra(Graph graph, int start, int end) {
    // Already visited nodes
    int visited[N+2];
    
    // Distance from node start
    int dist[N+2];

    // Initilizing both vectors
    for (int i = 0; i <= N+1; i++) {
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

    return dist[end];
}

int main() {
    std::cin >> N >> M;

    // Map of vector of pairs.
    Graph graph;

    // Reading adjacency list
    for (int i = 0; i < M; i++) {
        int v1, v2, weight;
        std::cin >> v1 >> v2 >> weight;
        graph[v1].push_back(std::make_pair(v2, weight));
        graph[v2].push_back(std::make_pair(v1, weight));
    }

    // Solve the problem
    std::cout << dijkstra(graph, 0, N+1) << std::endl;
    
    return 0;
}