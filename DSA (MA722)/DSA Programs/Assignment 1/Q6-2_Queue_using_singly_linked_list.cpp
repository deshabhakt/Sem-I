// Queue using singly linked list
// Roll No. 202cd005
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Node
{
public:
    int key;
    T data;
    Node<T> *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, T d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
template <class T>
class queue
{
public:
    Node<T> *front;
    Node<T> *rear;
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        Node<T> *tempf = front;
        Node<T> *tempr = rear;
        if (tempf == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node<T> *checkIfNodeExists(Node<T> *n)
    {
        Node<T> *ptr = NULL;
        Node<T> *temp = front;
        if (temp == n)
        {
            ptr = temp;
            return ptr;
        }
        else
        {
            temp = rear;
            while (temp != NULL)
            {
                if (temp->key == n->key)
                {
                    ptr = temp;
                }
                temp = temp->next;
            }
            return ptr;
        }
    }
    void enqueue(Node<T> *n)
    {
        Node<T> *temp = checkIfNodeExists(n);
        if (temp != NULL)
        {
            cout << "Node with key value " << temp->key << " already exists in queue." << endl;
        }
        else if (front == NULL)
        {
            front = n;
            rear = n;
            cout << "First element Enqueued successfully." << endl;
        }
        else
        {
            rear->next=n;
            rear=n;
            cout << "Next element Enqueued successfully." << endl;
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is empty.\nCannot perform dequeue operation." << endl;
        }
        else
        {
            if(front==rear)
            {
                front=NULL;
                rear=NULL;
            }
            else
            {
                front=front->next;
            }
            cout << "Node dequeued successfully."<<endl;
        }
    }
    int count()
    {
        int count = 0;
        Node<T> *ptr = rear;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    void displayQueue()
    {
        Node<T> *tempr = front;
        if (isEmpty())
        {
            cout << "Nothing to Print.\nQueue is Empty:(" << endl;
        }
        else
        {
            while (tempr != NULL)
            {
                
                cout << "(" << tempr->key << "," << tempr->data << ")   ";
                tempr = tempr->next;
            }
        }
    }
};
int main()
{
    int key1, varForDataTypeSelection, varForSwitchCase, count;
    do
    {
        cout << "\n=====================================================================================" << endl;
        cout << "********************* Queue using Operations Singly Linked list *********************" << endl;
        cout << "=====================================================================================" << endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT     2.DOUBLE    3.FLOAT     4.CHAR     5.Clear Screen     6.Exit from program" << endl;
        cout << ">";
        cin >> varForDataTypeSelection;
        
        if (varForDataTypeSelection == 1)
        {
            int data1;
            cout << "Selected Data type: INT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            queue<int> s;
            do
            {
                cout << "\n1.Check If queue is Empty\n2.Enqueue\n3.dequeue\n4.Check number of elements in queue\n5.Print queue\n6.Clear Screen\n7.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<int> *newNode = new Node<int>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if (s.isEmpty())
                    {
                        cout << "queue is Empty." << endl;
                    }
                    else
                    {
                        cout << "queue is not Empty." << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enqueue Operation\nEnter key and data of node to be enqueued:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.enqueue(newNode);
                    break;
                }
                case 3:
                {
                    cout << "dequeue Operation" << endl;
                    s.dequeue();
                    break;
                }
                case 4:
                {
                    count = s.count();
                    cout << "Number of elements in queue are " << count << "." << endl;
                    break;
                }
                case 5:
                {
                    cout << "queue is: " << endl;
                    s.displayQueue();
                    break;
                }
                case 6:
                {
                    system("clear");
                    break;
                }
                case 7:
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
            } while (varForSwitchCase != 7);
        }
        else if (varForDataTypeSelection == 2)
        {
            double data1;
            cout << "Selected Data type: DOUBLE" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            queue<double> s;
            do
            {
                cout << "\n1.Check If queue is Empty\n2.Enqueue\n3.dequeue\n4.Check number of elements in queue\n5.Print queue\n6.Clear Screen\n7.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<double> *newNode = new Node<double>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if (s.isEmpty())
                    {
                        cout << "queue is Empty." << endl;
                    }
                    else
                    {
                        cout << "queue is not Empty." << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enqueue Operation\nEnter key and data of node to be enqueued:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.enqueue(newNode);
                    break;
                }
                case 3:
                {
                    cout << "dequeue Operation" << endl;
                    s.dequeue();
                    break;
                }
                case 4:
                {
                    count = s.count();
                    cout << "Number of elements in queue are " << count << "." << endl;
                    break;
                }
                case 5:
                {
                    cout << "queue is: " << endl;
                    s.displayQueue();
                    break;
                }
                case 6:
                {
                    system("clear");
                    break;
                }
                case 7:
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
            } while (varForSwitchCase != 7);
        }
        else if (varForDataTypeSelection == 3)
        {
            float data1;
            cout << "Selected Data type: FLOAT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            queue<float> s;
            do
            {
                cout << "\n1.Check If queue is Empty\n2.Enqueue\n3.dequeue\n4.Check number of elements in queue\n5.Print queue\n6.Clear Screen\n7.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<float> *newNode = new Node<float>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if (s.isEmpty())
                    {
                        cout << "queue is Empty." << endl;
                    }
                    else
                    {
                        cout << "queue is not Empty." << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enqueue Operation\nEnter key and data of node to be enqueued:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.enqueue(newNode);
                    break;
                }
                case 3:
                {
                    cout << "dequeue Operation" << endl;
                    s.dequeue();
                    break;
                }
                case 4:
                {
                    count = s.count();
                    cout << "Number of elements in queue are " << count << "." << endl;
                    break;
                }
                case 5:
                {
                    cout << "queue is: " << endl;
                    s.displayQueue();
                    break;
                }
                case 6:
                {
                    system("clear");
                    break;
                }
                case 7:
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
            } while (varForSwitchCase != 7);
        }
        else if (varForDataTypeSelection == 4)
        {
            char data1;
            cout << "Selected Data type: CHAR" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            queue<char> s;
            do
            {
                cout << "\n1.Check If queue is Empty\n2.Enqueue\n3.dequeue\n4.Check number of elements in queue\n5.Print queue\n6.Clear Screen\n7.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<char> *newNode = new Node<char>();
                switch (varForSwitchCase)
                {
                case 1:
                {
                    if (s.isEmpty())
                    {
                        cout << "Queue is Empty." << endl;
                    }
                    else
                    {
                        cout << "Queue is not Empty." << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enqueue Operation\nEnter key and data of node to be enqueued:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    newNode->key = key1;
                    newNode->data = data1;
                    s.enqueue(newNode);
                    break;
                }
                case 3:
                {
                    cout << "Dequeue Operation" << endl;
                    s.dequeue();
                    break;
                }
                case 4:
                {
                    count = s.count();
                    cout << "Number of elements in queue are " << count << "." << endl;
                    break;
                }
                case 5:
                {
                    cout << "Queue is: " << endl;
                    s.displayQueue();
                    break;
                }
                case 6:
                {
                    system("clear");
                    break;
                }
                case 7:
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
            } while (varForSwitchCase != 7);
        }
        else if (varForDataTypeSelection == 5)
        {
            system("clear");
        }
        else if (varForDataTypeSelection == 6)
        {
            cout << "\n\nThanks for Using Program!" << endl;
            cout << "Program Ended\n\n"
                 << endl;
            cout << "=====================================================================================" << endl;
            cout << "=====================================================================================" << endl;
            break;
        }
        else
        {
            cout << "Invalid input!\nTry Again:)" << endl;
        }
    } while (varForDataTypeSelection != 6);
    return 0;
}