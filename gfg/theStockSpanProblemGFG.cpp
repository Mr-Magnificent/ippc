#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      arr[i] = temp;
    }
    stack<int> stk;
    vector<int> sol(n);

    for (int i = 0; i < n; i++) {
      while (!stk.empty() && arr[stk.top()] < arr[i]) {
        stk.pop();
      }

      int top = stk.empty() ? -1 : stk.top();
      sol[i] = i - top;
      stk.push(i);
    }

    for (int el : sol)
      cout << el << " ";
    cout << endl;
  }
}