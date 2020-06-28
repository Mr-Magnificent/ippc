#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    queue<tuple<string, int, int>> que;
    pair<int, int> minDel = getMin(s);
    que.emplace(s, minDel.first, minDel.second);
    unordered_set<string> hs;

    int total = minDel.first + minDel.second;

    while (total != -1) {
      int size = que.size();
      while (size--) {
        auto [remStr, left, right] = que.front();
        que.pop();

        if (total == 0) {
          if (!hs.count(remStr) && isValid(remStr)) {
            // cout << remStr << endl;
            hs.insert(remStr);
            continue;
          }
          continue;
        }

        for (int i = 0; i < remStr.size(); ++i) {
          if (remStr[i] == '(' && left != 0) {
            string temp = remStr.substr(0, i) + remStr.substr(i + 1);
            que.emplace(temp, left - 1, right);
          } else if (remStr[i] == ')' && right != 0) {
            string temp = remStr.substr(0, i) + remStr.substr(i + 1);
            que.emplace(temp, left, right - 1);
          }
        }
      }
      total -= 1;
    }

    vector<string> sol;
    for (string str : hs) {
      sol.push_back(str);
    }
    return sol;
  }

  bool isValid(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
      if (str[i] == '(')
        count++;
      else if (str[i] == ')')
        count--;

      if (count < 0)
        return false;
    }
    return count == 0;
  }

  pair<int, int> getMin(string s) {
    pair<int, int> del{0, 0};

    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(')
        count++;
      else if (s[i] == ')') {
        if (count == 0) {
          del.second++;
        } else {
          count--;
        }
      }
    }
    del.first = count;
    return del;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<string> ans = Solution().removeInvalidParentheses(line);
    for (string str : ans)
      cout << str << " ";
    cout << endl;
  }
}