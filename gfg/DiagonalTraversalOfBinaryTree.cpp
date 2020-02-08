#include "../lib/createTree.hpp"
using namespace std;
typedef TreeNode Node;

void diagonalPrint(Node *root) {
  unordered_map<int, vector<Node *>> map;
  stack<pair<TreeNode *, int>> stk;
  stk.push(make_pair(root, 0));
  map.insert(make_pair(0, vector<Node *>(1, root)));

}

int main(int argc, char **argv) {}