#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return vector<vector<int>>();
    }
    vector<vector<int>> sol;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> row;
      while (size-- != 0) {
        TreeNode *rmNode = q.front();
        row.push_back(rmNode->val);
        if (rmNode->left)
          q.push(rmNode->left);
        if (rmNode->right)
          q.push(rmNode->right);
        q.pop();
      }
      sol.push_back(row);
    }
    return sol;
  }
};

int main(int argc, char **argv) {
  string inp;
  while (getline(cin, inp)) {
    TreeNode *root = stringToTreeNode(inp);
    Solution sol = Solution();
    vector<vector<int>> ans = sol.levelOrder(root);
    for (vector<int> &row : ans) {
      for (int ele: row) {
        cout << ele << " ";
      }
      cout << endl;
    }
  }
}