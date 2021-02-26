#include <iostream>
#include <limits.h>
using namespace std;

void printSolution(int d[], int V, int source)
{
    cout << "Source: " << source << endl;
    cout << "Vertex \t\tDistance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        if (i != source)
        {
            if (d[i] < INT_MAX)
                cout << i << "\t\t" << d[i] << endl;
            else if (d[i] > 32767)                      //INT_MAX==32767 largest 16 bit integer value
                cout << i << "\t\t"<< "INFINITE" << endl;
        }
    }
}

void BellmanFord(int edge[][3], int V, int E, int src)
{
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    /*Step 2: Relax all edges |V| - 1 times. A simple shortest path from src to any other vertex can have at-most |V| - 1 edges */
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            int weight = edge[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    /*Step 3: check for negative-weight cycles. The above step guarantees shortest distances if graph doesn't contain 
    negative weight cycle.  If we get a shorter path, then there is a cycle.*/
    for (int j = 0; j < E; j++)
    {
        int u = edge[j][0];
        int v = edge[j][1];
        int weight = edge[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply return
        }
    }

    printSolution(dist, V, src);
    return;
}

int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    int edge[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    cout << "\n\tImplementation of Bellman-Ford's Algorithm\t\n\n";
    BellmanFord(edge, V, E, 3);
    return 0;
}