#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0];
        });
        
        int count = 0;

        for(int i = 0; i < intervals.size(); ++i) {
            count++;
            vector<int>& ptr = intervals[i];
            int j;
            for(j = i + 1; intervals[j][1] < intervals[i][1]; ++j);
            i = j;
        }
        return count;
    }
};