#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<string> stk;

    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '[') {
        string temp = "";
        while (stk.top() != "]") {
          temp += stk.top();
          stk.pop();
        }
        stk.pop();
        int reps = s[i - 1] - '0';
        string toAdd = "";
        while (reps--) {
          toAdd += temp;
        }
        stk.push(toAdd);
        i--;
      } else {
        stk.push(string(1, s[i]));
      }
    }
    string sol = "";
    while (!stk.empty()) {
      sol += stk.top();
      stk.pop();
    }
    return sol;
  }
};

int main(int args, char **argv) {
  Solution *sol = new Solution();
  cout << sol->decodeString("2[2[abc]3[cd]ef]") << "\n";
}