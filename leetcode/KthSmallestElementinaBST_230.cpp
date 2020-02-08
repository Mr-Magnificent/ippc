#include "../lib/createTree.hpp"
using namespace std;

class Solution {
  int value;
  int count = 0;

public:
  int kthSmallest(TreeNode *root, int k) {
    TreeNode *curr = root;
    while(curr != nullptr) {
      if (curr->left) {
        
      }
    }
  }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().kthSmallest(root, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}