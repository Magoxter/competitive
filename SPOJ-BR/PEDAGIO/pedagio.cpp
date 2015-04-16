#include <iostream>
#include <map>
#include <set>
#include <queue>

typedef std::map<int, std::set<int>> Graph;

void BFS(Graph graph, int city, std::set<int> &solution, int distance) {
    // Queue to use in the BFS
    std::queue<int> queue;
    // Parent of that node in the path
    std::map<int, int> parent;
    // Distance for that node to the beginning vertex
    std::map<int, int> cost;

    // Start by marking the city we are already in and put it on the queue
    queue.push(city);
    parent[city] = -1;
    cost[city] = 0;


    // BFS (we use the solution vector to keep track of the discovered vertices)
    while (queue.size() != 0) {
        int v = queue.front();
        // If we are already at the max distance, we can safely stop the BFS, we have a solution
        if (cost[v] == distance) break;

        queue.pop();

        // Add all the unvisited vertices into the queue to be visited. Use the solution
        // to check if a vertex was already discovered
        for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
            // If the vertex wasn't discovered or isn't the original city, add and "discover" it
            if (solution.find(*it) == solution.end() && *it != city) {
                parent[*it] = v;            // Where this vertex came from
                cost[*it] = cost[v] + 1;    // The distance of this vertex is equal to it's parent + 1
                solution.insert(*it);       // Insert it in the soltuion
                queue.push(*it);            // Put it on the queue to look at its neighboors
            }
        }   
    }
}

int main() {
    int nCities, nRoads, currentCity, nToll;
    int nTest = 1;

    std::cin >> nCities >> nRoads >> currentCity >> nToll;
    while (nCities != 0) {
        // Build the graph, reading from standard input
        Graph graph; 

        for (int i = 0; i < nRoads; i++) {
            int c1, c2;
            std::cin >> c1 >> c2;

            // Graph is undirected, so we have both c1->c2 and c2->c1
            graph[c1].insert(c2);
            graph[c2].insert(c1);
        }

        // Solve the problem
        std::set<int> solution;
        BFS(graph, currentCity, solution, nToll);

        // Print solution
        std::cout << "Teste " << nTest << std::endl;
        for (auto it = solution.begin(); it != solution.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;

        // Read next entry
        nTest++;
        std::cin >> nCities >> nRoads >> currentCity >> nToll;
    }

    return 0;
}