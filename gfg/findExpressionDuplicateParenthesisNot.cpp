#include <bits/stdc++.h>
using namespace std;

bool findDuplicate(string s) {
  stack<char> stk;

  for (char ch : s) {
    if (ch == ')') {
      if (stk.top() == '(')
        return true;
      while (stk.top() != '(')
        stk.pop();
      stk.pop();
    } else {
      stk.push(ch);
    }
  }
  return false;
}

int main(int argc, char **argv) {
  string s = "((a+b)+((c+d)))";
  cout << "Contains duplicate?: " << findDuplicate(s) << endl;
}