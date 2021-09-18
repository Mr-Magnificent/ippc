#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> sol;
        for(int i = 1, idx = 0; i <= n || idx == target.size(); ++i) {
            if (i == target[idx]) {
                sol.push_back("Push");
            } else {
                sol.push_back("Push");
                sol.push_back("Pop");
            }
        }
        return sol;
    }
};