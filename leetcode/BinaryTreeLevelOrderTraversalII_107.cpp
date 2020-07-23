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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            vector<int> level(size);
            for(int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                
                level[i] = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
