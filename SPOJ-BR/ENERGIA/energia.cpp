#include <iostream>
#include <map>
#include <vector>

int E, L;

typedef std::map<int, std::vector<int>> Graph;

void dfsVisit(int v, Graph graph, std::vector<int> &visited) {
    // Mark vertix as visited
    visited[v] = 1;

    // Go through all the adjacent vertices, if it wasn't visited yet, call DFS to visit it
    for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
        if (visited[*it] == 0) dfsVisit(*it, graph, visited);
    }
}

bool DFS(Graph graph) {
    // List of visited nodes
    std::vector<int> visited(E+1);

    // We can start at any vertex, so choose the first one
    dfsVisit(1, graph, visited);

    // Check if there is a vertix that wasn't visited
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0) return false;
    }

    return true;
}

int main() {
    // Number of stations and number of powerlines (vertices and edges)
    std::cin >> E >> L;
    int nTest = 1;

    while (E != 0) {
        Graph graph;

        for (int i = 0; i < L; i++) {
            int c1, c2;
            std::cin >> c1 >> c2;

            graph[c1].push_back(c2);
            graph[c2].push_back(c1);
        }

        std::cout << "Teste " << nTest << std::endl;
        if (DFS(graph)) std::cout << "normal" << std::endl;
        else std::cout << "falha" << std::endl;
        std::cout << std::endl;

        std::cin >> E >> L;
        nTest++;
    }

    return 0;
}