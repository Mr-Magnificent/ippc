#include <iostream>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  int height;

  TreeNode(int val) : val(val), height(0), left(nullptr), right(nullptr) {}
};

class AVL {
public:
  TreeNode *root;

  AVL() : root(nullptr) {}

  void addNode(int value) {
    TreeNode *node = new TreeNode(value);
    if (root == nullptr) {
      root = node;
      return;
    }
    addNodeHelper(root, node);
  }

  TreeNode *addNodeHelper(TreeNode *root, TreeNode *node) {
    if (root == nullptr) {
      return node;
    }

    if (root->val < node->val) {
      root->right = addNodeHelper(root->right, node);
    } else {
      root->left = addNodeHelper(root->left, node);
    }

    int leftHt = root->left ? root->left->height : 0;
    int rightHt = root->right ? root->right->height : 0;

    int myHt = leftHt - rightHt;

    if (myHt == 2) {
      if (root->left->height == 1) {

      } else {

      }
    } else if (myHt == -2) {
      if (root->right->height == -1) {

      } else {
        
      }
    } else {
      root->height = myHt;
    }

    return root;
  }

  TreeNode  *rotateRight(TreeNode *node) {
    TreeNode *left = node->left;
    TreeNode *leftRight = node->left->right;
    
    // *place the nodes
    left->right = node;
    left->right->left = leftRight;
    
    // * calculate node left child ka height
    node->height = getHeight(node);
    left->height = getHeight(left);

    return left;
  }

  TreeNode *rotateLeft(TreeNode *node) {
    TreeNode *right = node->right;
    TreeNode *rightLeft = node->right->left;
    
    // *place the nodes
    right->left = node;
    node->right = rightLeft;

    // *recalculate the heights of the trees
    node->height = getHeight(node);
    right->height = getHeight(right);

    return right;
  }

  int getHeight(TreeNode *node) {
    int leftHeight = node->left? node->left->height: 0;
    int rightHeight = node->right? node->right->height: 0;

    return max(leftHeight, rightHeight) + 1;
  }
};

void rotateLeft(TreeNode *node) {

}

void rotateRight(TreeNode *right) {

}

int main(int argc, char **argv) {}