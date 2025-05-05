#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for DFS (recursive)
void DFS(int node, vector<int> graph[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

// Function for BFS (using queue)
void BFS(int start, vector<int> graph[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> graph[V];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // because undirected
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS traversal: ";
    vector<bool> visited(V, false);
    DFS(start, graph, visited);
    cout << endl;

    cout << "BFS traversal: ";
    BFS(start, graph, V);
    cout << endl;

    return 0;
}
