// Stack operations using Singly Linked List
// Roll NO. 202cd005
#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;
template<class T>
class Node
{
    public:
    int key;
    T data;
    Node<T>* next;
    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d)
    {
        key=k;
        data=d;
    }
};
template<class T>
class stack
{
    public:
    Node<T>* top;
    stack()
    {
        top=NULL;
    }
    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkIfNodeExists(Node<T>* n)
    {
        Node<T>* temp=top;
        bool exists = false;
        while(temp!=NULL)
        {
            if(temp->key==n->key)
            {
                exists = true;
                break;
            }
            temp=temp->next;
        }
        return exists;
    }
    void push(Node<T> *n)
    {
        if(top==NULL)
        {
            top=n;
        }
        else if(checkIfNodeExists(n))
        {
            cout << "Node with key value "<< n->key << " already exists in stack.";
        }
        else
        {
            n->next=top;
            top=n;
            cout << "Node pushed successfully."<<endl;
        }
    }
    Node<T>* pop()
    {
        Node<T>* temp=NULL;
        if(isEmpty())
        {
            cout << "Cannot perform pop operation!"<<endl;
            cout << "Stack is empty."<<endl;
            return temp;
        }
        else
        {
            temp=top;
            top = top->next;
            return temp;
        }
    }
    Node<T>* peek()
    {
        
        if(isEmpty())
        {
            cout << "Stack Underflow."<<endl;
            return NULL;
        }
        else
        {
            cout << "(" << top->key <<","<<top->data<<")    "<<endl;
            return top;
        }
    }
    int count()
    {
        int count =0;
        Node<T>* temp=top;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    void displayStack()
    {
        Node<T>* temp=top;
        if(isEmpty())
        {
            cout << "Nothing to Print."<<endl;
            cout << "Stack is empty!"<<endl;
        }
        else
        {
            while(temp!=NULL)
            {
                cout << "("<<temp->key<<","<<temp->data<<")   ";
                temp=temp->next;
            }
        }
    }
};
int main()
{
    int key1,varForDataTypeSelection, varForSwitchCase,count;
    do
    {
        cout << "\n=====================================================================================" << endl;
        cout << "********************* Stack Operations using Singly Linked list  ********************" << endl;
        cout << "=====================================================================================" << endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT     2.DOUBLE    3.FLOAT     4.CHAR     5.Clear Screen     6.Exit from program" << endl;
        cout << ">";
        cin >> varForDataTypeSelection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        if (varForDataTypeSelection == 1)
        {
            int data1;
            cout << "Selected Data type: INT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            stack<int> s;
            do
            {
                cout << "\n1.Check If stack is Empty\n2.Push Node\n3.Pop\n4.Peek\n5.Check number of elements in Stack\n6.Print stack\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<int> *newNode = new Node<int>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Stack is not Empty."<<endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Push Node Operation\nEnter key and data of node to be pushed:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.push(newNode);
                    break;
                }
                case 3:
                {
                    cout << "Pop Operation" << endl;
                    newNode=s.pop();
                    cout << "Node popped out ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    delete newNode;
                    break;
                }
                case 4:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty"<<endl;
                    }
                    else
                    {
                        cout << "Peek Operation" << endl;
                    newNode=s.peek();
                    cout << "Top of stack is ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    }
                    break;
                }
                case 5:
                {
                    count=s.count();
                    cout << "Number of elements in stack are "<<count <<"."<<endl;
                    break;
                }
                case 6:
                {
                    cout << "Stack is: " << endl;
                    s.displayStack();
                    break;
                }
                case 7:
                {
                    system("clear");
                    break;
                }
                case 8:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (varForDataTypeSelection == 2)
        {
            double data1;
            cout << "Selected Data type: DOUBLE" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            stack<double> s;
            do
            {
                cout << "\n1.Check If stack is Empty\n2.Push Node\n3.Pop\n4.Peek\n5.Check number of elements in Stack\n6.Print stack\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<double> *newNode = new Node<double>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Stack is not Empty."<<endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Push Node Operation\nEnter key and data of node to be pushed:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.push(newNode);
                    break;
                }
                case 3:
                {
                    cout << "Pop Operation" << endl;
                    newNode=s.pop();
                    cout << "Node popped out ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    delete newNode;
                    break;
                }
                case 4:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty"<<endl;
                    }
                    else
                    {
                        cout << "Peek Operation" << endl;
                    newNode=s.peek();
                    cout << "Top of stack is ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    }
                    break;
                }
                case 5:
                {
                    count=s.count();
                    cout << "Number of elements in stack are "<<count <<"."<<endl;
                    break;
                }
                case 6:
                {
                    cout << "Stack is: " << endl;
                    s.displayStack();
                    break;
                }
                case 7:
                {
                    system("clear");
                    break;
                }
                case 8:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (varForDataTypeSelection == 3)
        {
            float data1;
            cout << "Selected Data type: FLOAT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            stack<float> s;
            do
            {
                cout << "\n1.Check If stack is Empty\n2.Push Node\n3.Pop\n4.Peek\n5.Check number of elements in Stack\n6.Print stack\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<float> *newNode = new Node<float>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Stack is not Empty."<<endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Push Node Operation\nEnter key and data of node to be pushed:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.push(newNode);
                    break;
                }
                case 3:
                {
                    cout << "Pop Operation" << endl;
                    newNode=s.pop();
                    cout << "Node popped out ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    delete newNode;
                    break;
                }
                case 4:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty"<<endl;
                    }
                    else
                    {
                        cout << "Peek Operation" << endl;
                    newNode=s.peek();
                    cout << "Top of stack is ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    }
                    break;
                }
                case 5:
                {
                    count=s.count();
                    cout << "Number of elements in stack are "<<count <<"."<<endl;
                    break;
                }
                case 6:
                {
                    cout << "Stack is: " << endl;
                    s.displayStack();
                    break;
                }
                case 7:
                {
                    system("clear");
                    break;
                }
                case 8:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (varForDataTypeSelection == 4)
        {
            char data1;
            cout << "Selected Data type: CHAR" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            stack<char> s;
            do
            {
                cout << "\n1.Check If stack is Empty\n2.Push Node\n3.Pop\n4.Peek\n5.Check number of elements in Stack\n6.Print stack\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<char> *newNode = new Node<char>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Stack is not Empty."<<endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Push Node Operation\nEnter key and data of node to be pushed:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.push(newNode);
                    break;
                }
                case 3:
                {
                    cout << "Pop Operation" << endl;
                    newNode=s.pop();
                    cout << "Node popped out ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    delete newNode;
                    break;
                }
                case 4:
                {
                    if(s.isEmpty())
                    {
                        cout << "Stack is Empty"<<endl;
                    }
                    else
                    {
                        cout << "Peek Operation" << endl;
                    newNode=s.peek();
                    cout << "Top of stack is ("<<newNode->key<<","<<newNode->data<<")"<<endl;
                    }
                    break;
                }
                case 5:
                {
                    count=s.count();
                    cout << "Number of elements in stack are "<<count <<"."<<endl;
                    break;
                }
                case 6:
                {
                    cout << "Stack is: " << endl;
                    s.displayStack();
                    break;
                }
                case 7:
                {
                    system("clear");
                    break;
                }
                case 8:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (varForDataTypeSelection == 5)
        {
            system("clear");
        }
        else if (varForDataTypeSelection == 6)
        {
            cout << "\n\nThanks for Using Program!" << endl;
            cout << "Program Ended\n\n" << endl;
            cout << "=====================================================================================" << endl;
            cout << "=====================================================================================" << endl;
            break;
        }
        else
        {
            cout << "Invalid input!\nTry Again:)" << endl;
        }
    }while (varForDataTypeSelection != 6);
    return 0;
}