#include <bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        TreeNode* left = trimBST(root->left, L, R);
        TreeNode* right = trimBST(root->right, L, R);

        root->left = left;
        root->right = right;

        if (root->val >= L && root->val <= R) return root;
        else if (!root->left && !root->right) return nullptr;
        else if (root-left && root->left->val >= L && root->left->val <= R) return root->left;
        else return root->right;
    }
};