#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2, -1);

        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = hi - (hi - lo) / 2;
            if (nums[mid] == target) {
                nums[0] = mid;
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        lo = 0;
        hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = hi  - (hi - lo) / 2;
            if (nums[mid] == target) {
                sol[1] = mid;
                lo = mid + 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return sol;
    }
};