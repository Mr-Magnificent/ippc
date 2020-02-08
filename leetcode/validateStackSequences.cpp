#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk;
    int i = 0, j = 0;
    int len = pushed.size();

    for (int ele: pushed) {
      stk.push(ele);
      while (!stk.empty() && stk.top() == popped[j]) {
        stk.pop();
        j++;
      }
    }
    return j == popped.size();
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  vector<int> pushed = {1,2,3,4,5};
  vector<int> popped = {4,3,5,1,2};
  cout << sol->validateStackSequences(pushed, popped) << "\n";
}