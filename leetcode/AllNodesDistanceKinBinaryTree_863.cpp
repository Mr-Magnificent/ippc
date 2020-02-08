#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  unordered_map<TreeNode *, TreeNode *> createParentMap(TreeNode *root) {
    stack<TreeNode *> stk;
    unordered_map<TreeNode *, TreeNode *> parentMap;
    parentMap.insert(make_pair(root, (TreeNode *)nullptr));
    stk.push(root);

    while (!stk.empty()) {
      TreeNode *rmNode = stk.top();
      stk.pop();
      if (rmNode->left) {
        stk.push(rmNode->left);
        parentMap.insert(make_pair(rmNode->left, rmNode));
      }
      if (rmNode->right) {
        stk.push(rmNode->right);
        parentMap.insert(make_pair(rmNode->right, rmNode));
      }
    }
    return parentMap;
  }

  TreeNode *findNode(TreeNode *node, int target) {
    if (!node) {
      return nullptr;
    }

    if (node->val == target) {
      return node;
    }

    TreeNode *left = findNode(node->left, target);
    if (left) return left;
    TreeNode *right = findNode(node->right, target);
    if (right) return right;
    return nullptr;
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    unordered_map<TreeNode *, TreeNode *> parentMap{createParentMap(root)};
    // TreeNode *target = findNode(root, targetVal);
    queue<pair<TreeNode *, int>> que;
    unordered_set<TreeNode *> visited;
    vector<int> sol;

    que.push(make_pair(target, K));

    while (!que.empty()) {
      int size = que.size();
      while (size-- > 0) {
        pair<TreeNode *, int> rmNode{que.front()};
        que.pop();
        if (visited.find(rmNode.first) != visited.end()) {
          continue;
        }
        visited.insert(rmNode.first);
        if (!rmNode.second) {
          sol.push_back(rmNode.first->val);
          continue;
        }
        if (rmNode.first->left) {
          que.push(make_pair(rmNode.first->left, rmNode.second - 1));
        }
        if (rmNode.first->right) {
          que.push(make_pair(rmNode.first->right, rmNode.second - 1));
        }
        if (parentMap.at(rmNode.first) != nullptr) {
          que.push(make_pair(parentMap[rmNode.first], rmNode.second - 1));
        }
      }
    }
    return sol;
  }
};

int main(int arvc, char **argv) {
  string s;
  while (getline(cin, s)) {
    TreeNode *root = stringToTreeNode(s);
    getline(cin, s);
    int target = stoi(s);
    getline(cin, s);
    int k = stoi(s);
    Solution sol = Solution();
    vector<int> ret = sol.distanceK(root, target, k);
    cout << integerVectorToString(ret);
  }
}