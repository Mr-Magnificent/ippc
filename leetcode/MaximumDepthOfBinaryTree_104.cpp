#include <bits/stdc++.h>
#include "../lib/createTree.hpp"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};