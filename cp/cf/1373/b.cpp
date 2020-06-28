#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define boost                                                                  \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i <= b; i++)

bool recur(string str, int level) {
  if (str.length() == 0) {
    if (level & 1 == 1)
      return true;
    return false;
  }

  for (int i = 0; i < str.length() - 1; ++i) {
    if (str[i] != str[i + 1]) {
      string ros = str.substr(0, i) + str.substr(i + 2);
      if (recur(ros, level + 1)) {
        return true;
      } else {
        return false;
      }
    }
  }

  if (level & 1 == 1)
    return true;
  return false;
}

int main() {
  boost;
  int t;
  cin >> t;
  cin.ignore(32767, '\n');
  while (t--) {
    string line;
    getline(cin, line);
    if (recur(line, 0)) {
      cout << "DA\n";
    } else {
      cout << "NET\n";
    }
  }
}