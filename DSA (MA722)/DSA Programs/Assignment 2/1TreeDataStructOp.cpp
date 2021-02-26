// implementation of Binary search tree

#include <iostream>

using namespace std;
template <class T> class treeNode {
public:
  T data;
  treeNode<T> *left;
  treeNode<T> *right;
  treeNode<T> *next;
  treeNode() {
    data = 0;
    left = right = NULL;
  }
  treeNode(T d) {
    data = d;
    left = NULL;
    right = NULL;
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
  treeNode<T> *rearNode() { return rear; }
};
template <class T> class Tree {
public:
  treeNode<T> *root;
  T ele;
  Tree() { root = NULL; }
  void CreateTree();
  bool isEmpty(treeNode<T> *root) {
    if (root == NULL)
      return true;
    else {
      return false;
    }
  }
  void PreOrder(treeNode<T> *p);
  void PostOrder(treeNode<T> *p);
  void InOrder(treeNode<T> *p);
  void LevelOrder(treeNode<T> *p);
  int DepthOfTree(treeNode<T> *root);
  int count(treeNode<T> *root);
  void Search(treeNode<T> *root);
  treeNode<T> *checkifelementpresentintree(T n);
  int NodesAtEachLevel(treeNode<T> *root, int curr, int desired);
  void insert(T pdata);
  treeNode<T> *deleteNode(treeNode<T> *n, treeNode<T> *delNode);
};
template <class T> void Tree<T>::CreateTree() {
  treeNode<T> *pop, *next;
  T x;
  queue<T> q;
  cout << "*NOTE: Please enter -1 if there's no node.*" << endl << endl;
  cout << "Enter Root element : ";
  cin >> x;
  cout << endl;
  root = new treeNode<T>();
  root->data = x;
  root->left = root->right = NULL;
  q.enqueue(root);
  while (!q.isEmpty()) {
    pop = q.dequeue();
    cout << "Enter left child of " << pop->data << ": ";
    cin >> x;
    cout << endl;
    if (x != -1) {
      next = new treeNode<T>();
      next->data = x;
      next->left = next->right = NULL;
      pop->left = next;
      q.enqueue(next);
      next = NULL;
    }
    cout << "Enter right child of " << pop->data << ": ";
    cin >> x;
    cout << endl;
    if (x != -1) {
      next = new treeNode<T>();
      next->data = x;
      next->left = next->right = NULL;
      pop->right = next;
      q.enqueue(next);
      next = NULL;
    }
  }
}
template <class T> void Tree<T>::PreOrder(treeNode<T> *p) {
  if (p != NULL) {
    cout << p->data << " ";
    PreOrder(p->left);
    PreOrder(p->right);
  }
}
template <class T> void Tree<T>::InOrder(treeNode<T> *p) {
  if (p != NULL) {
    InOrder(p->left);
    cout << p->data << " ";
    InOrder(p->right);
  }
}
template <class T> void Tree<T>::PostOrder(treeNode<T> *p) {
  if (p != NULL) {
    PostOrder(p->left);
    PostOrder(p->right);
    cout << p->data << " ";
  }
}
template <class T> void Tree<T>::LevelOrder(treeNode<T> *root) {
  queue<T> q;
  q.enqueue(root);
  cout << root->data << " ";
  while (!q.isEmpty()) {
    root = q.dequeue();
    if (root->left) {
      cout << root->left->data << " ";
      q.enqueue(root->left);
    }
    if (root->right) {
      cout << root->right->data << " ";
      q.enqueue(root->right);
    }
  }
}
template <class T> int Tree<T>::DepthOfTree(treeNode<T> *root) {
  int x = 0, y = 0;
  if (root != NULL) {
    x = DepthOfTree(root->left);
    y = DepthOfTree(root->right);
    if (x > y)
      return (x + 1);
    else
      return (y + 1);
  } else {
    return 0;
  }
}
template <class T> int Tree<T>::count(treeNode<T> *root) {
  treeNode<T> *temp = root;
  int x, y;
  if (temp != NULL) {
    x = count(temp->left);
    y = count(temp->right);
    return x + y + 1;
  }
  return 0;
}
template <class T>
int Tree<T>::NodesAtEachLevel(treeNode<T> *node, int curr, int desired) {
  if (node == NULL)
    return 0;
  if (curr == desired)
    return 1;
  return NodesAtEachLevel(node->left, curr + 1, desired) +
         NodesAtEachLevel(node->right, curr + 1, desired);
}
template <class T> treeNode<T> *Tree<T>::checkifelementpresentintree(T n) {
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
    return temp;
  } else {
    return NULL;
  }
}
template <class T> void Tree<T>::insert(T pdata) {
  treeNode<T> *temp = checkifelementpresentintree(pdata);
  if (temp != NULL) {
    int in;
    T val;
    do {
      cout << "\n1.Attach to left of " << temp->data << endl;
      cout << "2.Attach to right of " << temp->data << endl;
      cout << "3.Go To previous Menu" << endl;
      cin >> in;
      switch (in) {
      case 1: {
        if (temp->left == NULL) {
          cout << "Enter element to be inserted : ";
          cin >> val;
          if (checkifelementpresentintree(val) != NULL) {
            cout << "Element already present in Tree." << endl;
          } else {
            treeNode<T> *newNode = new treeNode<T>();
            newNode->data = val;
            temp->left = newNode;
            cout << "Element Added to tree successfully." << endl;
            in = 3;
          }
        } else {
          cout << "Node Already Occupied" << endl;
        }
        break;
      }
      case 2: {
        if (temp->right == NULL) {
          cout << "Enter element to be inserted : ";
          cin >> val;
          if (checkifelementpresentintree(val) != NULL) {
            cout << "Element already present in Tree." << endl;
          } else {
            treeNode<T> *newNode = new treeNode<T>();
            newNode->data = val;
            temp->right = newNode;
            cout << "Element Added to tree successfully." << endl;
            in = 3;
          }
        } else {
          cout << "Node Already Occupied" << endl;
        }
        break;
      }
      case 3: {
        break;
      }
      default: {
        cout << "Invalid Input\nTry Again" << endl;
      }
      }
    } while (in != 3);
  } else {
    cout << "Parent Unavailable" << endl;
  }
}
template <class T>
treeNode<T> *Tree<T>::deleteNode(treeNode<T> *r, treeNode<T> *delNode) {
  treeNode<T> *temp = checkifelementpresentintree(delNode->data);
  if (r == NULL) {
    return NULL;
  } else {
    if (r->left == NULL) {
      treeNode<T> *temp = r->right;
      delete r;
      return temp;
    } else if (r->right == NULL) {
      treeNode<T> *temp = r->left;
      delete r;
      return temp;
    } else if (r->left != NULL && r->right != NULL) {
      treeNode<T> *temp = r->right;
      temp->left = r->left;
      delete r;
      return temp;
    }
    return r;
  }
}
int main() {
  Tree<int> t;
  int input;
  do {
    cout << "\n*************************************************" << endl;
    cout << "***************  Tree Operations  ***************" << endl;
    cout << "*************************************************" << endl << endl;
    cout << "1.Create Tree\n2.Insert element in tree\n3.Delete element form "
            "tree\n4.Tree Traversal\n5.Depth of tree\n6.Check if Element is "
            "present in Tree\n7.Number of nodes at each level\n8.Total Number "
            "of Nodes\n9.Clear Screen\n10.Exit"
         << endl;
    cout << ">";
    cin >> input;
    switch (input) {
    case 1: {
      cout << "Tree Creation" << endl;
      t.CreateTree();
      break;
    }
    case 2: {
      cout << "Insert Element in Tree" << endl;
      cout << "Enter Parent: ";
      cin >> t.ele;
      t.insert(t.ele);
      break;
    }
    case 3: {
      cout << "Delete Element from Tree" << endl;
      cout << "Enter Element To be deleted: ";
      treeNode<int> *delNode = new treeNode<int>();
      cin >> delNode->data;
      treeNode<int> *temp = new treeNode<int>();
      temp = t.checkifelementpresentintree(delNode->data);
      if (temp != NULL) {
        t.deleteNode(t.root, delNode);
        cout << "Deletion successfull" << endl;
      } else {
        cout << "Element NOT present in List." << endl;
      }
      break;
    }
    case 4: {
      cout << "Tree Traversal" << endl;
      if (t.isEmpty(t.root)) {
        cout << "Tree is Empty" << endl;
      } else {
        cout << "Pre-Order Traversal  :";
        t.PreOrder(t.root);
        cout << endl;
        cout << "In-Order Traversal   :";
        t.InOrder(t.root);
        cout << endl;
        cout << "Post-Order Traversal :";
        t.PostOrder(t.root);
        cout << endl;
        cout << "Level-Order Traversal:";
        t.LevelOrder(t.root);
        cout << endl;
      }
      break;
    }
    case 5: {
      cout << "Depth of Tree is " << t.DepthOfTree(t.root) - 1 << "." << endl;
      break;
    }
    case 6: {
      cout << "Check if Element is present in Tree" << endl;
      cout << "Enter Element: ";
      cin >> t.ele;
      if (t.checkifelementpresentintree(t.ele) != NULL) {
        cout << "Element in Tree" << endl;
      } else {
        cout << "Element Not in Tree" << endl;
      }
      break;
    }
    case 7: {
      cout << "Number of nodes at each level" << endl;
      for (int i = 0; i < t.DepthOfTree(t.root); i++) {
        int count = t.NodesAtEachLevel(t.root, 0, i);
        cout << "Level " << i + 1 << " has " << count << " nodes" << endl;
      }
      break;
    }
    case 8: {
      cout << "Total Number of Nodes in Tree are " << t.count(t.root) << "."
           << endl;
      break;
    }
    case 9: {
      system("clear");
      break;
    }
    case 10: {
      cout << "\n\nProgram Ended\n" << endl;
      break;
    }
    default: {
      cout << "Invalid input\nTry Again" << endl;
    }
    }
  } while (input != 10);

  return 0;
}
