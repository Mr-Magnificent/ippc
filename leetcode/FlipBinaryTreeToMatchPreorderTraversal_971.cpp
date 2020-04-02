// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

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
// class Solution {
//   vector<int> result;

// public:
//   vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
//     if (root->val != voyage[0]) {
//       return {-1};
//     }

//     int idx = 0;
//     bool flag = getflipMatch(root, voyage, idx);
//     // * check if the voyage was possible
//     if (!flag) {
//       return {-1};
//     }

//     // * if voyage was possible return the result
//     return result;
//   }

//   bool getflipMatch(TreeNode *root, vector<int> &voyage, int &idx) {
//     if (root == nullptr) {
//       return true;
//     }

//      if (idx >= voyage.size()) {
//       return true;
//     }

//     // * maintain a boolean flag
//     bool flag = true;

//     // * increment idx by one initially everytime
//     idx = idx + 1;

//     // * if left match
//     if (root->left && root->left->val == voyage[idx]) {
//       flag &= getflipMatch(root->left, voyage, idx);
//       if (!flag) {
//         return flag;
//       }

//       idx = idx + 1;
//       flag &= getflipMatch(root->right, voyage, idx);
//       return flag;
//     }
//     // * if right match
//     else if (root->left && root->right && root->right->val == voyage[idx]) {
//       // * swap the nodes
//       TreeNode *temp = root->left;
//       root->left = root->right;
//       root->right = temp;

//       // *store it in the result vector
//       result.push_back(root->val);
//       flag &= getflipMatch(root->left, voyage, idx);
//       if (!flag) {
//         return flag;
//       }

//       idx += 1;
//       flag &= getflipMatch(root->right, voyage, idx);
//       return flag;
//     }
//     // * only right child available and it matches the voyage index
//     else if (root->right && root->right->val == voyage[idx]) {
//       flag &= getflipMatch(root->right, voyage, idx);
//       return flag;
//     }
//     // * if leaf node
//     else if (!root->left && !root->right) {
//       // idx += 1;
//       return true;
//     }
//     // * else
//     return false;
//   }
// };

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
  vector<int> result;
  int idx = 0;
public:
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    int idx = 0;
    bool flag = findIt(root, voyage, idx);
    
    if (!flag) {
      return {-1};
    }

    return result;
  }

  // ! find it
  bool findIt(TreeNode *root, vector<int> &voyage) {
    
  }

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    getline(cin, line);
    vector<int> voyage = stringToIntegerVector(line);
    vector<int> result = Solution().flipMatchVoyage(root, voyage);
    cout << integerVectorToString(result) << endl;
  }
}
