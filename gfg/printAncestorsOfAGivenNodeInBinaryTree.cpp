#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;
#define Node TreeNode

class Solution {
public:
  bool printAncestors(Node *root, int val) {
    if (!root) {
      return false;
    }

    if (root->val == val) {
      return true;
    }

    bool res = printAncestors(root->left, val);
    res |= printAncestors(root->right, val);

    if (res) {
      cout << root->val << " ";
    }
    return res;
  }
};

int main(int argc, char **argv) {
  string str;
  while (getline(cin, str)) {
    Node *root = stringToTreeNode(str);
    Solution sol = Solution();
    sol.printAncestors(root, 4);
    cout << endl;
  }
}