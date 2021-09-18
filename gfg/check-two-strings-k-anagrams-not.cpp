#include <bits/stdc++.h>
using namespace std;

bool areKAnagrams(string str1, string str2, int k) {
  unordered_map<char, int> s1;
  unordered_map<char, int> s2;

  for (auto ch : str1)
    s1[ch]++;

  for (auto ch : str2)
    s2[ch]++;

  int sum = 0;

  for (auto item : s1) {
    if (s2.find(item.first) == s2.end()) {
      sum += item.second;
    } else if (s2[item.first] < item.second) {
      sum += (item.second - s2[item.first]);
    }
  }

  return sum <= k;
}

int main(int argc, char **argv) {
  cout << areKAnagrams("abc", "bac", 2) << endl;
  raise(SIGSEGV);
}