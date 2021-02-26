#include<iostream>
using namespace std;

#define I 32767

int edge[9][3]={{1,2,15},{1,6,10},{2,5,25},{2,7,14},{3,4,22},
{4,5,52},{4,7,21},{3,6,25},{5,7,34}};

int s[8]={-1,-1,-1,-1,-1,-1,-1,-1};

int t[3][6];

int included[9]={0};

void unionfunc(int u,int v)
{
    if(s[u]<s[v])
    {
        s[u]=s[u]+s[v];
        s[v]=u;
    }
    else
    {
        s[v]=s[u]+s[v];
        s[u]=v;
    }
}
int find(int u)
{
    int x=u,v=0;
    while(s[x]>0)
    {
        x=s[x];
    }
    /*connecting node to head node*/
    while(u!=x)
    {
        v=s[u];
        s[u]=x;
        u=v;
    }
    return x;
}
int main()
{
    int u=0,v=0,i,j,k=0,min=I,n=7,e=9;          //e-->number of edges
    i=0;
    while(i<n-1)
    {
        min=I;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edge[j][2]<min)
            {
                u=edge[j][0];
                v=edge[j][1];
                min=edge[j][2];
                k=j;
            }
        }
        if(find(u)!=find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            t[2][i]=min;
            unionfunc(find(u),find(v));
            i++;
        }
        included[k]=1;
    }
    cout << "\n\tKrushkal's Algorithm\n";
    cout << "\nOutput is printed in following form: (start vertex, end vertex, weight)" << endl;
    cout << "\nMinimum Spanning Tree using Krushkal's Algorithm:\n";
    for (i = 0; i < n-1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << "," << t[2][i] <<")";
        if(i!=n-2)
        {
            cout << " --> ";
        }
    }
    int t_wt=0;
    for(int i=0;i<n;i++)
    {
        t_wt+=t[2][i];
    }
    cout << "\n\nTotal Minimum Weight: " << t_wt << endl;
    cout << endl;
}