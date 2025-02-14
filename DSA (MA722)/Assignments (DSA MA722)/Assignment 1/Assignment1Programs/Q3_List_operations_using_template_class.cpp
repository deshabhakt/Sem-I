// List operations
// Roll No. 202cd005

#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;
template <class T>
class mylist
{
private:
    char ch;
    int user_input_for_switch, arraysize;
    T element;
    T *list;

public:
    mylist(T arr[])
    {
        arraysize=arraySize(arr);
    }
    void setArray(const int &size)
    {
        list = new T[size];
        for (int i = 0; i < size; i++)
        {
            cout << ">";
            cin >> list[i];
        }
    }
    void getArray(unsigned int x, T arr[])
    {
        cout << "{";
        for (int i = 0; i < x; i++)
        {
            cout << arr[i];
            if (i < x - 1)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;
    }
    void deleteElement(const int index, T arr[])
    {
        if (index > arraysize)
        {
            cout << "Index out of range";
        }
        else
        {
            for (int i = 0; i < arraysize; i++)
            {
                if (i >= index)
                {
                    arr[i] = arr[i + 1];
                }
            }
            cout << "Array after deletion : ";
            arraysize--;
            getArray(arraysize, arr);
        }
    }
    unsigned int arraySize(T arr[])
    {
        int i = 0;
        while (arr[i] != '\0')
        {
            i++;
        }
        return i;
    }
    const int fetchIndex(T element_whose_index_to_be_fetched, T arr[])
    {
        int s = '\0', i;
        T x = element_whose_index_to_be_fetched;
        for (i = 0; i < arraysize; i++)
        {
            if (x == arr[i])
            {
                s = arr[i];
                break;
            }
        }
        if (s != '\0')
        {
            cout << "index of element " << x << " is " << i << endl;
        }
        else
        {
            cout << "Element not in list" << endl;
        }

        return i;
    }
    void fetchElement(const int index, T arr[])
    {
        if (index < arraysize)
        {
            cout << "Element present at index " << index << " is " << arr[index] << "." << endl;
        }
        else
        {
            cout << "Index out of range." << endl;
        }
    }
    void insertElement(const int index, T element_to_be_added, T arr[])
    {
        if (index > arraysize)
        {
            cout << "Index out of range." << endl;
        }
        else if (checkIfElementToBeAddedIsPresentInListORnot(element_to_be_added,arr) >0)
        {
            cout << "Same element already present in list." << endl;
            cout << "Original list is : ";
            getArray(arraysize,arr);
        }
        else
        {
            for (int i = 0; i <= arraysize; i++)
            {
                if(i==index)
                {
                    for (int j = arraysize - 1; j >= i; j--)
                    {
                        arr[j + 1] = arr[j];
                    }
                    arr[i] = element_to_be_added;
                    cout << "Updated list is : ";
                    getArray(++arraysize, arr);
                    break;
                }
            }
        }
    }
    int checkIfElementToBeAddedIsPresentInListORnot(T element_to_be_added,T arr[])
    {
        int temp=0;
        for (int i = 0; i <= arraysize; i++)
        {
            if (arr[i] == element_to_be_added)
            {
                temp++;
            }
            else
            {
                continue;
            }           
        }
        return temp;
    }
    bool empty(T arr[])
    {
        if (arraysize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void commonSwitchCaseBlockforBuiltInList(mylist ls, T builtInList[])
    {
        do
        {
            cout << "Using buit-in list...." << endl;
            cout << "Which Operation do you want to perform?: "
                 << " \n 1.Check if list is empty"
                 << "\n 2.Print List"
                 << "\n 3.Size of List"
                 << "\n 4.Delete element from list"
                 << "\n 5.Fetch index of an element "
                 << "\n 6.Fetch element from list "
                 << "\n 7.Insert element in list"
                 << "\n 8.Clear Screen"
                 << "\n 9.Go To Previous menu" <<endl;
            cout << ">";
            cin >> user_input_for_switch;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            if (ls.arraySize(builtInList) > 0)
            {
                switch (user_input_for_switch)
                {
                case 1:
                    if(ls.empty(ls.list))
                    {
                        cout << "List is empty."<<endl;
                    }
                    else
                    {
                        cout << "List is not empty."<<endl;
                    }
                    break;
                case 2:
                    cout << "The list is ";
                    ls.getArray(ls.arraySize(builtInList), builtInList);
                    break;
                case 3:
                    cout << "Size of list is " << ls.arraySize(builtInList) << "." << endl;
                    break;
                case 4:
                    int del_idx;
                    cout << "Enter index number of element which you want to delete: ";
                    cin >> del_idx;
                    ls.deleteElement(del_idx, builtInList);
                    break;
                case 5:
                    cout << "Enter element who's index number you want to find: ";
                    cin >> ls.element;
                    ls.fetchIndex(ls.element, builtInList);
                    break;
                case 6:
                    int fetch_element_at_index;
                    cout << "Enter index number of element which you want to find: ";
                    cin >> fetch_element_at_index;
                    ls.fetchElement(fetch_element_at_index, builtInList);
                    break;
                case 7:
                    int in_idx;
                    cout << "Enter index at which you want to insert element: " << endl;
                    cin >> in_idx;
                    cout << "Enter element which you want to add: " << endl;
                    cin >> ls.element;
                    ls.insertElement(in_idx, ls.element, builtInList);
                    break;
                case 8:
                    system("clear");
                    break;
                case 9:
                    break;
                default:
                    cout << "Invalid input! please try agian." << endl;
                }
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "List is empty.\nCannot perform opeartions." << endl;
            }
        }while(user_input_for_switch!=9);
    }
    void commonSwitchCaseBlockforDynamicList(mylist ls)
    {
        do
        {
            cout << "Which Operation do you want to perform?: "
                 << " \n 1.Check if list is empty"
                 << "\n 2.Print List"
                 << "\n 3.Size of List"
                 << "\n 4.Delete element from list"
                 << "\n 5.Fetch index of an element "
                 << "\n 6.Fetch element from list "
                 << "\n 7.Insert element in list" 
                 << "\n 8.Clear Screen"
                 << "\n 9.Go To Previous menu" << endl;
            cout << ">";
            cin >> user_input_for_switch;
            if (ls.arraySize(ls.list) > 0)
            {
                switch (user_input_for_switch)
                {
                case 1:
                    if(ls.empty(ls.list))
                    {
                        cout << "List is empty."<<endl;
                    }
                    else
                    {
                        cout << "List is not empty."<<endl;
                    }
                    break;
                case 2:
                    cout << "The list is ";
                    ls.getArray(ls.arraySize(ls.list), ls.list);
                    break;
                case 3:
                    cout << "Size of list is " << ls.arraySize(ls.list) << "." << endl;
                    break;
                case 4:
                    int del_idx;
                    cout << "Enter index number of element which you want to delete: ";
                    cin >> del_idx;
                    ls.deleteElement(del_idx, ls.list);
                    break;
                case 5:
                    cout << "Enter element who's index number you want to find: ";
                    cin >> ls.element;
                    ls.fetchIndex(ls.element, ls.list);
                    break;
                case 6:
                    int fetch_element_at_index;
                    cout << "Enter index number of element which you want to find: ";
                    cin >> fetch_element_at_index;
                    ls.fetchElement(fetch_element_at_index, ls.list);
                    break;
                case 7:
                    int in_idx;
                    cout << "Enter index at which you want to insert element: " << endl;
                    cin >> in_idx;
                    cout << "Enter element which you want to add: " << endl;
                    cin >> ls.element;
                    ls.insertElement(in_idx, ls.element, ls.list);
                    break;
                case 8:
                    system("clear");
                    break;
                case 9:
                    break;
                default:
                    cout << "Invalid input! please try agian." << endl;
                }
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "List is empty.\nCannot perform opeartions." << endl;
            }
        }while(user_input_for_switch!=9);
    }
};
int main()
{
    char ch;
    int index, store_size, varForDataTypeSelection, varForListSizeInputFromUser;
    do
    {
        cout <<"\n====================================================================================="<<endl;
        cout <<"******************************* Linear list Operations ******************************"<<endl;
        cout <<"====================================================================================="<<endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT       2.CHAR      3.FLOAT      4.Clear Screen        5.End Program" << endl;
        cout << ">";
        cin >> varForDataTypeSelection;
        if (varForDataTypeSelection == 1)
        {
            cout <<"Selected data type: INT"<<endl;
            int builtInList[10] = {1,2,3,4,5,6,7};
            mylist<int> ls(builtInList), callobj(builtInList);
            cout << "Chose between following options:"
                 << "\nEnter 1 if you want to use buit-in list"
                 << "\nEnter 2 if you want to use your own list"
                 << "\n> ";
            int opt_user;
            cin >> opt_user;
            if (opt_user == 1)
            {
                callobj.commonSwitchCaseBlockforBuiltInList(ls, builtInList);
            }
            else if (opt_user == 2)
            {
                cout << "Enter size of list: ";
                cin >> varForListSizeInputFromUser;
                cout << "\nEnter List elements: " << endl;
                ls.setArray(varForListSizeInputFromUser);
                callobj.commonSwitchCaseBlockforDynamicList(ls);
            }
        }
        else if (varForDataTypeSelection == 2)
        {
            cout <<"Selected data type: CHAR"<<endl;
            char builtInList[10] = {'a','b','c','d','e','f','g'};
            mylist<char> ls(builtInList), callobj(builtInList);
            cout << "Chose between following options:"
                 << "\nEnter 1 if you want to use buit-in list"
                 << "\nEnter 2 if you want to use your own list"
                 << "\n> ";
            int opt_user;
            cin >> opt_user;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            if (opt_user == 1)
            {
                callobj.commonSwitchCaseBlockforBuiltInList(ls, builtInList);
            }
            else if (opt_user == 2)
            {
                cout << "Enter size of list: ";
                cin >> varForListSizeInputFromUser;
                cout << "\nEnter List elements: " << endl;
                ls.setArray(varForListSizeInputFromUser);
                callobj.commonSwitchCaseBlockforDynamicList(ls);
            }
        }
        else if (varForDataTypeSelection == 3)
        {
            cout <<"Selected data type: FLOAT"<<endl;
            float builtInList[10] = {1.5,2.5,3.5,4.5,5.5};
            mylist<float> ls(builtInList), callobj(builtInList);
            cout << "Chose between following options:"
                 << "\nEnter 1 if you want to use buit-in list"
                 << "\nEnter 2 if you want to use your own list"
                 << "\n> ";
            int opt_user;
            cin >> opt_user;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            if (opt_user == 1)
            {
                callobj.commonSwitchCaseBlockforBuiltInList(ls, builtInList);
            }
            else if (opt_user == 2)
            {
                cout << "Enter size of list: ";
                cin >> varForListSizeInputFromUser;
                cout << "\nEnter List elements: " << endl;
                ls.setArray(varForListSizeInputFromUser);
                callobj.commonSwitchCaseBlockforDynamicList(ls);
            }
        }
        else if(varForDataTypeSelection == 4)
        {
            system("clear");
        }
        else if(varForDataTypeSelection == 5)
        {
            cout << "\nProgram Ended"<<endl;
            cout<<"\n====================================================================================="<<endl;
            break;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            cout << "Invalid input!\nTry again :)";
        }
    }while(varForDataTypeSelection!=5);
    return 0;
}