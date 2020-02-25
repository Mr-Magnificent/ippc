#include "../lib/createTree.hpp"
#include "../lib/createVector.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  unordered_map<int, int> valToIdx;
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    initializeMap(inorder);
    TreeNode *root = createTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
  }

  void initializeMap(vector<int> &inorder) {
    int len = inorder.size();
    for(int i = 0; i < len; i++) {
      this->valToIdx.insert(make_pair(inorder[i], i));
    }
  }

  TreeNode *createTree(vector<int> &preorder, int ps, int pe,
                       vector<int> &inorder, int is, int ie) {
    if (is > ie) {
      return nullptr;
    }

    TreeNode *node = new TreeNode(preorder[ps]);
    int idx = findIndex(inorder, preorder[ps], is, ie);

    int len = idx - is;

    node->left = createTree(preorder, ps + 1, ps + len, inorder, is, idx - 1);
    node->right = createTree(preorder, ps + len + 1, pe, inorder, idx + 1, ie);

    return node;
  }

  int findIndex(vector<int> &inorder, int val, int is, int ie) {
    return valToIdx[val];
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<int> arr1 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> arr2 = stringToIntegerVector(line);
    TreeNode *root = Solution().buildTree(arr1, arr2);
    cout << treeNodeToString(root) << endl;
  }
}