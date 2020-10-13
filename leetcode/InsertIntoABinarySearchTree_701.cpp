#include <bits/stdc++.h>
#include "../lib/createTree.hpp"
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        TreeNode **curr = &root;

        while (*curr != nullptr) {
            curr = (*curr)->val > val ? &(*curr)->left : &(*curr)->right;
        }

        *curr = node;
        return root;
    }
};