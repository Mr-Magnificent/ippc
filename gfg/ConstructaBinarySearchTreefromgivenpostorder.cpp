#include "../lib/createTree.hpp"
#include "../lib/createVector.hpp"
using namespace std;

class Solution {
public:
  TreeNode *constructTree(vector<int> &arr) {
    TreeNode *root = constructTreeHelper(arr, INT_MIN, INT_MAX);
    return root;
  }

  TreeNode *constructTreeHelper(vector<int> &arr, int left, int right) {
    if (arr.empty()) {
      return nullptr;
    }

    int last = arr.back();
    if (last < left || last > right) {
      return nullptr;
    }

    TreeNode *node = new TreeNode(last);
    arr.pop_back();
    node->right = constructTreeHelper(arr, last, right);
    node->left = constructTreeHelper(arr, left, last);
    return node;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<int> arr = stringToIntegerVector(line);
    TreeNode *root = Solution().constructTree(arr);
    cout << treeNodeToString(root) << endl;
  }
}