#include "../lib/createTree.hpp"
using namespace std;
typedef TreeNode Node;

int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here
  static int count = 0;
  if (!root) {
    return count;
  }
  if (root->val >= l && root->val <= h) {
    count++;
  }
  getCountOfNode(root->left, l, h);
  getCountOfNode(root->right, l, h);
  return count;
}

int main(int argc, char **argv) {
  string s;
  while (getline(cin, s)) {
    Node *root = stringToTreeNode(s);
    cout << getCountOfNode(root, 2, 8) << endl;
  }
  return 0;
}