#include <iostream>
#include <list>
using namespace std;

// Define a structure to create nodes to be added to the graph
struct Node {
    int label;                // Node label
    list<int> neighbours;     // List of neighbouring nodes
};

// Graph data structure
struct Graph {
    int n = 8;                // Number of nodes in the graph
    Node* nodes = new Node[n];  // Array to stored the nodes

    // This iterates through the nodes and assign values for each node
    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    // Method to add an undirected edge between two vertices
    void addEdge(int u, int v) {
        for (int neighbour : nodes[u].neighbours) { // To check if the edge is already present
            if (neighbour == v) {
                return;  // Edge already exists
            }
        }
        // As it's an undirected list, u and v are considered as each other's neighbours
        nodes[u].neighbours.push_back(v);
        nodes[v].neighbours.push_back(u);
    }

    // Print the adjacency list of the graph
    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << nodes[i].label << "|";
            for (int neighbour : nodes[i].neighbours) {
                cout << " -> Node " << neighbour;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    g->addEdge(0, 3);
    g->addEdge(0, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 6);
    g->addEdge(4, 7);
    g->addEdge(5, 7);


    // Print the adjacency list
    g->print();
}