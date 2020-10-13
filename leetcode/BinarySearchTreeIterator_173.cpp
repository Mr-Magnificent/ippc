#include <bits/stdc++.h>
#include "../lib/createTree.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> stk; 
public:
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        while (curr->left != nullptr) {
            stk.emplace(curr);
            curr = curr->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *rem = stk.top();
        stk.pop();
        TreeNode *itr = rem->right;
        while(itr != nullptr) {
            stk.emplace(itr);
            itr = itr->left;
        }
        return rem->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */