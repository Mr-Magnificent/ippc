#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int j = 0;
        if (nums.size() == 1) return nums[0];
        
        while (i < nums.size()) {
            while (j < nums.size() && nums[i] == nums[j]) {
                j++;
            }
            
            if (j == nums.size()) break;
            
            nums[i] = INT_MIN;
            nums[j] = INT_MIN;
            j++;
            while(nums[i] == INT_MIN) i++;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << " ";
            if (nums[i] != INT_MIN) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main(int argc, char argv) {
    vector<int> v{4,4,4,2,2};
    cout << Solution().majorityElement(v);
}
