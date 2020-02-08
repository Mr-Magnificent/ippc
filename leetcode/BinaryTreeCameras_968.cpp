#include "../lib/createTree.hpp"
using namespace std;

class Solution {
  int cameras = 0;

public:
  int calculateCameras(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left = calculateCameras(root->left);
    int right = calculateCameras(root->right);

    int res = left | right;
    if (res == 0) {
      return 3;
    }
    if (res == 3) {
      cameras++;
      return 1;
    }
    else {
      return 0;
    }
  }

  int minCameraCover(TreeNode *root) {
    int val = calculateCameras(root);
    if (val == 3)
      return this->cameras + 1;
    return this->cameras;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    int ret = Solution().minCameraCover(root);
    cout << to_string(ret) << endl;
  }
}