#include "../lib/createVector.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<tuple<int, int, int>> jobs;
    // vector<int> dp(profit.size(), 0);
    map<int, tuple<int, int, int>, greater<int>> dp;

    jobs.reserve(profit.size());

    for (int i = 0; i < startTime.size(); ++i) {
      jobs.push_back(make_tuple(endTime[i], profit[i], startTime[i]));
    }

    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < jobs.size(); ++i) {
      int max = -1;
      int maxLin = -1;
      // ! this is linear search but this can be optimized to binary search
      // for(int j = i - 1; j >= 0; --j) {
      //   if (dp[j] > dp[maxLin] && get<0>(jobs[j]) <= get<2>(jobs[i])) {
      //     maxLin = j;
      //   }
      // }

      // ! doesn't work
      // int lo = 0, hi = i - 1;
      // while (lo <= hi) {
      //   int mid = lo + ((hi - lo) / 2);
      //   if (get<0>(jobs[mid]) > get<2>(jobs[i])) {
      //     hi = mid - 1;
      //   } else if (get<0>(jobs[mid]) <= get<2>(jobs[i])) {
      //     if (max == -1)
      //       max = mid;
      //     else if (dp[max] < dp[mid])
      //       max = mid;
      //     lo = mid + 1;
      //   }
      // }

      auto it = dp.begin();
      for (; it != dp.end() && get<0>(it->second) > get<2>(jobs[i]); ++it)
        ;


      int curAmount = get<1>(jobs[i]) + (it != dp.end()) * it->first;
      if (curAmount > dp.begin()->first) {
        dp[curAmount] = jobs[i];
      }
    }

    return (dp.begin()->first);
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> st = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> et = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> am = stringToIntegerVector(line);

    cout << Solution().jobScheduling(st, et, am) << endl;
  }
}

/*
[1,2,3,3]
[3,4,5,6]
[50,10,40,70]

[1,2,3,4,6]
[3,5,10,6,9]
[20,20,100,70,60]

[1,1,1]
[2,3,4]
[5,6,4]

[24,24,7,2,1,13,6,14,18,24]
[27,27,20,7,14,22,20,24,19,27]
[6,1,4,2,3,6,5,6,9,8]
*/