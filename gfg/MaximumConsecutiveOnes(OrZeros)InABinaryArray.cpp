#include "../lib/createVector.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findLongestOnesWithinArray(vector<int> &arr) {
    int i = 0, j = 0;
    while (arr[i] != 1) {
      i++;
    }

    int maxLen = 0;

    while (j < arr.size()) {
      if (arr[j] == 1) {
        maxLen = max(j - i + 1, maxLen);
      } else {
        i = j + 1;
      }
      j += 1;
    }

    return maxLen;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<int> arr = stringToIntegerVector(line);
    cout << Solution().findLongestOnesWithinArray(arr) << endl;
  }
}