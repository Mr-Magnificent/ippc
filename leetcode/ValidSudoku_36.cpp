#include "../lib/createVectorTemplate.hpp"
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    array<int, 9> rowB;
    array<int, 9> colB;
    array<array<int, 3>, 3> squareB;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] != '.') {
          int dig = board[i][j] - '0';
          if ((rowB[i] & (1 << dig)) != 0 || (colB[j] & (1 << dig)) != 0 || (squareB[i / 3][j / 3] & (1 << dig)) != 0) {
            return false;
          }

          rowB[i] |= (1 << (board[i][j] - '0'));
          colB[j] |= (1 << (board[i][j] - '0'));
          squareB[i / 3][j / 3] |= (1 << (board[i][j] - '0'));
        }
      }
    }

    return true;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<vector<char>> board = stringToTypeVectorVector<char>(line);
    cout << Solution().isValidSudoku(board) << endl;
  }
}