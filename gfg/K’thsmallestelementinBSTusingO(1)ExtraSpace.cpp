#include "../lib/createTree.hpp"
using namespace std;

void morris(TreeNode *root, int k) {
  int count = 0;
  TreeNode *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      count++;
      if (count == k) {
        cout << curr->val << endl;
      }
      curr = curr->right;
    } else {
      TreeNode *currLeft = curr->left;
      while (currLeft->right != curr && currLeft->right != nullptr) {
        currLeft = currLeft->right;
      }
      if (currLeft->right == nullptr) {
        currLeft->right = curr;
        curr = curr->left;
      }
      else {
        count++;
        if (count == k) {
          cout << curr->val << endl;
        }
        currLeft->right = nullptr;
        curr = curr->right;
      }
    }
  }
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    int val;
    cin >> val;
    morris(root, val);
  }
}