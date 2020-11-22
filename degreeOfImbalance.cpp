#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    // first hight
    // second imbalance
    public:
    pair<int, int> degreeOfImbalance(TreeNode *root) {
        if (root == nullptr) {
            return pair<int, int>(0, 0);
        }

        pair<int, int> left = degreeOfImbalance(root->left);
        pair<int, int> right = degreeOfImbalance(root->right);

        int imbalance = abs(left.first - right.first);
        pair<int, int> newAns = make_pair(max(left.first, right.first), max(imbalance ,max(left.second, right.second)));
        newAns.first += 1;
        return newAns;
    }

};

int main() {
    TreeNode* root = stringToTreeNode("[5,null,4,3,6]");
    cout << Solution().degreeOfImbalance(root).second << endl;
}