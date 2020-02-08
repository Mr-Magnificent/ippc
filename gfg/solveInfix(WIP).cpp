#include <bits/stdc++.h>
using namespace std;

class InfixToAns {
  unordered_map<char, int> precedence;

public:
  InfixToAns() {
    precedence.insert(make_pair<char, int>('+', 1));
    precedence.insert(make_pair<char, int>('-', 1));
    precedence.insert(make_pair<char, int>('*', 2));
    precedence.insert(make_pair<char, int>('/', 2));
    precedence.insert(make_pair<char, int>('^', 3));
    precedence.insert(make_pair<char, int>('(', INT_MIN));
  }

  bool checkOperator(string s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
  }

  int solveInfix(vector<string> arr) {
    stack<char> oprtr;
    stack<int> oprnd;
    for (string s : arr) {
      if (!checkOperator(s) && s != "(") {
        oprnd.push(stoi(s));
      } else if (s == "(") {
        oprnd.push('(');
      } else {
        while (oprtr.top() != '(' || precedence[oprtr.top()] >= precedence[s[0]]) {

        }
      }
    }
  }
};

int main(int argc, char **argv) { InfixToAns *sol = new InfixToAns(); }