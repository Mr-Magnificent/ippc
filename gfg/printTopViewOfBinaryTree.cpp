#include "../lib/createTree.hpp"
using namespace std;

void printView(TreeNode *root) {
  unordered_map<int, int> map;
  int minInd = INT_MAX;
  queue<pair<TreeNode *, int>> que;
  que.push(make_pair(root, 0));
  while (!que.empty()) {
    int size = que.size();
    while (size-- > 0) {
      pair<TreeNode *, int> rmNode = que.front();
      que.pop();
      if (map.find(rmNode.second) == map.end()) {
        map.insert(make_pair(rmNode.second, rmNode.first->val));
      }
      minInd = min(minInd, rmNode.second);
      if (rmNode.first->left)
      que.push(make_pair(rmNode.first->left, rmNode.second - 1));
      if (rmNode.first->right)
      que.push(make_pair(rmNode.first->right, rmNode.second + 1));
    }
  }

  while(map.find(minInd) != map.end()) {
    cout << map[minInd] << " ";
    minInd++;
  }
  cout << endl;
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    printView(root);
  }
}