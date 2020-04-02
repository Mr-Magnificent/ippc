#include "../lib/createVector.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = flowerbed.size();
    int count = 0;
    if (len == 1 && flowerbed[0] == 1) {
      if (n == 0)
        return true;
      return false;
    } else if (len == 1 && flowerbed[0] == 0)
      return true;
    // first element and last element
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      count++;
    }
    if (flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0) {
      flowerbed[len - 1] = 1;
      count++;
    }
    
    for (int i = 1; i < (len - 1); i++) {
      if (flowerbed[i] == 1) {
        i++;
        continue;
      } else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        count++;
      }
    }
    if (count >= n) {
      return true;
    }
    return false;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> arr = stringToIntegerVector(line);
    int n;
    getline(cin, line);
    n = stoi(line);
    cout << Solution().canPlaceFlowers(arr, n) << endl;
  }
}