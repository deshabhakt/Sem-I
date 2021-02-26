#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sockids(n);
    for(int i=0;i<n;i++)
    {
        cin >> sockids[i];
    }
    map<int,int> sockfreq;
    for(int i=0;i<n;i++)
    {
        int key = sockids[i];
        sockfreq[key]=sockfreq[key]+1;
    }
    map<int,int>::iterator it=sockfreq.begin();
    int pairs=0;
    while(it!=sockfreq.end())
    {
        cout << it->first <<":"<<it->second<<endl;
        pairs+=it->second/2;
        it++;
    }
    cout << "pairs " << pairs<<endl;
    return 0;
}