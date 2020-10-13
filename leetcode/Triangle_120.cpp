#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> prev(triangle.size() + 1);
    vector<int> curr(triangle.size());

    for(int i = triangle.size() - 1; i >= 0; --i) {
      for(int j = 0; j <= i; ++j) {
        curr[j] = min(prev[j], prev[j + 1]);
      }
      prev = curr;
    }

    return curr[0];
  }
};