#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n) {
    if (n == 1) {
      return vector<TreeNode *>(1, new TreeNode(0));
    }
    vector<vector<TreeNode *>> prev((n + 1) / 2, vector<TreeNode *>());
    prev[0].push_back(new TreeNode(0));

    for (int i = 3; i <= n; i += 2) {
      for (int j = 1; j < i; j += 2) {
        for (int k = 0; k < prev[j / 2].size(); k++) {
          for (int l = 0; l < prev[(i - j - 2) / 2].size(); l++) {
            TreeNode *node = new TreeNode(0);
            node->left = prev[j / 2][k];
            node->right = prev[(i - j - 2) / 2][l];
            prev[i/2].push_back(node);
          }
        }
      }
    }

    return prev[n / 2];
  }
};

int main() {
  int n;
  while (cin >> n) {
    Solution().allPossibleFBT(n);
  }
}