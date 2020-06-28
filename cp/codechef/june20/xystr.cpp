#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define boost                                                                  \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i <= b; i++)

int main() {
  boost;
  int t;
  cin >> t;
  cin.ignore(32767, '\n');
  while (t--) {
    string s;
    getline(cin, s);
    int count = 0;
    for(int i = 0; i < s.length() - 1; ++i) {
      if (s[i] != s[i + 1]) {
        count++;
        i++;
      }
    }
    cout << count << "\n";
  }
}