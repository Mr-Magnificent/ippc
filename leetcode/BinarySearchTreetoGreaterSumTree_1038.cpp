#include "../lib/createTree.hpp"
using namespace std;

class Solution {
  int value = 0;

public:
  TreeNode *bstToGst(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    bstToGst(root->right);
    root->val += value;
    value = root->val;
    bstToGst(root->left);
    return root;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    TreeNode *ret = Solution().bstToGst(root);

    string out = treeNodeToString(ret);
    cout << out << endl;
  }
  return 0;
}