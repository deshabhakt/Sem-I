void primsAlgo(int cost[][N], int near[], int t[][N - 2])
{
    int i, j, k, u, v, n = N - 1, min = I;
    for (i = 1; i <= n; i++) // finding minimum cost edge from upper triangular matrix
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
            {
                near[j] = k;
            }
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")";
        if(i!=n-2)
        {
            cout << " --> ";
        }
    }
    cout << endl;
}