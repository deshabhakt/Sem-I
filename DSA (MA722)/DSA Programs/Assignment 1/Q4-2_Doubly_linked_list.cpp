// Doubly Linked list
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
    int data;
    Node<T> *next;
    Node<T> *previous;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
template <class T>
class DoublyLinkedList
{
public:
    Node<T> *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node<T> *n)
    {
        head = n;
    }
    Node<T> *checkIfNodeExists(int k)
    {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void appendNode(Node<T> *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node exists alreday in doubly linked list with key value " << n->key << "." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                Node<T> *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node appended successfully." << endl;
            }
        }
    }
    void prependNode(Node<T> *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node already exists in doubly linked list with key value " << n->key << "." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node prepended as head node" << endl;
            }
            else
            {
                head->previous = n;
                n->next = head;
                n->previous = NULL;
                head = n;
                cout << "Node prepended successfully." << endl;
            }
        }
    }
    void insertNodeAfter(int k, Node<T> *n)
    {
        Node<T> *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "Cannot perform insertion." << endl;
            cout << "Node with key value " << k << " does not exists in doubly linked list." << endl;
        }
        else
        {
            if (checkIfNodeExists(n->key) != NULL)
            {
                cout << "Node with key value " << n->key << " already exists in doubly linked list." << endl;
            }
            else
            {
                Node<T> *nextNode = ptr->next;
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node inserted at the end." << endl;
                }
                else
                {
                    nextNode->previous = n;
                    n->next = nextNode;
                    n->previous = ptr;
                    ptr->next = n;
                }
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        Node<T> *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "Cannot perform deletion." << endl;
            cout << "Node with key value " << k << " does not exists in linked list." << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "head node with key value " << k << " unlinked successfully." << endl;
            }
            else
            {
                Node<T> *previousNode = ptr->previous;
                Node<T> *nextNode = ptr->next;
                if (nextNode == NULL)
                {
                    previousNode->next = NULL;
                    cout << "Last node with key value " << k << " unlinked successfully." << endl;
                }
                else
                {
                    previousNode->next = nextNode;
                    nextNode->previous = previousNode;
                    cout << "Node with key value " << k << " unlinked successfully." << endl;
                }
            }
        }
    }
    void updateNodeByKey(int k, T data)
    {
        Node<T> *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "Cannot perform updation." << endl;
            cout << "Node with key value " << k << " does not exists in linked list." << endl;
        }
        else
        {
            Node<T> *temp = ptr;
            ptr->data = data;
            cout << "Node before updation: (" << temp->key << "," << temp->data << ")" << endl;
            cout << "Node after updation: (" << ptr->key << "," << ptr->data << ")" << endl;
        }
    }
    void printDoublyLinkedList()
    {
        if (head == NULL)
        {
            cout << "Doubly linked list is empty." << endl;
        }
        {
            Node<T> *ptr = head;
            while (ptr != NULL)
            {
                cout << "(" << ptr->key << "," << ptr->data << ")    ";
                ptr = ptr->next;
            }
        }
    }
    void printDoublyLinkedListInReverseOrder()
    {
        if (head == NULL)
        {
            cout << "Doubly linked list is empty." << endl;
        }
        {
            Node<T> *temp = head;
            Node<T> *ptrbwd = NULL;
            while (temp != NULL)
            {
                ptrbwd = temp;
                temp = temp->next;
            }
            while (ptrbwd != NULL)
            {
                cout << "(" << ptrbwd->key << "," << ptrbwd->data << ")    ";
                ptrbwd = ptrbwd->previous;
            }
        }
    }
};
int main()
{
    int varForDataTypeSelection, varForSwitchCase, key1, k1;
    do
    {
        cout << "\n=====================================================================================" << endl;
        cout << "**************************** Doubly Linked list Operations **************************" << endl;
        cout << "=====================================================================================" << endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT     2.DOUBLE    3.FLOAT     4.CHAR     5.Clear Screen     0.Exit from program" << endl;
        cout << ">";
        cin >> varForDataTypeSelection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        if (varForDataTypeSelection == 1)
        {
            int data1;
            cout << "Selected Data type: INT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            DoublyLinkedList<int> s;
            do
            {
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print doubly linked list\n7.Print doubly linked list in reverse order\n8.Clear Screen\n0.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<int> *n1 = new Node<int>();
                switch (varForSwitchCase)
                {
                case 0:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
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
                    if (s.checkIfNodeExists(k1))
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
                    cout << "Doubly linked list is: " << endl;
                    s.printDoublyLinkedList();
                    break;
                }
                case 7:
                {
                    cout << "Doubly linked list in reverse order: " << endl;
                    s.printDoublyLinkedListInReverseOrder();
                    break;
                }
                case 8:
                {
                    system("clear");
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }

            } while (varForSwitchCase != 0);
        }
        else if (varForDataTypeSelection == 2)
        {
            double data1;
            cout << "Selected Data type: DOUBLE" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            DoublyLinkedList<double> s;
            do
            {
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print doubly linked list\n7.Print doubly linked list in reverse order\n8.Clear Screen\n0.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<double> *n1 = new Node<double>();
                switch (varForSwitchCase)
                {
                case 0:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
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
                    if (s.checkIfNodeExists(k1))
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
                    cout << "Doubly linked list is: " << endl;
                    s.printDoublyLinkedList();
                    break;
                }
                case 7:
                {
                    cout << "Doubly linked list in reverse order: " << endl;
                    s.printDoublyLinkedListInReverseOrder();
                    break;
                }
                case 8:
                {
                    system("clear");
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }

            } while (varForSwitchCase != 0);
        }
        else if (varForDataTypeSelection == 3)
        {
            float data1;
            cout << "Selected Data type: FLOAT" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            DoublyLinkedList<float> s;
            do
            {
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print doubly linked list\n7.Print doubly linked list in reverse order\n8.Clear Screen\n0.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<float> *n1 = new Node<float>();
                switch (varForSwitchCase)
                {
                case 0:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
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
                    if (s.checkIfNodeExists(k1))
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
                    cout << "Doubly linked list is: " << endl;
                    s.printDoublyLinkedList();
                    break;
                }
                case 7:
                {
                    cout << "Doubly linked list in reverse order: " << endl;
                    s.printDoublyLinkedListInReverseOrder();
                    break;
                }
                case 8:
                {
                    system("clear");
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }

            } while (varForSwitchCase != 0);
        }
        else if (varForDataTypeSelection == 4)
        {
            char data1;
            cout << "Selected Data type: CHAR" << endl;
            cout << "Which Operation Do you want to perform?" << endl;
            DoublyLinkedList<char> s;
            do
            {
                cout << "\n1.Append Node\n2.PrependNode\n3.Insert Node after a particular node\n4.Delete Node\n5.Update Node data\n6.Print doubly linked list\n7.Print doubly linked list in reverse order\n8.Clear Screen\n0.Go to previous menu\n> ";
                cin >> varForSwitchCase;
                Node<char> *n1 = new Node<char>();
                switch (varForSwitchCase)
                {
                case 0:
                {
                    cout << "=====================================================================================" << endl;
                    break;
                }
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
                    if (s.checkIfNodeExists(k1))
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
                    cout << "Doubly linked list is: " << endl;
                    s.printDoublyLinkedList();
                    break;
                }
                case 7:
                {
                    cout << "Doubly linked list in reverse order: " << endl;
                    s.printDoublyLinkedListInReverseOrder();
                    break;
                }
                case 8:
                {
                    system("clear");
                    break;
                }
                default:
                {
                    cout << "Invalid Input.\nTry Again:)" << endl;
                    break;
                }
                }
            } while (varForSwitchCase != 0);
        }
        else if (varForDataTypeSelection == 5)
        {
            system("clear");
        }
        else if (varForDataTypeSelection == 0)
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
    } while (varForDataTypeSelection != 0);
    return 0;
}