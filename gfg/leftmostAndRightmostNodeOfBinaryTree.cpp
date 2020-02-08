#include "../lib/createTree.hpp"
using namespace std;
typedef TreeNode Node;

void printLeftMostAndRightmost(TreeNode *root) {
  queue<TreeNode *> que;
  que.push(root);

  while (!que.empty()) {
    int size = que.size();
    cout << que.front()->val << endl;
    while (size-- > 0) {
      TreeNode *node = que.front();
      que.pop();
      if (node->left) {
        que.push(node->left);
      }
      if (node->right) {
        que.push(node->right);
      }
      if (size == 0) {
        cout << node->val << endl;
      }
    }
  }
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    printLeftMostAndRightmost(root);
  }
}