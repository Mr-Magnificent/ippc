#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  int num = 1;
  stack<int> stk;
  string S = "((())(()))";

  for (char ch : S) {
    if (ch == '(') {
      stk.push(num);
      cout << num++;
    }
    
    else if (ch == ')') {
      cout << stk.top();
      stk.pop();
    }
  }
}