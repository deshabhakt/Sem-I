#include<iostream>
#include<limits>
using namespace std;

#define SIZE 10
int hashfun(int key)
{
    return key%SIZE;
}
int probe(int H[],int key)
{
    int index=hashfun(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
        if(i>=10)
        {
            break;
        }
    }
    return (index+i)%SIZE;
}
void insert(int H[],int key)
{
    int index=hashfun(key);
    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
    cout << "Element inserted successfully at index " << index << "."<<endl;
}
int search(int H[],int key)
{
    int index=hashfun(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
    
}


int main()
{
    int HT[10]={};
    int index,input;
    do
    {  
        cout << "\n\nHashing with Linear Probing"<<endl;
        cout << "\n0.Info about Hashing with linear probing\n1.Insert Element\n2.Search\n3.Print Hash Table\n4.Clear Screen\n5.Quit\n>";
        cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        switch(input)
        {
            case 0:
                {
                    cout <<"\n**************** Hash Table With linear probing ****************"<<endl;
                    cout << "\n1.Load factor (which is ratio of Total number of elements in hash" <<      "\n  table and hash table size) should be <= 0.5";
                    cout << "\n2.Hence half of the hash table remains empty.";
                    cout << "\n3.It is not suggested to use hash table with deletion operation."<<
                            "\n  Since when Smashing occurs with shift element to next index,"<< 
                            "\n  so during deletion if we delete a element then we have to shift all" <<"\n  the elements by (-1) index.";
                    cout <<"\n4.During Searching if we find an empty space in Hash Table then we stop "<<"\n  the search at that index because it is certain that the element is "<<"\n  not present in the table";
                }
                break;
            case 1:
                {
                cout << "Insert Operation"<<endl;
                cout << "Enter element which you want to insert: ";
                cin >> index;
                int count=1;
                for(int i=0;i<SIZE;i++)
                {
                    if(HT[i]==0)
                    {
                        continue;
                    }
                    else
                    {
                        count++;
                    }
                }
                if(count>5)
                {
                    cout << "Exceeding Load factor."<<endl;
                    cout << "(Load factor should be less than or equal to  0.5)"<<endl;
                    cout << "Cannot add more entries to hash table."<<endl;
                }
                else
                {
                    insert(HT,index);
                }
                count=1;                
                break;
                }
            case 2:
                {
                cout << "Search Operation"<<endl;
                cout << "Enter Element which you want to search: ";
                cin >> index;
                int temp=search(HT,index);
                if(temp>=0&&temp<SIZE)
                {
                    cout << "Element found at index "<< temp<<endl;
                }
                else
                {
                    cout << "Element not found in hash table"<<endl;
                }
                break;
                }
            case 3:
                {
                cout << "The Hash Table is "<<endl;
                int sz=sizeof(HT)/sizeof(int);
                for(int i=0;i<sz;i++)
                {
                    cout << HT[i]<<" ";
                }
                cout <<endl;
                break;
                }
            case 4:
                {
                system("clear");
                break;
                }
            case 5:
                break;
            default:
                cout << "Invalid input\nTry again"<<endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();            
        }
    } while (input!=5);
    // insert(HT,10);
    // insert(HT,12);
    // insert(HT,2);
    // insert(HT,22);
    // cout << search(HT,2);
    return 0;

}