#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int gmax = 0;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(')
        stk.push(i);

      else if (stk.top() != -1 && s[stk.top()] == '(') {
        stk.pop();
        gmax = max(gmax, i - stk.top());
      }
      else {
        stk.push(i);
      }
    }
    return gmax;
  }
};

int main(int argc, char** argv) {
  Solution *sol = new Solution();
  cout << sol->longestValidParentheses("())");
  cout << "\n";
}
