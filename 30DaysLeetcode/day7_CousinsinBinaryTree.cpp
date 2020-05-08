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
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode *> que;
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            
            // count the number of items matched at current level
            int count = 0;
            while (size-- > 0) {
                TreeNode *rm = que.front();
                que.pop();
                
                // check if same parent if true return false
                bool check = checkParent(rm, x, y);
                
                if (check == true) return false;
                
                // check if the rm->val == x || y; increment count
                if (rm->val == x || rm->val == y) count++;
                
                // push the children of the rm node
                if (rm->left) que.push(rm->left);
                if (rm->right) que.push(rm->right);
            }
            
            if (count == 1) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkParent(TreeNode *node, const int &x, const int &y) {
        if (!node->left || !node->right) return false;
        
        if ((node->left->val == x && node->right->val == y) 
            || (node->left->val == y && node->right->val == x)) {
            return true;
        }
        
        return false;
    }
};
