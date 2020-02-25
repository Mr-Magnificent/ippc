#include "../lib/createTree.hpp"
using namespace std;
typedef TreeNode Node;

void diagonalPrint(Node *root) {
  unordered_map<int, vector<Node *>> map;
  stack<pair<Node *, int>> stk;
  stk.push(make_pair(root, 0));
  
  int minVal = 0;

  while (!stk.empty()) {
    pair<Node*, int> rmNode = stk.top();
    stk.pop();

    minVal = min(minVal, rmNode.second);

    if (map.find(rmNode.second) == map.end()) {
      map[rmNode.second] = vector<Node *>(1, rmNode.first);
    } else {
      map[rmNode.second].push_back(rmNode.first);
    }

    if (rmNode.first->right) {
      stk.push(make_pair(rmNode.first->right, rmNode.second));
    }

    if (rmNode.first->left) {
      stk.push(make_pair(rmNode.first->left, rmNode.second - 1));
    }
  }

  for (int i = 0; i >= minVal; i--) {
    for (Node *el: map[i]) {
      cout << el->val << " ";
    }
  }
  cout << endl;
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    diagonalPrint(root);
  }
}