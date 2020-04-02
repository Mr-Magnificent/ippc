#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // bool comparator(const pair<int, char> &first, const pair<int, char>
  // &second) {
  //   if (first.first == second.first) {
  //     return first.second < second.second;
  //   }
  //   return first.first > second.first;
  // }
  struct Node {
    char ch;
    array<int, 26> arr{};

    Node(char ch) : ch(ch) {}
  };

  static bool comparator(const Node *first, const Node *second) {
    for (int i = 0; i < 26; i++) {
      if (first->arr[i] > second->arr[i]) {
        return true;
      }
    }
    if (first->ch < second->ch) {
      return true;
    }
    return false;
  }

  string rankTeams(vector<string> &votes) {
    vector<Node *> arr;
    int length = votes[0].length();

    for (int i = 0; i < 26; i++) {
      arr.push_back(new Node((char)(i + 'A')));
    }

    for (string &vote : votes) {
      for (int i = 0; i < length; i++) {
        arr[vote[i] - 'A']->arr[i]++;
      }
    }

    // iterate over the length of the string and find for the top element
    sort(arr.begin(), arr.end(), comparator);

    string ans = "";
    for (int i = 0; i < length; i++) {
      ans += arr[i]->ch;
    }
    return ans;
  }
};


int main(int argc, char **argv) {
  int n;
  cin >> n;
  vector<string> votes;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    votes.push_back(str);
  }

  cout << Solution().rankTeams(votes) << endl;
}