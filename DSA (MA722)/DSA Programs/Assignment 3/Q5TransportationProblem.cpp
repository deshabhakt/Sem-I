#include <iostream>
using namespace std;
int main()
{
    int flag = 0, flag1 = 0;
    int s[10], d[10], sn, eop = 1, dm, a[10][10];
    int i, j, sum = 0, min, x[10][10], k, fa, fb;
    /* Getting The Input For the Problem*/
    cout << "\n\t Transporation Problem \t\n" <<endl; 
    cout << "Enter the number of Sources:\n>";
    cin >> sn;
    cout << "\nEnter the number of Destinations\n>";
    cin >> dm;
    cout << "Enter the Supply Values:";
    for (i = 0; i < sn; i++)
    {
        cout << "\nSource " << (i+1) << ": ";
        cin >> s[i];
    }
    cout << "\nEnter the Demand Values: ";
    for (j = 0; j < sn; j++)
    {
        cout << "\nDestination " << (j+1) <<": ";
        cin >> d[j];
    }
    cout << "\nEnter costs row wise :\n";
    for (i = 0; i < sn; i++)
    {
        for (j = 0; j < dm; j++)
        {
            cout << ">";
            cin >> a[i][j];
        }
    }
    /* Calculation For the Transportation */
    i = 0;
    j = 0;
    for (i = 0, j = 0; i < sn, j < dm;)
    {
        if (s[i] < d[j]) // Check supply less than demand
        {
            x[i][j] = a[i][j] * s[i]; // Calculate  amount * supply
            d[j] = d[j] - s[i];       // Calculate demand - supply
            i++;                      // Increment i for the deletion of the row or column
        }
        else if (s[i] >= d[j])  //Check the supply greater than equal to demand
        {
            x[i][j] = a[i][j] * d[j]; // Calculate  amount * demand
            s[i] = s[i] - d[j];       // Calculate supply - demand
            j++;                      // Increment j for the deletion of the row or column
        }
    }
    cout << "\nGiven Cost Matrix is :\n";
    for (fa = 0; fa < sn; fa++)
    {
        for (fb = 0; fb < dm; fb++)
        {
            cout << a[fa][fb] << "\t";
        }
        cout << endl;
    }

    cout << "\nAllocated Cost Matrix is \n";
    for (fa = 0; fa < sn; fa++)
    {
        for (fb = 0; fb < dm; fb++)
        {
            if(x[fa][fb]!=0)
            {
                cout << x[fa][fb] << "\t";
            }
            else
            {
                cout <<"\t";
            }            
            sum = sum + x[fa][fb];
        }
        cout << endl;
    }
    cout << "\nThe Transportation cost: " << sum << endl<<endl;
}
