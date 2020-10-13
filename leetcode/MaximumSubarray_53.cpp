#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gmax = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            gmax = max(gmax, sum);
        }

        return gmax;
    }
};

// divide and conquer approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};