#include "../lib/createVector.hpp"
#include <bits/stdc++.h>
using namespace std;

class SolutionMemo {
  vector<vector<int>> memo;

public:
  int change(int amount, vector<int> &coins) {
    if (amount == 0)
      return 1;
    if (coins.size() == 0)
      return 0;

    memo.resize(coins.size(), vector<int>(amount + 1, 0));

    for (int i = 0; i < memo.size(); ++i) {
      memo[i][0] = 1;
    }

    int ans = helper(amount, coins, 0);
    return ans;
  }

  int helper(int amount, vector<int> &coins, int idx) {
    int sum = 0;
    for (int i = idx; i < coins.size(); ++i) {
      if ((amount - coins[i]) < 0)
        continue;

      int diff = amount - coins[i];
      if (memo[i][diff] != 0) {
        sum += memo[i][diff];
      } else {
        sum += helper(diff, coins, i);
      }
    }

    memo[idx][amount] = sum;
    return sum;
  }
};

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> prev(amount + 1);
    vector<int> curr(amount + 1);

    prev[0] = 1;

    for (int i = 0; i < coins.size(); ++i) {
      for (int j = 0; j <= amount; j++) {
        curr[j] = prev[j] +
                   ((j - coins[i] >= 0) ? curr[j - coins[i]] : 0);
      }
      prev = curr;
    }

    return curr[amount];
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    int amount = stoi(line);
    getline(cin, line);
    vector<int> coins = stringToIntegerVector(line);
    cout << Solution().change(amount, coins) << endl;
  }
}