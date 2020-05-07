#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    int gans = 0;

    for (int i = 0; i < n; ++i) {
      stack<int> stk;
      stk.push(-1);
      // increment the current value of matrix
      int ans = 0;
      for (int j = 0; j < m; ++j) {

        if (i != 0 && matrix[i - 1][j] != 0 && matrix[i][j] != 0) {
          matrix[i][j] = matrix[i - 1][j] + 1;
        }

        int top = stk.top();
        while (stk.size() > 1 && matrix[j] < matrix[top]) {
          top = stk.top();
          stk.pop();

          if (matrix[i][top] <= (j - 1) - stk.top()) {
            ans = max(ans, ((j - 1) - stk.top()) * matrix[i][top]);
          }
        }

        stk.push(i);
      }

      while (stk.size() > 1) {
        int idxToCheck = stk.top();
        stk.pop();
        ans = max(ans, ((m - 1) - stk.top()) * matrix[i][idxToCheck]);
      }

      gans = max(ans, gans);
    }

    return gans;
  }
};

int main(int argc, char **argv) {}