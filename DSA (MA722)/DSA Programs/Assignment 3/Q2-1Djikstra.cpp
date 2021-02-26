#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define N 9     //N--> number of vertices


// Function to find vertex with minimum distance from set of vertices not yet included
int minDist(int d[], int included[])
{
    int min=INT_MAX,minIndex;
    for(int v=0;v<N;v++)
    {
        if(included[v]==0 && d[v]<=min)
        {
            min=d[v];
            minIndex=v;
        }
    }
    return minIndex;
}
void printSolution(int d[],int source)
{
    cout << "Source: " << source << endl;
    cout << "Vertex \t\tDistance from Source"<<endl; 
    for (int i = 0; i < N; i++) 
        if(i!=source)
            cout << i <<"\t\t"<< d[i]<<endl; 
}
void dijkstrasAlgorithm(int g[N][N],int source)
{
    int d[N],included[N]={0};
    
    //Initialize all distances as Infinite and included[v]=0
    for(int v=0;v<N;v++)
    {
        d[v]=INT_MAX;
        included[v]=0;
    }
    d[source]=0;
    // Finding shortest path for all vertices
    for(int i=0;i<N-1;i++)
    {
        int min_dist=minDist(d,included);
        included[min_dist]=1;

        for(int v=0;v<N;v++)
        {
            if(included[v]==0 && g[min_dist][v] && d[min_dist]!=INT_MAX && d[min_dist]+ g[min_dist][v] < d[v])
                d[v] = d[min_dist] + g[min_dist][v];
        }
    }
    printSolution(d,source);
}
int main()
{
    int graph[N][N] = { { 0, 24, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 24, 0, 18, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 18, 0, 17, 0, 40, 0, 0, 20 }, 
                        { 0, 0, 17, 0, 9, 2, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 42, 0, 0, 0 }, 
                        { 0, 0, 40, 2, 42, 0, 12, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 12, 0, 15, 36 }, 
                        { 8, 11, 0, 0, 0, 0, 15, 0, 27 }, 
                        { 0, 0, 20, 0, 0, 0, 36, 27, 0 } }; 
    cout << "\n\tImplementation of Dijkstra's Algorithm\t\n\n";
    dijkstrasAlgorithm(graph, 0); 
}