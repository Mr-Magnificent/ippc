// Definition for a Node.
#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> sol{};
        queue<Node *> que;
        que.push(root);
        
        while (!que.empty()) {
            int size = 0;
            vector<int> level{};
            
            while (size--) {
                Node *remNode = que.front();
                que.pop();
                level.push_back(remNode->val);
                
                for(Node *child: remNode->children) {
                    que.push(child);
                }
            }
            
            sol.push_back(level);
        }
        return sol;
    }
};
