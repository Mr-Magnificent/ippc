#include "../lib/createTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<int, vector<int>> map;
  int minRange = 0;
  int maxRange = 0;

public:
  void findElements(TreeNode *root, int pos) {
    if (root == nullptr) {
      return;
    }

    minRange = min(minRange, pos);
    maxRange = max(maxRange, pos);


    if (map.find(pos) != map.end()) {
      map[pos].push_back(root->val);
    } else {
      map.insert(make_pair(pos, vector<int>(1, root->val)));
    }

    findElements(root->right, pos + 1);
    findElements(root->left, pos - 1);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    findElements(root, 0);
    vector<vector<int>> result;

    for (int i = minRange; i <= maxRange; i++) {
      result.push_back(map[i]);
    }
    return result;
  }
};

int main(int argc, char **argv) {
  string line;

  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    vector<vector<int>> ret = Solution().verticalTraversal(root);
    for (vector<int> &arr: ret) {
      sort(arr.begin(), arr.end());
    }
    cout << integerVectorOfVectorToString(ret) << "\n";
  }
}