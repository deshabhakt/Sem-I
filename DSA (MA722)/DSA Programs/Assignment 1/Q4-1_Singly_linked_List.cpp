// Singly Linked List Execution and its operations
// Roll No. 202cd005

#include <iostream>
#include <stdlib.h>
#include <limits>
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
    }
};
template <class T>
class SinglyLinkedList
{
public:
    Node<T> *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node<T> *n)
    {
        head = n;
    }
    Node<T>* nodeExists(int k)
    {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void appendNode(Node<T> *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << "." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended Successfully." << endl;
            }
            else
            {
                Node<T> *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended Successfully." << endl;
            }
        }
    }
    void prependNode(Node<T> *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value" << n->key << "." << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended Successfully." << endl;
        }
    }
    void insertNodeAfter(int k, Node<T> *n)
    {
        Node<T> *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node Exists with key value " << k << "." << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value" << n->key << "." << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List is empty.\nCannot perform deletion." << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key value " << k << "." << endl;
            }
            else
            {
                Node<T> *temp = NULL;
                Node<T> *prevptr = head;
                Node<T> *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node unlinked with key value " << k << " successfully." << endl;
                }
                else
                {
                    cout << "Node doesn't exists with key value " << k << "." << endl;
                }
            }
        }
    }
    void updateNodeByKey(int k, T d)
    {
        Node<T> *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully." << endl;
        }
        else
        {
            cout << "Node doesn't exist with key value " << k << "." << endl;
        }
    }
    void printLinkedList()
    {
        if (head == NULL)
        {
            cout << "No nodes in singly linked list" << endl;
        }
        else
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")   ";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    int  key1, k1;
    char varForDataTypeSelection, varForSwitchCase;
    do
    {
        Title:
        cout << "\n=====================================================================================" << endl;
        cout << "**************************** Singly Linked list Operations **************************" << endl;
        cout << "=====================================================================================" << endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT     2.DOUBLE    3.FLOAT     4.CHAR     5.Clear Screen     6.Exit from program" << endl;
        cout << ">";
        cin >> varForDataTypeSelection;
        if(!isdigit(varForDataTypeSelection))
        {
            cout << "Invalid Input" << endl;
            goto Title;
        }
        if (((int)varForDataTypeSelection - '0') == 1)
        {
            int data1;
            cout << "Selected Data type: INT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            SinglyLinkedList<int> s, callobj;
            do
            {
                label:
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print singly linked list\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                if(!isdigit(varForSwitchCase))
                {
                    cout << "Invalid input" << endl;
                    goto label;
                }
                Node<int> *n1 = new Node<int>();
                switch ((int)varForSwitchCase - '0')
                {
                case 1:
                {
                    cout << "Append Node Operation\nEnter Key & data of node to be appended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.appendNode(n1);
                    break;
                }
                case 2:
                {
                    cout << "Prepend Node Operation\nEnter key and data of node to be prepended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.prependNode(n1);
                    break;
                }
                case 3:
                {
                    cout << "Insert Node Operation" << endl;
                    cout << "Enter key of node after which you want to insert a node:\n>";
                    cin >> k1;
                    if (s.nodeExists(k1))
                    {
                        cout << "Enter key and data of node to be inserted:" << endl;
                        cout << ">";
                        cin >> key1;
                        cout << ">";
                        cin >> data1;
                        n1->key = key1;
                        n1->data = data1;
                        s.insertNodeAfter(k1, n1);
                    }
                    else
                    {
                        cout << "No node exists with entered key value." << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Delete Node Operation (Deletion by key of node)" << endl;
                    cout << "Enter key value of node to be deleted:" << endl;
                    cout << ">";
                    cin >> k1;
                    s.deleteNodeByKey(k1);
                    break;
                }
                case 5:
                {
                    cout << "Update data of Node with key value" << endl;
                    cout << "Enter key of node who's data is to be updated: ";
                    cin >> k1;
                    cout << "\nEnter new data: ";
                    cin >> data1;
                    cout << endl;
                    s.updateNodeByKey(k1, data1);
                    break;
                }
                case 6:
                {
                    cout << "Linked list is: " << endl;
                    s.printLinkedList();
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
                    goto Title;break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (((int)varForDataTypeSelection - '0') == 2)
        {
            double data1;
            cout << "Selected Data type: DOUBLE" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            SinglyLinkedList<double> s;
            do
            {
                label2:
                Node<double> *n1 = new Node<double>();
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print singly linked list\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                if(!isdigit(varForSwitchCase))
                {
                    cout << "Invalid input" << endl;
                    goto label2;
                }
                switch ((int)varForSwitchCase - '0')
                {
                case 1:
                {
                    cout << "Append Node Operation\nEnter Key & data of node to be appended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.appendNode(n1);
                    break;
                }
                case 2:
                {
                    cout << "Prepend Node Operation\nEnter key and data of node to be prepended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.prependNode(n1);
                    break;
                }
                case 3:
                {
                    cout << "Insert Node Operation" << endl;
                    cout << "Enter key of node after which you want to insert a node:\n>";
                    cin >> k1;
                    if (s.nodeExists(k1))
                    {
                        cout << "Enter key and data of node to be inserted:" << endl;
                        cout << ">";
                        cin >> key1;
                        cout << ">";
                        cin >> data1;
                        n1->key = key1;
                        n1->data = data1;
                        s.insertNodeAfter(k1, n1);
                    }
                    else
                    {
                        cout << "No node exists with entered key value." << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Delete Node Operation (Deletion by key of node)" << endl;
                    cout << "Enter key value of node to be deleted:" << endl;
                    cout << ">";
                    cin >> k1;
                    s.deleteNodeByKey(k1);
                    break;
                }
                case 5:
                {
                    cout << "Update data of Node with key value" << endl;
                    cout << "Enter key of node who's data is to be updated: ";
                    cin >> k1;
                    cout << "\nEnter new data: ";
                    cin >> data1;
                    cout << endl;
                    s.updateNodeByKey(k1, data1);
                    break;
                }
                case 6:
                {
                    cout << "Linked list is: " << endl;
                    s.printLinkedList();
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
                    goto Title;break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (((int)varForDataTypeSelection - '0') == 3)
        {
            float data1;
            cout << "Selected Data type: FLOAT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            SinglyLinkedList<float> s;
            do
            {
                label3:
                Node<float> *n1 = new Node<float>();
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print singly linked list\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                if(!isdigit(varForSwitchCase))
                {
                    cout << "Invalid input" << endl;
                    goto label3;
                }
                switch ((int)varForSwitchCase-'0')
                {
                case 1:
                {
                    cout << "Append Node Operation\nEnter Key & data of node to be appended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.appendNode(n1);
                    break;
                }
                case 2:
                {
                    cout << "Prepend Node Operation\nEnter key and data of node to be prepended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.prependNode(n1);
                    break;
                }
                case 3:
                {
                    cout << "Insert Node Operation" << endl;
                    cout << "Enter key of node after which you want to insert a node:\n>";
                    cin >> k1;
                    if (s.nodeExists(k1))
                    {
                        cout << "Enter key and data of node to be inserted:" << endl;
                        cout << ">";
                        cin >> key1;
                        cout << ">";
                        cin >> data1;
                        n1->key = key1;
                        n1->data = data1;
                        s.insertNodeAfter(k1, n1);
                    }
                    else
                    {
                        cout << "No node exists with entered key value." << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Delete Node Operation (Deletion by key of node)" << endl;
                    cout << "Enter key value of node to be deleted:" << endl;
                    cout << ">";
                    cin >> k1;
                    s.deleteNodeByKey(k1);
                    break;
                }
                case 5:
                {
                    cout << "Update data of Node with key value" << endl;
                    cout << "Enter key of node who's data is to be updated: ";
                    cin >> k1;
                    cout << "\nEnter new data: ";
                    cin >> data1;
                    cout << endl;
                    s.updateNodeByKey(k1, data1);
                    break;
                }
                case 6:
                {
                    cout << "Linked list is: " << endl;
                    s.printLinkedList();
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
                    goto Title;break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 8);
        }
        else if (((int)varForDataTypeSelection - '0') == 4)
        {
            char data1;
            cout << "Selected Data type: CHAR" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            SinglyLinkedList<char> s;
            do
            {
                label4:
                Node<char> *n1 = new Node<char>();
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print singly linked list\n7.Clear Screen\n8.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                if(!isdigit(varForSwitchCase))
                {
                    cout << "Invalid input" << endl;
                    goto label4;
                }
                switch ((int)varForSwitchCase - '0')
                {
                case 1:
                {
                    cout << "Append Node Operation\nEnter Key & data of node to be appended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.appendNode(n1);
                    break;
                }
                case 2:
                {
                    cout << "Prepend Node Operation\nEnter key and data of node to be prepended:" << endl;
                    cout << ">";
                    cin >> key1;
                    cout << ">";
                    cin >> data1;
                    n1->key = key1;
                    n1->data = data1;
                    s.prependNode(n1);
                    break;
                }
                case 3:
                {
                    cout << "Insert Node Operation" << endl;
                    cout << "Enter key of node after which you want to insert a node:\n>";
                    cin >> k1;
                    if (s.nodeExists(k1))
                    {
                        cout << "Enter key and data of node to be inserted:" << endl;
                        cout << ">";
                        cin >> key1;
                        cout << ">";
                        cin >> data1;
                        n1->key = key1;
                        n1->data = data1;
                        s.insertNodeAfter(k1, n1);
                    }
                    else
                    {
                        cout << "No node exists with entered key value." << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Delete Node Operation (Deletion by key of node)" << endl;
                    cout << "Enter key value of node to be deleted:" << endl;
                    cout << ">";
                    cin >> k1;
                    s.deleteNodeByKey(k1);
                    break;
                }
                case 5:
                {
                    cout << "Update data of Node with key value" << endl;
                    cout << "Enter key of node who's data is to be updated: ";
                    cin >> k1;
                    cout << "\nEnter new data: ";
                    cin >> data1;
                    cout << endl;
                    s.updateNodeByKey(k1, data1);
                    break;
                }
                case 6:
                {
                    cout << "Linked list is: " << endl;
                    s.printLinkedList();
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
                    goto Title;
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
        else if (((int)varForDataTypeSelection - '0') == 5)
        {
            system("clear");
        }
        else if (((int)varForDataTypeSelection - '0') == 6)
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

    } while (((int)varForDataTypeSelection - '0') != 4);
    return 0;
}
