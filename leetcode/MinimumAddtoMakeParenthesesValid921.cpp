#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string S) {
    stack<char> stk;
    for (char ch : S) {
      if (!stk.empty() && stk.top() == '(' && ch == ')')
        stk.pop();
      else
        stk.push(ch);
    }
    return stk.size();
  }
};

int main() {
  Solution *sol = new Solution();
  cout << sol->minAddToMakeValid("()))((");
  cout << endl;
}