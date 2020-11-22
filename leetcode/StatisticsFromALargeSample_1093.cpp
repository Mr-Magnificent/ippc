#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<double> sampleStats(vector<int> &count) {
    long totSum = 0;
    int countEle = 0;
    vector<double> res {INT_MAX, INT_MIN, 0, 0, 0};

    for (int i = 0; i < count.size(); ++i) {
      totSum += (i * count[i]);
      countEle += count[i];

      res[0] = (count[i] != 0 && res[0] == INT_MAX) ? i : res[0];
      res[1] = count[i] != 0 ? i : res[1];
      res[4] = count[res[4]] < count[i] ? i : res[4];
    }

    int idx = -1, countHlf = 0;
    for(countHlf = countEle / 2; countHlf > 0;) {
        ++idx;
        countHlf -= count[idx];
    }

    int offset = 0;
    if (countHlf == 0 && countEle % 2 == 0) offset++;
    while(count[idx + offset] == 0) ++offset;

    res[2] = totSum / double(countEle);
    res[3] = (double(idx) + idx + offset) / 2;
    return res;
  }
};