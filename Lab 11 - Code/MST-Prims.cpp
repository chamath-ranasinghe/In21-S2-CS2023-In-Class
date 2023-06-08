#include <iostream>

using namespace std;

#define NUM_VERTICES 6
#define INFINITY 9999

// Function to find the vertex with the minimum distance from the set of vertices not yet included in the MST
int findMin(int dist[], bool isVisited[])
{
    int min = INFINITY;
    int minIndex;

    // Traverse through all the vertices and find the vertex with the minimum distance
    for (int v = 0; v < NUM_VERTICES; v++)
    {
        // If the vertex is not yet included in the MST and its distance is less than the current minimum distance
        if (!isVisited[v] && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the Minimum Spanning Tree (MST)
void printMST(int graph[NUM_VERTICES][NUM_VERTICES])
{
    int parent[NUM_VERTICES];
    int dist[NUM_VERTICES];
    bool isVisited[NUM_VERTICES];

    // Initialize distance and visited arrays
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        dist[i] = INFINITY;
        isVisited[i] = false;
        parent[i] = -1;
    }

    dist[0] = 0; // Start from the first vertex

    // Build the MST with NUM_VERTICES - 1 vertices
    for (int i = 0; i < NUM_VERTICES - 1; i++)
    {
        int u = findMin(dist, isVisited); // Find the vertex with the minimum distance

        isVisited[u] = true; // Include the vertex in the MST

        // Update the distances of the adjacent vertices not yet included in the MST
        for (int v = 0; v < NUM_VERTICES; v++)
        {
            // If there is an edge between u and v, v is not in MST, and the edge weight is smaller than the current distance[v]
            if (graph[u][v] && !isVisited[v] && graph[u][v] < dist[v])
            {
                parent[v] = u;         // Update the parent of v
                dist[v] = graph[u][v]; // Update the minimum distance of v
            }
        }
    }

    // Print the MST
    cout << "Edge" << "    " << "Weight" << endl;
    for (int i = 1; i < NUM_VERTICES; i++)
    {
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
    }
}

int main()
{
    int graph[NUM_VERTICES][NUM_VERTICES] = { {0, 3, 0, 0, 0, 1},
                                              {3, 0, 2, 1, 10, 0},
                                              {0, 2, 0, 3, 0, 5},
                                              {0, 1, 3, 0, 5, 0},
                                              {0, 10, 0, 5, 0, 4},
                                              {1, 0, 5, 0, 4, 0} };

    printMST(graph); // Display the Minimum Spanning Tree

    return 0;
}
