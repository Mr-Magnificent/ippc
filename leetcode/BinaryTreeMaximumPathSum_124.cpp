#include "../lib/createTree.hpp"
using namespace std;

class Solution {
  int maxSum = INT_MIN;
public:
  int calculateMaxPathSum(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int left = calculateMaxPathSum(node->left);
    int right = calculateMaxPathSum(node->right);
    
    int maxVal = max(node->val, node->val + left);
    maxVal = max(maxVal, node->val + right);
    maxSum = max(maxSum, max(maxVal, node->val + left + right));
    return maxVal;
  }

  int maxPathSum(TreeNode *root) {
    if (!root) {
      return INT_MIN;
    }
    calculateMaxPathSum(root);
    return maxSum;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    int res = Solution().maxPathSum(root);
    cout << res << endl;
  }
}