#include "../lib/createVector.hpp"
using namespace std;

class Solution {
public:
  string countOfAtoms(string formula) {
    int multiplier = 1;
    map<string, int> atomsCount;

    stack<int> mulHist;

    // iterate over the string
    int idx = formula.length() - 1;
    while (idx >= 0) {
      // if char == ( then divide the multiplier with stack top
      if (formula[idx] == '(') {
        multiplier /= mulHist.top();
        mulHist.pop();
        idx--;
        continue;
      }

      // aggressively try to get the integer for multiplier
      int atomicMul = 1;
      int dig = 0;
      int ch = formula[idx] - '0';
      while (ch >= 0 && ch < 10) {
        ch = formula[idx--] - '0';
        dig += ch * atomicMul;
        atomicMul *= 10;
        ch = formula[idx] - '0';
      }

      if (dig != 0)
        multiplier *= dig;

      if (formula[idx] == ')') {
        if (dig == 0) {
          mulHist.push(1);
        } else {
          mulHist.push(dig);
        }
      } else {
        // aggressibely try to get the atom
        string atom = "";
        while (formula[idx] >= 'a' && formula[idx] <= 'z') {
          atom = formula[idx--] + atom;
        }
        atom = formula[idx] + atom;
        atomsCount[atom] += multiplier;
        if (dig != 0) {
          multiplier /= dig;
        }
      }
      idx--;
    }

    string ans = "";
    for (auto item : atomsCount) {
      ans += item.first;
      if (item.second > 1) {
        ans = ans + to_string(item.second);
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    cout << Solution().countOfAtoms(line) << endl;
  }
}