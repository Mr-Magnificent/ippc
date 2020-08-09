#include <bits/stdc++.h>
using namespace std;

#ifndef TRAILING_SPACE
#define TRAILING_SPACE
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
#endif

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(const vector<int> &list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

vector<vector<int>> stringToIntegerVectorVector(string line) {
    vector<vector<int>> output;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    
    string input = line.substr(1, line.length() - 2);
    stringstream ss;
    ss.str(input);
    char delim = ']';
    string row;
    while(getline(ss, row, delim)) {
        vector<int> v = stringToIntegerVector(row + "]");
        getline(ss, row, ',');
        output.push_back(v);
    }
    
    return output;
}

string integerVectorOfVectorToString(vector<vector<int>> &list) {
    int length = list.size();
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    
    for(int i = 0; i < length; i++) {
        string ret = integerVectorToString(list[i]);
        result += ret + ", ";
    }
    
    return "[" + result.substr(0, result.length() - 2) + "]";
}

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifndef TRAILING_SPACE
#define TRAILING_SPACE
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(
        find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
        .base(),
                input.end());
}
#endif

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }
    
    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node == nullptr) {
            output += "null, ";
            continue;
        }
        
        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }
    
    string item;
    stringstream ss;
    ss.str(input);
    
    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    
    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

class Solution {
    
    int getOverlapCount(vector<vector<int>> &a, vector<vector<int>> &b) {
        int count = 0;
        for(uint p = 0; p < a.size(); ++p) {
            for(uint q = 0; q < a[0].size(); ++q) {
                count += (a[p][q] == b[p][q]) * a[p][q];
            }
        }
        
        return count;
    }
    
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int maxCount = 0;
        for(uint i = 0; i < a.size(); ++i) {
            for(uint j = 0; j < a[0].size(); ++j) {
                // shift down, right
                vector<int> top = a[0];
                a.erase(a.begin());
                a.push_back(top);
                
                // check overlap 1's and store maximum for each shift
                maxCount = max(maxCount, getOverlapCount(a, b));
                
                for(uint p = 0; p < a.size(); ++p) {
                    int temp = a[p][0];
                    a[p].erase(a[p].begin());
                    a[p].push_back(temp);
                }
                
                maxCount = max(maxCount, getOverlapCount(a, b));
            }
        }
        return maxCount;
    }
};
