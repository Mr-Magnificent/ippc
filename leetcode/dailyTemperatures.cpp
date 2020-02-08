#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    int len = t.size();

    vector<int> sol(len);
    stack<int> stk;

    for (int i = 0; i < len; i++) {
      while (!stk.empty() && t[stk.top()] < t[i]) {
        sol[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    return sol;
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> ans = sol->dailyTemperatures(temp);
  for (int ele: ans) {
    cout << ele << " ";
  }
  cout << endl;
}