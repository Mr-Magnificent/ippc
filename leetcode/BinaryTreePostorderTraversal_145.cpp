#include <bits/stdc++.h>
using namespace std;


//~ Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        stack<pair<TreeNode *, int>> stk;
        stk.push({root, 0});
        vector<int> sol{};
        
        while (!stk.empty()) {
            auto &pair = stk.top();
            
            if (pair.second == 0) {
                if (pair.first->left) {
                    stk.push({pair.first->left, 0});
                }
                pair.second++;
            } else if (pair.second == 1) {
                if (pair.first->right) {
                    stk.push({pair.first->right, 0});
                }
                pair.second++;
            } else {
                sol.push_back(pair.first->val);
                stk.pop();
            }
        
        return sol;
    }
};
