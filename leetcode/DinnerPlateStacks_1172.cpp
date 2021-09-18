#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
  vector<stack<int>> stk;
  priority_queue<int, vector<int>, greater<int>> q;
  int capacity;

public:
  DinnerPlates(int capacity) {
    this->capacity = capacity;
    stk.emplace_back(stack<int>());
    q.push(0);
  }

  void push(int val) {
    while (!q.empty() && q.top() >= stk.size()) {
      q.pop();
    }

    if (q.size() == 0 || stk[q.top()].size() == capacity) {
      stk.emplace_back(stack<int>());
      q.push(stk.size() - 1);
    }

    while (stk[q.top()].size() == capacity) q.pop();

    stk[q.top()].push(val);
  }

  int pop() {
    while (!stk.empty() && stk[stk.size() - 1].size() == 0) {
      stk.pop_back();
    }

    if (stk.size() == 0)
      return -1;

    stack<int> &lstk = stk[stk.size() - 1];

    int temp = lstk.top();
    lstk.pop();

    return temp;
  }

  int popAtStack(int index) {
    if (index >= stk.size())
      return -1;

    if (stk[index].size() == 0)
      return -1;

    int temp = stk[index].top();
    stk[index].pop();

    q.push(index);
    return temp;
  }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

int main() {
  vector<string> operations = {
      "DinnerPlates", "push", "push", "push",       "push",       "push",
      "popAtStack",   "push", "push", "popAtStack", "popAtStack", "pop",
      "pop",          "pop",  "pop",  "pop"};
  vector<vector<int>> vals = {{2},  {1}, {2}, {3}, {4}, {5}, {0}, {20},
                              {21}, {0}, {2}, {},  {},  {},  {},  {}};

  DinnerPlates *obj;

  for (int i = 0; i < operations.size(); ++i) {
    if (!operations[i].compare("DinnerPlates")) {
      obj = new DinnerPlates(vals[i][0]);
    } else if (!operations[i].compare("push")) {
      obj->push(vals[i][0]);
    } else if (!operations[i].compare("pop")) {
      int param = obj->pop();
      cout << param << endl;
    } else if (!operations[i].compare("popAtStack")) {
      int param = obj->popAtStack(vals[i][0]);
      cout << param << endl;
    }
  }
}