#include <iostream>
#include <climits>
using namespace std;

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Function to construct and print MST for a graph using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];   // Stores the MST
    int key[V];      // Used to pick minimum weight edge
    bool mstSet[V];  // True if vertex is included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;     // Start from the first vertex
    parent[0] = -1; // First node is root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick min key vertex
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            // Update key and parent if the edge u-v is smaller and v is not in MST
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

// Main function
int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
