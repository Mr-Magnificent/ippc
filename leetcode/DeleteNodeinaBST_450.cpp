#include "../lib/createTree.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

  TreeNode *deleteNode(TreeNode *root, int key) {

    if (root == nullptr) {
      return nullptr;
    }

    if (root->val == key) {
      if (!root->left) {
        return root->right;
      } else {
        int val = findLeftMaxValue(root->left);
        root->val = val;
        root->left = deleteLeftMaxNode(root->left);
        return root;
      }
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    return root;
  }

  int findLeftMaxValue(TreeNode *root) {
    if (!root->right) {
      return root->val;
    }

    return findLeftMaxValue(root->right);
  }

  TreeNode *deleteLeftMaxNode(TreeNode *root) {
    if (!root->right) {
      return root->left;
    }

    root->right = deleteLeftMaxNode(root->right);
    return root;
  }

  // TreeNode *deleteRightElement(TreeNode *node) {
  //   if (!node->right) {
  //     return node->left;
  //   }
  //   node->right = deleteRightElement(node->right);
  //   return node;
  // }

  // TreeNode *findSuitableElement(TreeNode *node) {
  //   if (!node->right) {
  //     return node;
  //   }

  //   return findSuitableElement(node->right);
  // }
};

int main(int argc, char **argv) {
  string line;

  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    int val;
    cin >> val;

    TreeNode *sol = Solution().deleteNodeRecur(root, val);
    cout << treeNodeToString(sol) << endl;
  }
}
