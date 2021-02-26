#include <iostream>
#include<string>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	for(int i=0;i<n;i++)
	{
        string path;
        cin>>path;
       
	}
	for(int i=0;i<n;i++)
	{
	     if(path[0]==path[path.length()-1])
	    {
	        cout <<"Circular\n";
	    }
	    else
	    {
	        cout << "Not Circular\n";
	    }
	}
	return 0;
}