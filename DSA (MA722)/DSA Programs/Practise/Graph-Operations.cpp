#include <iostream>
using namespace std;

#define I 32676
#define N 8

// Using Queue as a supplimentary DS for BFS and DFS

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class queue
{
public:
    Node *front;
    Node *rear;
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        Node *tempf = front;
        if (tempf == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(Node *n)
    {
        
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next=n;
            rear=n;
        }
    }
    int dequeue()
    {
        Node *temp=new Node();
        temp = front;
        front = front->next;
        return temp->data;
    }
};

class Graph
{
    public:
    void BFS(int G[][N], int start, int n) //n--> matrix order
    {
        int i = start, j;
        int visited[N] = {0};
        queue q;
        cout << i << " ";
        visited[i]=1;
        Node* n1 = new Node();
        n1->data=i;
        n1->next=NULL;
        q.enqueue(n1);
        while(!q.isEmpty())
        {
            i=q.dequeue();
            for(j=1;j<n;j++)
            {
                if(visited[j]==0 && G[i][j]!=I)         // checking if node is visited or not and if edge exists
                {
                    cout << j << " ";
                    Node* n2 = new Node();
                    n2->data=j;
                    n2->next=NULL;
                    q.enqueue(n2);
                    visited[j]=1;
                }
            }
        }
    }

    void DFS(int G[][N],int start,int n)
    {
        static int visited[N] = {0};
        if(visited[start]==0)
        {
            cout << start << " ";
            visited[start]=1;
            for(int j=1;j<n;j++)
            {
            if(G[start][j]!=I && visited[j]==0)
            {
                DFS(G,j,n);
            }
            }
        }
    }
    void primsAlgo(int cost[][N],int near[],int t[][N-2])
{
    int i,j,k,u,v,n=N-1,min=I;
    /*Finding first min wt edge*/
    for(i=1;i<=n;i++)           //scanning upper triangular matrix for minimum weight edge
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;v=j;         // storing co-ordinates of min wt edge in u,v
            }
        }
    }
    near[u]=near[v]=0;          // marking corr near indices to 0 i.e marking edge as visited
    t[0][0]=u;t[1][0]=v;        // storing u,v in t matrix
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
        near[k]=0;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]] )
            {
                near[j]=k;
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
};
int main()
{
    Graph g;
    int cost[][N] = {{I, I, I, I, I, I, I, I},
                     {I, I, 25, I, I, I, 5, I},
                     {I, 25, I, 12, I, I, I, 10},
                     {I, I, 12, I, 8, I, I, I},
                     {I, I, I, 8, I, 16, I, 14},
                     {I, I, I, I, 16, I, 20, 18},
                     {I, 5, I, I, I, 20, I, I},
                     {I, I, 10, I, 14, 18, I, I}};
    int near[N] = {I, I, I, I, I, I, I, I};
    int t[2][N - 2];
    g.BFS(cost,1,N);
    cout << endl;
    g.DFS(cost,1,N);
    cout << endl;
    g.primsAlgo(cost,near,t);
}