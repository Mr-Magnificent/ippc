#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    vector<int> sol(T.size());
    stack<int> stk;
    for (int i = T.size() - 1; i >= 0; i--) {
      while (!stk.empty() && T[stk.top()] < T[i])
        stk.pop();
      sol[i] = stk.top();
      stk.push(i);
    }
    return sol;
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> ans = sol->dailyTemperatures(arr);
  for (int el : ans)
    cout << el << " ";
  cout << endl;
}