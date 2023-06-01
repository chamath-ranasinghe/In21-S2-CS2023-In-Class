#include <iostream>
#include <numeric>

#define V 6

using namespace std;

// Function to print the shortest times from source
int printTimes(int dist[], int src)
{
    cout<<"Shortest Distance from Source"<<endl;
    for (int i = 0; i < V; i++)
        if (i != src){
            cout<<"To "<<i<<" -> "<<dist[i]<<endl;
        }
}


int findMinDistNode(int time[], bool shrtpth[]){
    // Initialize min value
    int min = INT16_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (shrtpth[v] == false && time[v] <= min){
            min = time[v];
            min_index = v;
        }

    return min_index;    
}

// Function to find the average time from sources
double findAvg(int arr[]){
    int sum = 0;

    for(int i=0; i<V; i++){ sum += arr[i];}
    double avg = static_cast<double>(sum) / 5.0;
    return avg;
}

//Dijkstra's algorithm
void runDijkstra(int graph[][6], int src){

    int time[V]; // Array to store the times from source to each city

    for(int i=0; i<V; i++){
        time[i] = INT16_MAX;
    }

    bool shrtPth[V]{}; // Store the cities included in shortest time (True if yes)
    int minVertex;

    time[src] = 0; // Set distance from source vertex to 0

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from vertices yet to be traversed
        minVertex = findMinDistNode(time, shrtPth);
        shrtPth[minVertex] = true;

        for (int v = 0; v < V; v++){

        /* Update the vertex only if 
            a. It's not traversed already
            b. There's an edge
            c. Total weight from src to the vertex is smaller than the current value
        */
        if (!shrtPth[v] && graph[minVertex][v] && time[minVertex] != INT16_MAX
            && time[minVertex] + graph[minVertex][v] < time[v]){
            time[v] = time[minVertex] + graph[minVertex][v];
        }
    }
    }  

    printTimes(time, src);
    double avgTime = findAvg(time);
    cout<<"Avg time from source: "<<avgTime<<endl;
}

int main(){
    int graph[V][V] = {{0,10,0,0,15,5},
                        {10,0,10,30,0,0},
                        {0,10,0,12,5,0},
                        {0,30,12,0,0,20},
                        {15,0,5,0,0,0},
                        {5,0,0,20,0,0}};
    
    // Run the algorithm for each city as source
    for(int i=0; i<V; i++){
        cout<< "Source is " << i << endl;
        runDijkstra(graph, i);
        cout<<endl;
    }    

    return 0;
}