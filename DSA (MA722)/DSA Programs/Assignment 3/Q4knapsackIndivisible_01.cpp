#include <iostream>
using namespace std;

int knapSackRec(int W, int wt[],int val[], int i,int **dp)
{
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)
    {

        dp[i][W] = knapSackRec(W, wt,val, i - 1,dp);
        return dp[i][W];
    }
    else
    {
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));

        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {10, 18, 20};
    int W ;
    int n = sizeof(val) / sizeof(val[0]);
    cout <<"\nKnapsack Problem Implementation"<<
           "\n   (Indivisible Objects)\n";
    cout << "Values: ";
    for(int i=0;i<n;i++)
    {
        cout << " " << val[i];
    }
    cout << "\nWeights:";
    for(int i=0;i<n;i++)
    {
        cout << " " << wt[i];
    }
    cout << "\nEnter Weight limit:\n>";
    cin >> W;
    cout << "\nWeight limit: " << W << endl;
    cout << "Max Value that can be obtained for given weight limit: " << knapSack(W, wt, val, n) << endl;
    return 0;
}
