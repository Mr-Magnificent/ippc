#include <bits/stdc++.h>
#include "../lib/createVector.hpp"
using namespace std;

class AVLNode {
public:
  int val;
  AVLNode *left;
  AVLNode *right;
  int height;

  AVLNode(int val) : height(1), left(nullptr), right(nullptr), val(val) {}
};

class AVL {
public:
  AVLNode *root;

  AVL() : root(nullptr) {}

  void display(AVLNode *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->val << "@" << getBalanceFactor(root) << ": ";
  if (root->left) {
    cout << to_string(root->left->val) << " ";
  } else {
    cout << " null";
  }
  if (root->right) {
    cout << to_string(root->right->val) << " ";
  } else {
    cout << " null";
  }
  cout << endl;
  display(root->left);
  display(root->right);
}

  void addNode(int value) {
    AVLNode *temp = findPlace(root, value);
    root = temp;
  }

  AVLNode *findPlace(AVLNode *root, int val) {
    if (root == nullptr) {
      AVLNode *node = new AVLNode(val);
      return node;
    }

    // find the position of the node
    if (root->val < val) {
      root->right = findPlace(root->right, val);
    } else {
      root->left = findPlace(root->left, val);
    }

    // find the balance factor of the root
    int balFact = getBalanceFactor(root);
    root->height = getHeight(root);

    // check if rotations are required
    if (balFact == 2) {
      // LL rotation
      if (getBalanceFactor(root->left) == 1) {
        return rotateRight(root);
      }
      // LR rotation
      else {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
      }
    } else if (balFact == -2) {
      // RR rotation
      if (getBalanceFactor(root->right) == -1) {
        return rotateLeft(root);
      }
      // RL rotation
      else {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
      }
    }
    return root;
  }

  AVLNode *rotateRight(AVLNode *node) {
    AVLNode *left = node->left;
    AVLNode *leftRight = node->left->right;

    // * place the nodes
    left->right = node;
    node->left = leftRight;

    // * calculate node, left child ka height
    node->height = getHeight(node);
    left->height = getHeight(left);

    return left;
  }

  AVLNode *rotateLeft(AVLNode *node) {
    AVLNode *right = node->right;
    AVLNode *rightLeft = node->right->left;

    // *place the nodes
    right->left = node;
    node->right = rightLeft;

    // *recalculate the heights of the trees
    node->height = getHeight(node);
    right->height = getHeight(right);

    return right;
  }

  int getHeight(AVLNode *node) {
    int leftHeight = node->left ? node->left->height : 0;
    int rightHeight = node->right ? node->right->height : 0;

    return max(leftHeight, rightHeight) + 1;
  }

  int getBalanceFactor(AVLNode *node) {
    int leftHeight = node->left ? node->left->height : 0;
    int rightHeight = node->right ? node->right->height : 0;

    return leftHeight - rightHeight;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<int> vals = stringToIntegerVector(line);
    AVL sol = AVL();

    for (int i = 0; i < vals.size(); i++) {
      sol.addNode(vals[i]);
    }

    // treeNodeToString(sol.root);
    sol.display(sol.root);
  }
}