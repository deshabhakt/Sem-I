// Reversing a string using Singly Linked list and checking if a list is Palindrome or not
// Roll NO. 202cd05
#include <iostream>
#include<stdlib.h>
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
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
template <class T>
class String
{
public:
    Node<T> *head;
    int count;
    String()
    {
        head = NULL;
    }
    void append(Node<T> *n)
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node<T> *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    void displayString()
    {
        Node<T> *ptr = head;
        if (ptr == NULL)
        {
            cout << "String is empty." << endl;
        }
        else
        {
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
    }
    void reverseString()
    {
        //reversing string
        Node<T> *current = head;
        Node<T> *prev = NULL;
        Node<T> *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        //displaying reversed string
        displayString();
        //re-reversing string so that original string remains intact
        current = head;
        prev = NULL;
        next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    bool checkIfPalindrome() //by spliting list from middle and comparing the two parts
    {
        Node<T> *temp = NULL;
        Node<T> *sp = head, *fp = head, *mid = NULL;
        while (fp != NULL && fp->next != NULL)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        if (fp != NULL) //fp will not be null only if linked list has odd number of elements
        {
            temp = sp;
            mid = sp->next;
        }
        else
        {
            mid = sp;
        }
        //Reversing second part of list i.e. from middle to end
        Node<T> *prev = NULL;
        Node<T> *next = NULL;
        while (mid != NULL)
        {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        while (prev != NULL)
        {
            if (prev->data != head->data) //checking if same elements are present at mirror location i.e palindrome
                return false;
            prev = prev->next;
            head = head->next;
        }
    return true;
    }
};
int main()
{
    int varForSwitchCase;
    String<char> s;
    string st;
    cout << "\n=====================================================================================" << endl;
    cout << "******** Program on Reversing String and Checking If String is Palindrome ***********" << endl;
    cout << "\n**************************** (Using Singly Linked List) *****************************" << endl;
    cout << "=====================================================================================" << endl;
    cout << "Enter String: ";
    cin >> st;
    for (int i = 0; i < st.length();i++)
    {
        Node<char> *newNode = new Node<char>();
        {
            newNode->key = i;
            newNode->data = st[i] ;
            s.append(newNode);
        }
    }
    cout << "\nWhich Operation Do you want to perform?" << endl;
    do
    {
        cout << "\n1.Diplay String\n2.Reverse String\n3.Check if string is Palindrome\n4.Clear Screen\n5.Exit\n>";
        cin >> varForSwitchCase;
        switch (varForSwitchCase)
        {
        case 1:
        {
            cout << "Linked list is :";
            s.displayString();
            break;
        }
        case 2:
        {
            cout << "Reverse String Operation" << endl;
            s.reverseString();
            break;
        }
        case 3:
        {
            if (s.checkIfPalindrome())
            {
                cout << "String is Palindrome." << endl;
            }
            else
            {
                cout << "String is not Palindrome" << endl;
            }
            break;
        }
        case 4:
        {
            system("clear");
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            cout << "Invalide input.\nTry Again:)" << endl;
        }
        }
    } while (varForSwitchCase != 5);
    return 0;
}