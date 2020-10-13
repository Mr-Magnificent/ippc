#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        res.reserve(candidates.size());
        vector<vector<int>> ans;

        helper(ans, res, target, 0, 0, candidates);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& asf, int target, int ssf, int idx, vector<int> &candidates) {
        if (idx == candidates.size()) return;

        if (ssf > target) return;

        if (ssf == target) {
            ans.push_back(asf);
            return;
        }

        for(int i = idx; i < candidates.size(); ++i) {
            if (ssf + candidates[i] > target) continue;
            asf.push_back(candidates[i]);
            helper(ans, asf, target, ssf + candidates[i], i, candidates);
            asf.pop_back();
        }
    }
};
