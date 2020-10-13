#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for(int i = 1; i <= (n >> 1); ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        if ((n & 1) == 1) ans.push_back(0);
        return ans;
    }
};