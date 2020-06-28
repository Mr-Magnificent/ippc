#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD 1000000007
using namespace std;

class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(n, vector<int>(m + 1)));
    // for 1st place
    for(int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for(int j = 0; j < m; ++j) {
        if (i == n - 1) {
          dp[0][i][j] = 1;
        } else {
          sum = (sum + dp[0][i + 1][j]) % MOD;
          dp[0][i][j] = sum;
        }
      }
    }

    for(int place = 1; place < k; ++place) {
      for(int i = n - 1 - place; i >= 0; --i) {
        int sum = 0;
        for(int j = m - 1; j >= 0; --j) {
          sum = (sum + dp[place - 1][i + 1][j + 1]) % MOD;
          dp[place][i][j] = (dp[place][i + 1][j] + sum) % MOD;
        }
      }
    }

    int total = 0;
    for(int i = 0; i < m; ++i) {
      total = (total + dp[k - 1][0][i]) % MOD;
    }

    return total;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stoi(line);
    getline(cin, line);
    int m = stoi(line);
    getline(cin, line);
    int k = stoi(line);
    cout << Solution().numOfArrays(n, m, k) << endl;
  }
}