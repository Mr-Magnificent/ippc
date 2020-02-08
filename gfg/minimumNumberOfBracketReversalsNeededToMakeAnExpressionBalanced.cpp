#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  string expression = "}{{}}{{{";
  stack<char> stk;

  for (char ch : expression) {
    if (!stk.empty() && stk.top() == '{' && ch == '}')
      stk.pop();
    else 
      stk.push(ch);
  }

  int opcount = 0;
  int endcount = 0;

  while (!stk.empty()) {
    if (stk.top() == '{') opcount++;
    else endcount++;
    stk.pop();
  }

  int ans = 0;
  int sum = opcount % 2 + endcount % 2;
  switch (sum) {
    case 0:
      ans = opcount / 2 + endcount / 2;
      break;
    case 1:
      cout << "Ans not possible\n";
      break;
    case 2:
      ans = opcount / 2 + endcount / 2 + 2;
      break;
  }
  cout << ans;
  cout << endl;
}