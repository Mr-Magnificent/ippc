#include "../lib/createTree.hpp"

class Solution {
    int ans = 0;
public:
    int distributeCoins(TreeNode* root) {
        helper(root);
        return ans;
    }

    int helper(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = helper(node->left);
        int right = helper(node->right);

        ans += abs(left) + abs(right);
        int sum = left + right;
        return node->val + sum - 1;
    }
};