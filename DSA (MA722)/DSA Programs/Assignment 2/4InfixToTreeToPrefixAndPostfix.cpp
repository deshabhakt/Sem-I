#include <iostream>
#include <stack>
using namespace std;

// Tree Structure
typedef struct node {
  char data;
  struct node *left, *right;
} * nptr;

// Function to create new node
nptr newNode(char c) {
  nptr n = new node;
  n->data = c;
  n->left = n->right = NULL;
  return n;
}

// Function to build Expression Tree
nptr build(string &s) {

  // Stack to hold nodes
  stack<nptr> stN;

  // Stack to hold chars
  stack<char> stC;
  nptr t, t1, t2;

  // Prioritising the operators
  int p[123] = {0};
  p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3, p[')'] = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {

      // Push '(' in char stack
      stC.push(s[i]);
    }

    // Push the operands in node stack
    else if (isalpha(s[i])) {
      t = newNode(s[i]);
      stN.push(t);
    } else if (p[s[i]] > 0) {
      // If an operator with lower or
      // same associativity appears
      while (!stC.empty() && stC.top() != '(' &&
             ((s[i] != '^' && p[stC.top()] >= p[s[i]]) ||
              (s[i] == '^' && p[stC.top()] > p[s[i]]))) {

        // Get and remove the top element
        // from the character stack
        t = newNode(stC.top());
        stC.pop();

        // Get and remove the top element
        // from the node stack
        t1 = stN.top();
        stN.pop();

        // Get and remove the currently top
        // element from the node stack
        t2 = stN.top();
        stN.pop();

        // Update the tree
        t->left = t2;
        t->right = t1;

        // Push the node to the node stack
        stN.push(t);
      }

      // Push s[i] to char stack
      stC.push(s[i]);
    } else if (s[i] == ')') {
      while (!stC.empty() && stC.top() != '(') {
        t = newNode(stC.top());
        stC.pop();
        t1 = stN.top();
        stN.pop();
        t2 = stN.top();
        stN.pop();
        t->left = t2;
        t->right = t1;
        stN.push(t);
      }
      stC.pop();
    }
  }
  t = stN.top();
  return t;
}

void PostOrder(nptr root) {
  if (root) {
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;
  }
}
void PreOrder(nptr root) {
  if (root) {
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
  }
}

int main() {

  string s;
  cout << "\nConverting InFix Expression to PreFix and PostFix using "
          "expression Tree\n"
       << endl;
  cout << "Enter Infix Expression: ";
  cin >> s;
  s = "(" + s;
  s += ")";
  nptr root = build(s);
  cout << "PreFix Expression using PreOrder Traversal: ";
  PreOrder(root);
  cout << endl;
  cout << "PostFix Expression using PostOrder Traversal: ";
  PostOrder(root);
  cout << endl;

  return 0;
}