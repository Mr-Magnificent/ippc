#include <bits/stdc++.h>
using namespace std;

/**
 * *Time O(nlog(n))
 * *Space O(n)
 */
class Solution1 {
    int countDuplicates(vector<int>& nums) {
        unordered_map<int, bool> freq;
        int count = 0;
        for(int num: nums) {
            count += (freq.count(num) == 1 && freq[num] == false);
            if (freq.find(num) != freq.end()) freq[num] = true;
            else freq[num] = false;            
        }
        return count;
    }

public:
    int findPairs(vector<int>& nums, int k) {
        set<int> vals;
        int count = 0;

        if (k == 0) return countDuplicates(nums);

        for(int num: nums) vals.insert(num);
        auto i = vals.begin();
        auto j = vals.begin();
        j++;
        while (j != vals.end() && i != j) {
            int diff = (*j - *i);
            count += (diff == k);
            if (diff < k) {
                j++;
            } else if (diff > k) {
                i++;
            } else {
                i++; j++;
            }
        }
        return count;
    }
};

/**
 * *Time O(n)
 * *Space O(n)
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> seen;
        unordered_set<int> used;

        int count = 0;
        for(int num: nums) {
            int prev = num - k;
            if (seen.count(prev) == 0 && used.count(prev) == 1) {
                count++;
                seen.insert(prev);
            }
            int next = num + k;
            if (seen.count(num) == 0 && used.count(next) == 1) {
                count++;
                seen.insert(num);
            }
            used.insert(num);
        }

        return count;
    }
};