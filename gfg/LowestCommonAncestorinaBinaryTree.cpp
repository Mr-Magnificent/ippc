#include "../lib/createTree.hpp"
typedef TreeNode Node;
using namespace std;

int heightOfTree(Node *root) {
  if (root == nullptr) {
    return -1;
  }

  int left = heightOfTree(root->left);
  int right = heightOfTree(root->right);

  return max(left, right) + 1;
}

void createParentMap(Node *root, int height, unordered_map<Node *, Node *> &parentMap) {
  queue<Node *> que;
  que.push(root);
  int level = -1;

  parentMap.insert(make_pair(root, nullptr));

  while(!que.empty()) {
    int size = que.size();
    level++;
    while (size-- > 0) {

    }
  }  
}

Node *lca(Node *root, int n1, int n2) {
  // Your code here
  int height = heightOfTree(root);
  unordered_map<Node *, Node *> parentMap;
  createParentMap(root, height, parentMap);
}

int main(int argc, char **argv) {

}