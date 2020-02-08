#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int i = S.length() - 1, j = T.length() - 1;
    int back = 0;
    while (true) {
      for (; i >= 0 && (back || S[i] == '#'); i--) {
        back += S[i] == '#' ? 1 : -1;
      }

      back = 0;
      for (; j >= 0 && (back || T[j] == '#'); j--) {
        back += T[i] == '#' ? 1 : -1;
      }

      if (i >= 0 && j >= 0 && S[i] != T[j]) {
        return false;
      }
      if (i == -1 && j == -1) break;
      if (i >= 0 && j >= 0 && S[i] == T[j]) {
        i--; j--;
      };
    }
    return true;
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  string s = "xywrrmp";
  string t = "xywrrmu#p";
  cout << sol->backspaceCompare(s, t) << "\n";
}