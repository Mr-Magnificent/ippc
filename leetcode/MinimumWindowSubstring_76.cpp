#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> tMap;
    int tLen = t.length();

    for (char ch : t) {
      tMap[ch]++;
    }

    int start = 0;
    int startIdx = 0;
    int endIdx = -1;

    int matchedCount = 0;

    unordered_map<char, int> sMap;

    int sLength = s.length();
    for (int i = 0; i < sLength; i++) {
      char curCh = s[i];
      char stCh = s[start];

      if (tMap.find(curCh) != tMap.end()) {
        sMap[curCh]++;

        if (sMap[curCh] <= tMap[curCh]) {
          matchedCount++;
        }

        while (tMap.find(stCh) == tMap.end() || sMap[stCh] > tMap[stCh]) {
          if (sMap.find(stCh) != sMap.end()) {
            sMap[stCh]--;
          }

          start++;
          stCh = s[start];
        }
      }

      if (matchedCount == tLen) {
        if (endIdx == -1 || (i - start) < (endIdx - startIdx)) {
          endIdx = i;
          startIdx = start;
        }
      }
    }

    if (startIdx != -1) {
      return s.substr(startIdx, (endIdx - startIdx + 1));
    }

    return "";
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    string s = line.substr(1, line.length() - 2);
    getline(cin, line);
    string t = line.substr(1, line.length() - 2);

    cout << Solution().minWindow(s, t) << endl;
  }
}