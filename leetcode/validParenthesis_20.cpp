#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        stk.push(ch);
        continue;
      }
      if (stk.empty()) return false;
      switch (ch) {
      case '}':
        if (stk.top() != '{')
          return false;
        stk.pop();
        break;
      case ')':
        if (stk.top() != '(')
          return false;
        stk.pop();
        break;
      case ']':
        if (stk.top() != '[')
          return false;
        stk.pop();
        break;
      }
    }
    if (stk.empty())
      return true;
    return false;
  }
};