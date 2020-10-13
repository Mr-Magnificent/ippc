#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lastNeg = -1;
        vector<int> pos(nums.size() + 1, 0);
        vector<int> neg(nums.size() + 1, 0);

        pos[0] = 1;

        for(int i = 1; i <= nums.size(); ++i) {
            if (nums[i] == 0) {

            } else {
                if (nums[i] < 0) {
                    if (lastNeg == -1) {
                        pos[i] = 1;
                        neg[i] = nums[i];
                    } else {
                        pos[i] = neg[i - 1] * nums[i] * pos[lastNeg - 1];
                        lastNeg = i;
                        neg[i] = nums[i];
                    }
                } else {
                    pos[i] = pos[i - 1] * nums[i - 1];
                    neg[i] = neg[i - 1] * nums[i - 1];
                }
            }
        }

        int maxAns = 0;
        for(int i = 1; i < pos.size(); ++i) {
            maxAns = max(maxAns, pos[i]);
        }

        return maxAns;
    }
};