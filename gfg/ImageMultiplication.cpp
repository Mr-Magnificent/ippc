#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int multiplyImage(TreeNode *root) {
    if (!root) {
      return 0;
    }

    ans += root->val * root->val;
    if (root->left && root->right) {
      multiplyImageHelper(root->left, root->right);
    }

    return ans;
  }

  void multiplyImageHelper(TreeNode *left, TreeNode *right) {
    ans += left->val * right->val;
    if (left->left && right->right) {
      multiplyImageHelper(left->left, right->right);
    }

    if (left->right && right->left) {
      multiplyImageHelper(left->right, right->left);
    }
  }
private:
  int ans = 0;

};

int main(int argc, char **argv) {
  string line;

  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    int ans = Solution().multiplyImage(root);
    cout << ans << endl;
  }
}