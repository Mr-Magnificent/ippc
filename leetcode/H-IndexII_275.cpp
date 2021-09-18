#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
      int hindex = 0;
      int lo = 0;
      int hi = citations.size();
      while (lo <= hi) {
          int mid = hi - (hi - lo) / 2;

          if (hindex < citations[mid]) {
              hindex = citations.size() - mid;
          } 

          if (mid >= citations[mid]) {
              hi = lo - 1;
          } else {
              lo = hi + 1;
          }
      }
      return hindex;
  }
};
