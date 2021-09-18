#include <bits/stdc++.h>
using namespace std;

class Solution {
    int reverse(int num) {
        int rnum = 0;
        while (num != 0) {
            rnum *= 10 + (num % 10);
            num /= 10;
        }
        return rnum;
    }

public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0;

        for(int ele: nums) {
            ele = ele - reverse(ele);
            count += m[ele];
            m[ele]++;
        }

        return count;
    }
};