// implementation of Binary search tree

#include<iostream>

#define SPACE 10
using namespace std;
template<class T>
class treeNode
{
    public:
    T data;
    treeNode *left;
    treeNode *right;
    treeNode()
    {
        data=0;
        left=right=NULL;
    }
    treeNode(T d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
template<class T>
class BST
{
    public:
    treeNode<T>* root;
    BST()
    {
        root=NULL;
    }
    bool isEmpty()
    {
        if(root==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertNode(treeNode<T>* n)
    {
        if(root==NULL)
        {
            root=n;
            cout << "Value inserted at root";
        }
        else
        {
            treeNode<T>* temp=root;
            while(temp!=NULL)
            {
                if(n->data==temp->data)
                {
                    cout << "No duplicates Allowed in BST"<< endl;
                    break;
                }
                else if((n->data<temp->data)&&(temp->left==NULL))
                {
                    temp->left=n;
                    cout << "Value inserted to left"<<endl;
                    break;
                }
                else if(n->data<temp->data)
                {
                    temp=temp->left;
                }
                else if((n->data>temp->data) && (temp->right==NULL))
                {
                    temp->right=n;
                    cout << "Value inserted to right"<<endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void printBST(treeNode<int>* r,int space)
    {
        if(r==NULL)
        {
            return;
        }
        space+=SPACE;
        printBST(r->right,space);
        cout << endl;
        for(int i=SPACE; i<space; i++)
            cout << " ";
        cout << r->data<<endl;
        printBST(r->left,space);
    }
    void printPreOrder(treeNode<T>* n)
    {
        if(n==NULL)
        {
            return;
        }
        cout << n->data << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
    void printInOrder(treeNode<T>* n)
    {
        if(n==NULL)
        {
            return;
        }
        printInOrder(n->left);
        cout << n->data << " ";
        printInOrder(n->right);
    }
    void printPostOrder(treeNode<T>* n)
    {
        if(n==NULL)
        {
            return;
        }
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->data << " ";
    }
};
int main()
{
    int user_input,val;
    BST<int> obj;
    do
    {
        treeNode<int>* n1 = new treeNode<int>();
        cout << "\nSelect Operation: "<<endl;
        cout << "1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST values \n5.Pre-Order Traversal\n6.In-Order Traversal\n7.Post-Order Traversal" <<endl; 
        //\n5.Clear Screen\n6.End Program"
        cout << ">";
        cin >> user_input;
        switch(user_input)
        {
            case 1:
                cout << "Insert"<<endl;
                cout << ">";
                cin >> val;
                n1->data=val;
                obj.insertNode(n1);
                break;
            case 2:
                cout << "Search Node"<<endl;
                break;

            case 3:
                cout << "Delete Node"<<endl;
                break;
            case 4:
                cout << "Print BST values"<<endl;
                obj.printBST(obj.root,5);
                break;
            case 5:
                obj.printBST(obj.root,5);
                cout << "Pre-Order Traversal of BST"<<endl;
                obj.printPreOrder(obj.root);
                break;
            case 6:
                obj.printBST(obj.root,5);
                cout << "In-Order Traversal of BST"<<endl;
                obj.printInOrder(obj.root);
                break;
            case 7:
                obj.printBST(obj.root,5);
                cout << "Post-Order Traversal of BST"<<endl;
                obj.printPostOrder(obj.root);
                break;
            case 8:
                break;
            default:
                cout << "Invalid Input"<<endl;
        }
    } while (user_input!=8);
    return 0;
}