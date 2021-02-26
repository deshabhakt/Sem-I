#include <iostream>
#define I 32767             //setting I to Maximum value
using namespace std;
 
int main()
{
    int cost[8][8] = {{I, I, I, I, I, I, I, I},
                     {I, I, 25, I, I, I, 5, I},
                     {I, 25, I, 12, I, I, I, 10},
                     {I, I, 12, I, 8, I, I, I},
                     {I, I, I, 8, I, 16, I, 14},
                     {I, I, I, I, 16, I, 20, 18},
                     {I, 5, I, I, I, 20, I, I},
                     {I, I, 10, I, 14, 18, I, I}};
    int near[8] = {I, I, I, I, I, I, I, I};
    int t[3][6];
    int i,j,k,u,v,w,n=7,min=I;        //n=7 because we're skipping first row and first column

    /*Finding first min wt edge*/
    
    for(i=1;i<=n;i++)           //scanning upper triangular matrix for minimum weight edge
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;v=j;w=cost[i][j];         // storing co-ordinates of min wt edge in u,v
            }
        }
    }
    near[u]=near[v]=0;          // marking corr near indices to 0 i.e marking edge as visited
    t[0][0]=u;t[1][0]=v;t[2][0]=w;        // storing u,v in t matrix
    for(i=1;i<=n;i++)
    {
        if(near[i]!=0)          // check if node is not visited
        {
            if(cost[i][u]<cost[i][v])       // compare wt of near edges and update them in near array
                near[i]=u;
            else
                near[i]=v;
        }
    }
    /* doing above procedure for all remaining edges */
    for(i=1;i<n-1;i++)         
    {
        min=I;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min)
            {
                k=j;
                min=cost[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        t[2][i]=min;
        near[k]=0;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]] )
            {
                near[j]=k;
            }
        }
    }
    cout << "\n\tPrim's Algorithm\n";
    cout << "\nOutput is printed in following form: (start vertex, end vertex, weight)" << endl;
    cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << "," << t[2][i] <<")";
        if(i!=n-2)
        {
            cout << " --> ";
        }
    }
    int t_wt=0;
    for(int i=0;i<n-1;i++)
    {
        t_wt+=t[2][i];
    }
    cout << "\n\nTotal Minimum Weight: " << t_wt << endl;
    cout << endl;
}