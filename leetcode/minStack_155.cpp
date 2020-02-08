#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  vector<long> stk;
  long min;
  MinStack() {}

  void push(int x) {
    if (stk.empty()) {
      min = x;
    }

    stk.push_back(x - min);
    if (x < min) {
      min = x;
    }
  }

  void pop() {
    if (stk.back() < 0) {
      min = min - stk.back();
    }
    stk.pop_back();
  }

  int top() {
    long ele = stk.back();
    if (ele < 0) {
      return min;
    }
    return ele + min;
  }

  int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char **argv) {
  MinStack *obj = new MinStack();
  obj->push(2147483646);
  obj->push(2147483646);
  obj->push(2147483647);
  cout << obj->top() << "\n";
  obj->pop();
  cout << obj->getMin() << "\n";
  obj->pop();
  cout << obj->getMin() << "\n";
  obj->pop();
  obj->push(2147483647);
  cout << obj->top() << "\n";
  cout << obj->getMin() << "\n";
  obj->push(-2147483648);
  cout << obj->top() << "\n";
  cout << obj->getMin() << "\n";
  obj->pop();
  cout << obj->getMin() << "\n";
}