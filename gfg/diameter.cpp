#include "../lib/createTree.hpp"
#include <string>
typedef TreeNode Node;
using namespace std;

struct Diameter {
  int diameter = 0;

  int getDiameter(Node *root) {
    if (!root) {
      return 0;
    }

    int left = getDiameter(root->left);
    int right = getDiameter(root->right);

    // * check if the height(root->left) and height(right) + 1
    // * can overcome the present diameter
    this->diameter = max(this->diameter, left + right + 1);
    return max(left, right) + 1;
  }
};

int diameter(Node *root) {
  Diameter sol;
  sol.getDiameter(root);
  return sol.diameter;
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    cout << diameter(root) << endl;
  }
}