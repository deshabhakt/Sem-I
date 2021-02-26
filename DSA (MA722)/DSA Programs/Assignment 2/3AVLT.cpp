#include <iostream>
#define SPACE 10
using namespace std;
template <class T> class treeNode {
public:
  treeNode<T> *left;
  T data;
  int height;
  treeNode<T> *right;
  treeNode<T> *next;
  treeNode() {
    left = right = NULL;
    data = height = 0;
  }
  treeNode(T d) {
    left = right = NULL;
    data = d;
    height = 0;
  }
};
template <class T> class queue {
public:
  treeNode<T> *front;
  treeNode<T> *rear;

  queue() {
    front = NULL;
    rear = NULL;
  }
  bool isEmpty() {
    treeNode<T> *tempf = front;
    treeNode<T> *tempr = rear;
    if (tempf == NULL) {
      return true;
    } else {
      return false;
    }
  }
  void enqueue(treeNode<T> *n) {
    if (front == NULL) {
      front = n;
      rear = n;
    } else {
      rear->next = n;
      rear = n;
    }
  }
  treeNode<T> *dequeue() {
    treeNode<T> *temp = NULL;
    if (isEmpty()) {
      return NULL;
    } else {
      if (front == rear) {
        temp = front;
        front = NULL;
        rear = NULL;
        return temp;
      } else {
        temp = front;
        front = front->next;
        return temp;
      }
    }
  }
};
template <class T> class AVLT {
public:
  treeNode<T> *root;
  T element;
  AVLT() { root = NULL; }
  int BalanceFactor(treeNode<T> *p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl - hr;
  }
  int NodeHeight(treeNode<T> *p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl > hr ? (hl + 1) : (hr + 1);
  }
  treeNode<T> *LLRotation(treeNode<T> *p) {
    treeNode<T> *pl = p->left;
    treeNode<T> *plr = pl->right;
    p->left = plr;
    pl->right = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (root == p)
      root = pl;
    return pl;
  }
  treeNode<T> *RRRotation(treeNode<T> *p) {
    treeNode<T> *pr = p->right;
    treeNode<T> *prl = pr->left;
    p->right = prl;
    pr->left = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if (root == p)
      root = pr;
    return pr;
  }
  treeNode<T> *LRRotation(treeNode<T> *p) {
    treeNode<T> *pl = p->left;
    treeNode<T> *plr = pl->right;
    p->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    if (root == p)
      root = plr;
    return plr;
  }
  treeNode<T> *RLRotation(treeNode<T> *p) {
    treeNode<T> *pr = p->right;
    treeNode<T> *prl = pr->left;
    p->right = prl->left;
    prl->left = p;
    prl->right = pr;
    pr->left = prl->right;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    if (root == p)
      root = prl;
    return prl;
  }
  treeNode<T> *insert(treeNode<T> *p, T nd) {
    if (p == NULL) {
      treeNode<T> *temp = new treeNode<int>();
      temp->data = nd;
      temp->height = 1;
      return temp;
    }
    if (nd < p->data) {
      p->left = insert(p->left, nd);
    } else if (nd > p->data) {
      p->right = insert(p->right, nd);
    }
    p->height = NodeHeight(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
      return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
      return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
      return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
      return RLRotation(p);
    return p;
  }
  int DepthOfTree(treeNode<T> *root) {
    if (root == NULL) {
      return 0;
    } else {
      int x = DepthOfTree(root->left);
      int y = DepthOfTree(root->right);
      if (x > y) {
        return x + 1;
      } else {
        return y + 1;
      }
    }
  }
  int CalcNodesAtEachLevel(treeNode<T> *n, int current, int desired) {
    if (n == NULL) {
      return 0;
    }
    if (current ==desired) {
      return 1;
    } else {
      return CalcNodesAtEachLevel(n->left, current + 1, desired) +
             CalcNodesAtEachLevel(n->right, current + 1, desired);
    }
  }
  void PrintNumberOfNodesAtEachLevel(treeNode<T> *root) {
    int h = DepthOfTree(root);
    for (int i = 0; i < h; i++) {
      int count = CalcNodesAtEachLevel(root, 0, i);
      cout << "At Level " << i + 1 << ", Number of Nodes are " << count << "."
           << endl;
    }
  }
  void printAVLT(treeNode<int> *r, int space) {
    if (r == NULL) {
      return;
    }
    space += SPACE;
    printAVLT(r->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " ";
    cout << r->data << endl;
    printAVLT(r->left, space);
  }
  void PreOrder(treeNode<T> *root) {
    if (root == NULL) {
      return;
    } else {
      cout << root->data << " ";
      PreOrder(root->left);
      PreOrder(root->right);
    }
  }
  void InOrder(treeNode<T> *root) {
    if (root == NULL) {
      return;
    } else {
      InOrder(root->left);
      cout << root->data << " ";
      InOrder(root->right);
    }
  }
  void PostOrder(treeNode<T> *root) {
    if (root == NULL) {
      return;
    } else {
      PostOrder(root->left);
      PostOrder(root->right);
      cout << root->data << " ";
    }
  }
  void printGivenLevel(treeNode<T> *n,
                       int level) // Used for LevelOrderTraversal
  {
    if (n == NULL) {
      return;
    } else if (level == 0) {
      cout << n->data << " ";
    } else {
      printGivenLevel(n->left, level - 1);
      printGivenLevel(n->right, level - 1);
    }
  }
  void LevelOrder(treeNode<T> *n) {
    int h = DepthOfTree(n);
    for (int i = 0; i <= h; i++)
      printGivenLevel(n, i);
  }
  int TotalNumberOfNodesInTree(treeNode<T> *root) {
    if (root == NULL) {
      return 0;
    } else {
      int x = TotalNumberOfNodesInTree(root->left);
      int y = TotalNumberOfNodesInTree(root->right);
      return x + y + 1;
    }
  }
  treeNode<T> *minValueNode(treeNode<T> *node) {
    treeNode<T> *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
      current = current->left;
    }
    return current;
  }
  treeNode<T> *deleteNode(treeNode<T> *p, int v) {
    // base case
    if (p == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (v < p->data) {
      p->left = deleteNode(p->left, v);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (v > p->data) {
      p->right = deleteNode(p->right, v);
    }
    // if key is same as root's key, then This is the node to be deleted
    else {
      // node with only one child or no child
      if (p->left == NULL) {
        treeNode<T> *temp = p->right;
        delete p;
        return temp;
      } else if (p->right == NULL) {
        treeNode<T> *temp = p->left;
        delete p;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        treeNode<T> *temp = minValueNode(p->right);
        // Copy the inorder successor's content to this node
        p->data = temp->data;
        // Delete the inorder successor
        p->right = deleteNode(p->right, temp->data);
        // deleteNode(p->right, temp->data);
      }
      return p;
    }
    p->height = NodeHeight(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)
      return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)
      return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)
      return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)
      return RLRotation(p);
    return p;
  }
  T CheckIfNodeExists(T n) {
    queue<T> q;
    q.enqueue(root);
    treeNode<T> *temp = root;
    while (temp->data != n && !q.isEmpty()) {
      temp = q.dequeue();
      if (temp->left) {
        q.enqueue(temp->left);
      }
      if (temp->right) {
        q.enqueue(temp->right);
      }
    }
    if (temp->data == n) {
      return n;
    } else {
      return 0;
    }
  }
};
int main() {
  AVLT<int> obj;
  int user_input;
  do {
    treeNode<int> *temp = new treeNode<int>();
    cout << "\nSelect Operation: " << endl;
    cout << "1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print AVL Tree "
            "values \n5.Tree Traversal\n6.Number of Nodes at each "
            "level\n7.Total Number of Nodes is Tree\n8.Depth Of "
            "Tree\n9.Clear\n10.Exit"
         << endl;
    cout << ">";
    cin >> user_input;
    switch (user_input) {
    case 1: {
      cout << "Insert" << endl;
      cout << ">";
      cin >> obj.element;
      temp->data = obj.element;
      if (obj.root == NULL) {
        obj.root = obj.insert(obj.root, obj.element);
      } else if (obj.element == obj.CheckIfNodeExists(obj.element)) {
        cout << "No Duplicates are Allowed" << endl;
      } else {
        obj.insert(obj.root, obj.element);
      }
      break;
    }
    case 2: {
      cout << "Search Node" << endl;
      cout << "Enter Value to be searched : ";
      cin >> obj.element;
      temp->data = obj.element;
      if (obj.element == obj.CheckIfNodeExists(obj.element)) {
        cout << "Element is Present in Tree." << endl;
      } else {
        cout << "Element is Not Present in Tree." << endl;
      }
      break;
    }
    case 3: {
      cout << "Delete Node" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in AVL Tree: ";
      cin >> obj.element;
      temp->data = obj.element;
      if (obj.element == obj.CheckIfNodeExists(obj.element)) {
        temp = obj.deleteNode(obj.root, obj.element);
        cout << "Node " << obj.element << " Deleted" << endl;
      } else {
        cout << "Node NOT found" << endl;
      }
      break;
    }
    case 4: {
      cout << "Print AVL Tree" << endl;
      obj.printAVLT(obj.root, 5);
      break;
    }
    case 5: {
      obj.printAVLT(obj.root, 5);
      cout << "\nPre-Order Traversal of AVL Tree   : ";
      obj.PreOrder(obj.root);
      cout << "\nIn-Order Traversal of AVL Tree    : ";
      obj.InOrder(obj.root);
      cout << "\nPost-Order Traversal of AVL Tree  : ";
      obj.PostOrder(obj.root);
      cout << "\nLevel order Traversal of AVL Tree : ";
      obj.LevelOrder(obj.root);
      break;
    }
    case 6: {
      cout << "Number of Nodes at each Level are :" << endl;
      obj.PrintNumberOfNodesAtEachLevel(obj.root);
      break;
    }
    case 7: {
      cout << "Total Number of Nodes in Tree are : "
           << obj.TotalNumberOfNodesInTree(obj.root);
      break;
    }
    case 8: {
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
