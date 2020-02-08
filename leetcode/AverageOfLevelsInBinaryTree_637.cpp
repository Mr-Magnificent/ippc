#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> q;
    vector<double> sol;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      double avg{};
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        avg += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      sol.push_back(avg / size);
    }
    return sol;
  }
};

int main(int argc, char **argv) {
  string inp;
  while (getline(cin, inp)) {
    TreeNode *root = stringToTreeNode(inp);
    Solution sol = Solution();
    vector<double> ans = sol.averageOfLevels(root);
    for (double avg : ans)
      cout << avg << endl;
    cout << endl;
  }
}