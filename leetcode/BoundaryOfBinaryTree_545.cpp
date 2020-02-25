#include "../lib/createTree.hpp"
using namespace std;
typedef TreeNode Node;

void printLeft(Node *node) {
  if (!node) {
    return;
  }
  if (node->left) {
    cout << node->val << " ";
    printLeft(node->left);
  } else if (node->right) {
    cout << node->val << " ";
    printLeft(node->right);
  } else {
    return;
  }
}

void printLeaf(Node *root) {
  if (!root) {
    return;
  }
  if (!root->left && !root->right) {
    cout << root->val << " ";
    return;
  }
  printLeaf(root->left);
  printLeaf(root->right);
}

void printRight(Node *node) {
  if (!node) {
    return;
  }
  if (node->right) {
    printRight(node->right);
    cout << node->val << " ";
  } else if (node->left) {
    printRight(node->left);
    cout << node->val << " ";
  } else {
    return;
  }
}

void printBoundary(Node *root) {
  // Your code here
  cout << root->val << " ";
  printLeft(root->left);
  printLeaf(root);
  printRight(root->right);
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    printBoundary(root);
    cout << endl;
  }
}