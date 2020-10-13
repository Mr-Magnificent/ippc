#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool binarySearchAndErase(vector<int> &digits, int tar) {
    int lo = 0;
    int hi = digits.size() - 1;

    while (lo <= hi) {
      int mid = hi - ((hi - lo) / 2);
      if (digits[mid] == tar) {
        digits.erase(digits.begin() + mid);
        return true;
      } else if (digits[mid] < tar) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return false;
  }

public:
  string largestMultipleOfThree(vector<int> &digits) {
    if (digits.size() == 0)
      return "";
    sort(digits.begin(), digits.end(), greater<int>());

    int sum = accumulate(digits.begin(), digits.end(), 0);

    if (sum == 0)
      return "0";

    string ans;
    if (sum % 3 == 0) {
      for (int dig : digits)
        ans += to_string(dig);
      return ans;
    }

    // Binary search items
    // * if sum % 3 == 1 ? try removing 1, 4, 7 : remove two of 2, 5, 8
    // * if sum % 3 == 2 ? try removing 2, 5, 8 : remove two of 1, 4, 7

    if (sum % 3 == 1) {
      for (int i = 1; i <= 9; i += 3) {
        if (binarySearchAndErase(digits, i)) {
          if (digits.size() == 0)
            return "";
          if (digits[0] == 0)
            return 0;
          for (int dig : digits)
            ans += to_string(dig);
          return ans;
        }
      }

      bool two = false;
      for (int i = 2; i <= 9;) {
        if (binarySearchAndErase(digits, i)) {
          if (two == true) {
            if (digits.size() == 0)
              return "";
            if (digits[0] == 0)
              return 0;
            for (int dig : digits)
              ans += to_string(dig);
            return ans;
          } else
            two = true;
        } else
          i += 3;
      }
    }

    if (sum % 3 == 2) {
      for (int i = 2; i <= 9; i += 3) {
        if (binarySearchAndErase(digits, i)) {
          if (digits.size() == 0)
            return "";
          if (digits[0] == 0)
            return "0";
          for (int dig : digits)
            ans += to_string(dig);
          return ans;
        }
      }

      bool two = false;
      for (int i = 1; i <= 9;) {
        if (binarySearchAndErase(digits, i)) {
          if (two == true) {
            if (digits.size() == 0)
              return "";
            if (digits[0] == 0)
              return 0;
            for (int dig : digits)
              ans += to_string(dig);
            return ans;
          } else
            two = true;
        } else
          i += 3;
      }
    }

    if (digits.size() == 0)
      return "";
    if (digits[0] == 0)
      return 0;
    for (int dig : digits)
      ans += to_string(dig);
    return ans;
  }
};
