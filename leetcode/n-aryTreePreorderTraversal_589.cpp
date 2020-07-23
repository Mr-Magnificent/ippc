#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return vector<int>{};
        stack<pair<Node *, unsigned int>> stk;
        stk.push({root, 0});
        vector<int> sol{};
        
        while (!stk.empty()) {
            auto &remNode = stk.top();
            
            if (remNode.first->children.size() == remNode.second) {
                stk.pop();
            } else {
                if (remNode.second == 0) {
                    sol.push_back(remNode.first->val);
                }
                stk.push({remNode.first->children[remNode.second], 0});
                remNode.second++;
            }
        }
        return sol;
    }
};
