#include "../lib/createTree.hpp"
using namespace std;

// morris traversal
class Solution {
public:
  int sumComb(int sum, int val, int L, int R) {
    if (val >= L && val <= R) {
      return val + sum;
    }
    return sum;
  }

  int rangeSumBST(TreeNode *root, int L, int R) {
    TreeNode *curr = root;
    int sum = 0;
    while (curr != nullptr) {
      if (curr->left == nullptr || curr->val < L) {
        sum = sumComb(sum, curr->val, L, R);
        curr = curr->right;
      } else {
        TreeNode *currNext = curr->left;
        while (currNext->right != curr && currNext->right != nullptr) {
          currNext = currNext->right;
        }

        if (currNext->right == curr) {
          sum = sumComb(sum, curr->val, L, R);
          currNext->right = nullptr;
          if (curr->val < R) {
            curr = curr->right;
          } else {
            curr = nullptr;
          }
        } else {
          currNext->right = curr;
          curr = curr->left;
        }
      }
    }
    return sum;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    cout << Solution().rangeSumBST(root, 18, 24) << endl;
  }
}
