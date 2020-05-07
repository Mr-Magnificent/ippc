#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    if (intervals.size() == 0) {
      return vector<vector<int>>();
    }

    vector<vector<int>> sol;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) -> bool { return a[0] < b[0]; });
    
    int start = intervals[0][0], end = intervals[0][1];
    for(vector<int> &v: intervals) {
      if (v[0] < end) {
        if (v[1] < end) {
          continue;
        }
        end = v[1];
      } else {
        sol.push_back(v);
        start = v[0]; end = v[1];
      }
    }
    return sol;
  }
};

int main() {}