#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int min1 = INT_MAX, min2 = INT_MAX;
        unordered_set<int> nums;
        for(int num: arr) {
            min1 = num < min2? num: min1;
            min2 = num < min2 && num != min1? num: min2;
            nums.insert(num);
        }

        int diff = min2 - min1;
        nums.erase(min1);
        nums.erase(min2);
        while(!nums.empty()) {
            min2 += diff;
            if (nums.find(min2) == nums.end()) return false;
            nums.erase(min2);
        }
        return true;
    }
};
