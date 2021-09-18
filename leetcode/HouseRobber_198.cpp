#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> take(nums.size());
        vector<int> leave(nums.size());

        take[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            take[i] = leave[i - 1] + nums[i];
            leave[i] = max(leave[i - 1], take[i - 1]);
        }

        return max(take[take.size() - 1], leave[leave.size() - 1]);
    }
};