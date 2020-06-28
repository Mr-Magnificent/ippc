#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i <= b; i++)

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, loss = 0;
    cin >> n >> k;

    REP(i, 0, n - 1) {
      int tmp;
      cin >> tmp;
      loss += (tmp > k) ? tmp - k : 0;
    }

    cout << loss << "\n";
  }
}