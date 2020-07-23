#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> invalid;
    invalid.reserve(deadends.size());

    for (int i = 0; i < deadends.size(); ++i) {
      invalid.insert(deadends[i]);
    }

    queue<string> que;
    que.push("0000");

    int ans = 0;
    bool found = false;
    while (!que.empty()) {
      int size = que.size();
      ans++;
      while (size-- > 0) {
        string code = que.front();
        que.pop();
        cout << code << endl;
        if (invalid.find(code) != invalid.end()) {
          continue;
        }

        invalid.insert(code);

        if (code == target) {
          found = true;
          break;
        }

        for (int i = 0; i < 4; ++i) {
          string a{code};
          string b{code};

          a[i] = '0' + (code[i] - '0' + 1) % 10;
          b[i] = '0' + (code[i] - '0' - 1 + 10) % 10;

          if (invalid.find(a) == invalid.end()) {
            que.push(a);
          }
          
          if (invalid.find(b) == invalid.end()) {
            que.push(b);
          }
        }
      }

      if (found == true) {
        break;
      }
    }

    if (!found)
      return -1;
    return ans - 1;
  }
};