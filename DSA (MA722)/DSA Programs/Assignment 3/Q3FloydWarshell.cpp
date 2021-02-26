#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX

void flyodWarshall(vector<vector<int>> g)
{
	int V = g.size();

	vector<vector<int>> dist = g;

	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				if (dist[i][k] != I && dist[k][j] != I && dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	cout << endl;
	cout << "The Shortest path between any vertices is:\n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INT_MAX)
			{
				cout << "INFINITE\t";
				continue;
			}
			cout << dist[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int V;
	cout << "\n\tShortest Path between Any Pair of Vertices\n\n";
	cout << "Enter the number of vertex in the g: ";
	cin >> V;
	vector<vector<int>> g(V, vector<int>(V));

	cout << "INFINITE: " << I << endl;
	cout << "Enter the weights of the each Edges:\n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << ">";
			cin >> g[i][j];
		}
	}

	flyodWarshall(g);
}
