#include <bits/stdc++.h>
#include "../lib/createVector.hpp"
using  namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int gMax = 0;
        int cMax0 = 0, cMax1 = 0;
        bool con0 = false, zero = false;

        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                // is it consecutive 0
                zero = true;
                if (con0 == true) {
                    cMax0 = cMax1 = 0;
                } else {
                    cMax1 = cMax0;
                    cMax0 = 0;
                }
                con0 = true;
            } else {
                // is it a 1?
                cMax0++;
                cMax1++;
                cout << cMax0 << " " << cMax1 << endl;
                gMax = max(gMax, max(cMax0, cMax1));
                con0 = false;
            }
        }
        if (zero) return gMax;
        return nums.size() - 1;
    }
};

int main(int argc, char** argv) {
    string line;
    while (getline(cin, line)) {
        vector<int> inp = stringToIntegerVector(line);
        cout << Solution().longestSubarray(inp) << endl;
    }
}