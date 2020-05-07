#include <bits/stdc++.h>
#include "../lib/createVector.hpp"
using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    int len = matrix.size();
    int bre = matrix[0].size();
    
    int total = len + bre - 1;

    vector<int> ans;

    for (int g = 0; g < total; g++) {
      if (g % 2 == 0) {
        if (g < len - 1) {
          int j = 0, i = g;
          while (i >= 0 && j < bre) {
            ans.push_back(matrix[i][j]);
            j++;
            i--;
          }
        } else {
          int i = len - 1, j = g - len + 1;
          while (i >= 0 && j < bre) {
            ans.push_back(matrix[i][j]);
            j++;
            i--;
          }
        }
      } else {
        if (g < bre - 1) {
          int i = 0, j = g;
          while (i < len && j >= 0) {
            ans.push_back(matrix[i][j]);
            i++;
            j--;
          }
        } else {
          int j = bre - 1, i = g - bre + 1;
          while (i < len && j >= 0) {
            ans.push_back(matrix[i][j]);
            i++;
            j--;
          }
        }
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<vector<int>> matrix = stringToIntegerVectorVector(line);
    vector<int> res = Solution().findDiagonalOrder(matrix);
    for(int val: res) {
      cout << val << " ";
    }
    cout << endl;
  }
}
