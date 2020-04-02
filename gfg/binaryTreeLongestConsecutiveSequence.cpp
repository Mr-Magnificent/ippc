#include "../lib/createTree.hpp"

using namespace std;

struct Solution {
  int binaryTreeLongest(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int ans = 0;
    if (node->left != nullptr) {
      int leftAns = binaryTreeLongest(node->left);
      if (node->left->val == node->val + 1) {
        leftAns++;
      }

      ans = max(ans, leftAns);
    }

    if (node->right != nullptr) {
      int rightAns = binaryTreeLongest(node->right);
      if (node->right->val == node->val + 1) {
        rightAns++;
      }

      ans = max(ans, rightAns);
    }

    return (ans == 0) ? 1 : ans;
  }
};

int main(int argc, char **argv) {

  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    cout << treeNodeToString(root) << endl;
    int count = Solution().binaryTreeLongest(root);
    cout << count << endl;
  }
}
