#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int maxNum = 1;

    arr[0] = 1;
    for (int i = 1; i < arr.size(); ++i) {
      arr[i] = (arr[i] - arr[i - 1] > 1) ? arr[i - 1] + 1 : arr[i];
      maxNum = maxNum < arr[i] ? arr[i] : maxNum;
    }

    return maxNum;
  }
};