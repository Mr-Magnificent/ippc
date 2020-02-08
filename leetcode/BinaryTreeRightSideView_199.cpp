#include "../lib/createTree.hpp"
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> que;
    if (!root) {
      return vector<int>();
    }
    vector<int> sol;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      sol.push_back(que.front()->val);
      while (size-- > 0) {
        TreeNode *node = que.front();
        que.pop();
        if (node->right)
          que.push(node->right);
        if (node->left)
          que.push(node->left);
      }
    }
    return sol;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    vector<int> ret = Solution().rightSideView(root);
    cout << integerVectorToString(ret) << endl;
  }
}