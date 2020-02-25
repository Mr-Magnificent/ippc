#include "../lib/createTree.hpp"
using namespace std;

class Solution {

  int minVal;
  int maxVal;

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    minVal = min(p->val, q->val);
    maxVal = max(p->val, q->val);
    return findLCA(root);
  }

  TreeNode *findLCA(TreeNode *root) {
    if (root->val == minVal || root->val == maxVal) {
      return root;
    }

    if (root->val > maxVal) {
      return findLCA(root->left);
    } else if (root->val < minVal) {
      return findLCA(root->right);
    }
    return root;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    getline(cin, line);
    TreeNode *p = new TreeNode(stoi(line));
    getline(cin, line);
    TreeNode *q = new TreeNode(stoi(line));

    TreeNode *temp = Solution().lowestCommonAncestor(root, p, q);
    cout << temp->val << endl;
  }
}