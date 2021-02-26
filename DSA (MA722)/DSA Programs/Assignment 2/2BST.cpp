// implementation of Binary search tree

#include <iostream>
#define SPACE 10

using namespace std;
template <class T>
class treeNode
{
public:
    T data;
    treeNode *left;
    treeNode *right;
    treeNode<T> *next;
    treeNode()
    {
        data = 0;
        left = right = NULL;
    }
    treeNode(T d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
template <class T>
class queue
{
public:
    treeNode<T> *front;
    treeNode<T> *rear;

    queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        treeNode<T> *tempf = front;
        treeNode<T> *tempr = rear;
        if (tempf == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(treeNode<T> *n)
    {
        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
    treeNode<T> *dequeue()
    {
        treeNode<T> *temp = NULL;
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            if (front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
                return temp;
            }
            else
            {
                temp = front;
                front = front->next;
                return temp;
            }
        }
    }
};
template <class T>
class BST
{
public:
    treeNode<T> *root;
    T element;
    BST()
    {
        root = NULL;
    }
    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertNode(treeNode<T> *n)
    {
        if (root == NULL)
        {
            root = n;
            cout << "Value inserted at root";
        }
        else
        {
            treeNode<T> *temp = root;
            while (temp != NULL)
            {
                if (n->data == temp->data)
                {
                    cout << "No duplicates Allowed in BST" << endl;
                    break;
                }
                else if ((n->data < temp->data) && (temp->left == NULL))
                {
                    temp->left = n;
                    cout << "Value inserted to left" << endl;
                    break;
                }
                else if (n->data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((n->data > temp->data) && (temp->right == NULL))
                {
                    temp->right = n;
                    cout << "Value inserted to right" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void printBST(treeNode<int> *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += SPACE;
        printBST(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->data << endl;
        printBST(r->left, space);
    }
    void printPreOrder(treeNode<T> *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->data << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
    void printInOrder(treeNode<T> *n)
    {
        if (n == NULL)
        {
            return;
        }
        printInOrder(n->left);
        cout << n->data << " ";
        printInOrder(n->right);
    }
    void printPostOrder(treeNode<T> *n)
    {
        if (n == NULL)
        {
            return;
        }
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->data << " ";
    }
    void printGivenLevel(treeNode<T> *n, int level) //Used for LevelOrderTraversal
    {
        if (n == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << n->data << " ";
        }
        else
        {
            printGivenLevel(n->left, level - 1);
            printGivenLevel(n->right, level - 1);
        }
    }
    void printLevelOrder(treeNode<T> *n)
    {
        int h = DepthOfTree(n);
        for (int i = 0; i <= h; i++)
            printGivenLevel(n, i);
    }
    int DepthOfTree(treeNode<T> *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int x = DepthOfTree(root->left);
            int y = DepthOfTree(root->right);
            if (x > y)
            {
                return x + 1;
            }
            else
            {
                return y + 1;
            }
        }
    }
    int TotalNumberOfNodesInTree(treeNode<T> *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int x = TotalNumberOfNodesInTree(root->left);
            int y = TotalNumberOfNodesInTree(root->right);
            return x + y + 1;
        }
    }
    int CalcNodesAtEachLevel(treeNode<T> *n, int curr, int desired)
    {
        if (n == NULL)
            return 0;
        if (curr == desired)
            return 1;
        else
        {
            return CalcNodesAtEachLevel(n->left, curr + 1, desired) + CalcNodesAtEachLevel(n->right, curr + 1, desired);
        }
    }
    void printNumberOfNodesAtEachLevel(treeNode<T> *root)
    {
        int h = DepthOfTree(root);
        for (int i = 0; i < h; i++)
        {
            int count = CalcNodesAtEachLevel(root, 0, i);
            cout << "At Level " << i + 1 << " ,Number of Nodes are " << count << "." << endl;
        }
    }
    treeNode<T> *minValueNode(treeNode<T> *node)
    {
        treeNode<T> *current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    treeNode<T> *deleteNode(treeNode<T> *r, int v)
    {
        // base case
        if (r == NULL)
        {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        else if (v < r->data)
        {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (v > r->data)
        {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted
        else
        {
            // node with only one child or no child
            if (r->left == NULL)
            {
                treeNode<T> *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                treeNode<T> *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with two children: Get the inorder successor (smallest
                // in the right subtree)
                treeNode<T> *temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node
                r->data = temp->data;
                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->data);
                //deleteNode(r->right, temp->data);
            }
        }
        return r;
    }
    T CheckIfNodeExists(T n)
    {
        queue<T> q;
        q.enqueue(root);
        treeNode<T> *temp = root;
        while (temp->data != n && !q.isEmpty())
        {
            temp = q.dequeue();
            if (temp->left)
            {
                q.enqueue(temp->left);
            }
            if (temp->right)
            {
                q.enqueue(temp->right);
            }
        }
        if (temp->data == n)
        {
            return n;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    int user_input;
    BST<int> obj;
    do
    {
        treeNode<int> *temp = new treeNode<int>();
        cout << "\nSelect Operation: " << endl;
        cout << "1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST values \n5.Tree Traversal\n6.Number of Nodes at each level\n7.Total Number of Nodes is Tree\n8.Depth Of Tree\n9.Clear\n10.Exit" << endl;
        cout << ">";
        cin >> user_input;
        switch (user_input)
        {
        case 1:
        {
            cout << "Insert" << endl;
            cout << ">";
            cin >> obj.element;
            temp->data = obj.element;
            if (obj.root == NULL)
            {
                obj.insertNode(temp);
            }
            else if (obj.element == obj.CheckIfNodeExists(obj.element))
            {
                cout << "No Duplicates are Allowed" << endl;
            }
            else
            {
                obj.insertNode(temp);
            }
            break;
        }
        case 2:
        {
            cout << "Search Node" << endl;
            cout << "Enter Value to be searched : ";
            cin >> obj.element;
            temp->data = obj.element;
            if (obj.element == obj.CheckIfNodeExists(obj.element))
            {
                cout << "Element is Present in Tree." << endl;
            }
            else
            {
                cout << "Element is Not Present in Tree." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Delete Node" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> obj.element;
            temp->data = obj.element;
            if (obj.element == obj.CheckIfNodeExists(obj.element))
            {
                temp = obj.deleteNode(obj.root, obj.element);
                cout << "Node " << temp->data << " Deleted" << endl;
            }
            else
            {
                cout << "Node NOT found" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Print BST" << endl;
            obj.printBST(obj.root, 5);
            break;
        }
        case 5:
        {
            obj.printBST(obj.root, 5);
            cout << "\nPre-Order Traversal of BST   : ";
            obj.printPreOrder(obj.root);
            cout << "\nIn-Order Traversal of BST    : ";
            obj.printInOrder(obj.root);
            cout << "\nPost-Order Traversal of BST  : ";
            obj.printPostOrder(obj.root);
            cout << "\nLevel order Traversal of BST : ";
            obj.printLevelOrder(obj.root);
            break;
        }
        case 6:
        {
            cout << "Number of Nodes at each Level are :" << endl;
            obj.printNumberOfNodesAtEachLevel(obj.root);
            break;
        }
        case 7:
        {
            cout << "Total Number of Nodes in Tree are : " << obj.TotalNumberOfNodesInTree(obj.root);
            break;
        }
        case 8:
        {
            cout << "Depth of Tree is " << obj.DepthOfTree(obj.root) - 1;
            break;
        }
        case 9:
            system("clear");
            break;
        case 10:
            cout << "\n********Program Ended********\n";
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (user_input != 10);
    return 0;
}