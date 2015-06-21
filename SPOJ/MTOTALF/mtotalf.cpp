#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

int print(std::vector<std::vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int convert(char c) {
    // upper case letter
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    // lower case letter
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
}

int BFS(std::vector<std::vector<int>> graph, int start, int end, int *parent) {
    // Create array of visited vertices and zero it
    bool visited[graph.size()];
    memset(visited, 0, sizeof(visited));

    // Queue to be used in the BFS
    std::queue<int> queue;

    // Put starting vertex in the queue and start the BFS
    queue.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (queue.size() > 0) {
        // Vertex we are at
        int v = queue.front();
        queue.pop();

        // Add all this vertex's neighboors to the queue, checking if they are already visited
        for (int i = 0; i < graph.size(); i++) {
            if (graph[v][i] > 0 && visited[i] == false) {
                queue.push(i);
                visited[i] = true;
                parent[i] = v;

                // If we reached sink, we have a path
                if (i == end) return true;
            }
        }
    }

    // We didn't reach sink
    return false;
}

int maxFlow(std::vector<std::vector<int>> cap, int source, int sink) {
    int parent[cap.size()]; // filled by BFS so we have the augumenting path
    memset(parent, -1, sizeof(parent)); // Zeroing it

    int answer = 0;

    while (BFS(cap, source, sink, parent)) {
        // Get the maximum flow
        int pathFlow = 999999999;
        int v = sink; // used to transverse the path

        // Iterate through the path
        while (v != source) {
            //std::cout << v << " ";
            
            int p = parent[v];
            pathFlow = std::min(pathFlow, cap[p][v]);

            v = p;
        }
        //std::cout << "\n";

        //print(cap);

        v = sink;
        while (v != source) {
            int p = parent[v];
            cap[p][v] -= pathFlow;
            cap[v][p] += pathFlow;

            v = p;
        }

        //print(cap);

        answer += pathFlow;

        memset(parent, -1, sizeof(parent)); // Zeroing it
    }

    return answer;
}

int main() {
    std::ios::sync_with_stdio(false);

    // 26x26, size of the alphabet.
    std::vector<std::vector<int>> cap; 
    cap.resize(52, std::vector<int> (52, 0));

    // Starts at A and ends at Z
    int source = 0;
    int sink = 25;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b;
        int x;
        std::cin >> a >> b >> x;
        
        cap[convert(a)][convert(b)] += x;
        cap[convert(b)][convert(a)] += x;
    }

    std::cout << maxFlow(cap, source, sink) << "\n";
}