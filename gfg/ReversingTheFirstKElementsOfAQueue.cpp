#include <bits/stdc++.h>
using namespace std;

#define ll long long

queue<ll> modifyQueue(queue<ll> q, int k) {
  int size = q.size();
  k %= size;

  stack<int> stk;
  for (int i = 0; i < k; i++) {
    stk.push(q.front());
    q.pop();
  }

  while (!stk.empty()) {
    q.push(stk.top());
    stk.pop();
  }

  for (int i = 0; i < (n - k); i++) {
    q.push(q.front());
    q.pop();
  }

  return q;
}

int main(int argc, char **argv) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    int k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      q.push(temp);
    }

    k %= n;
    stack<int> stk;
    for (int i = 0; i < k; i++) {
      stk.push(q.front());
      q.pop();
    }

    while (!stk.empty()) {
      q.push(stk.top());
      stk.pop();
    }

    for (int i = 0; i < (n - k); i++) {
      q.push(q.front());
      q.pop();
    }

    while (!q.empty()) {
      cout << q.front() << " ";
      q.pop();
    }
    cout << endl;
  }
}