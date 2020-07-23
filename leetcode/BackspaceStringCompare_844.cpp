#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string a, string b) {
    int i = a.length() - 1, j = b.length() - 1;
    int hc1 = 0, hc2 = 0; // hashcount
    while (i >= 0 && j >= 0) {
        if (a[i] == '#') {
            hc1++;
            i--;
            continue;
        }
        
        if (b[j] == '#') {
            hc2++;
            j--;
            continue;
        }
        
        if (hc1 > 0) {
            i--;
            hc1--;
            continue;
        }
        
        if(hc2 > 0) {
            j--;
            hc2--;
            continue;
        }
        
        if (a[i] != b[j]) {
            return false;
        }
        i--;
        j--;
    }
    
    while (i >= 0) {
        if (a[i] == '#') hc1++;
        else hc1--;
        
        if (hc1 < 0) return false;
        i--;
    }
    
    while (j >= 0) {
        if (b[j] == '#') hc2++;
        else hc2--;
        
        if (hc2 < 0) return false;
        j--;
    }
    
    return true;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
      string a = line;
      getline(cin, line);
      string b = line;
      cout << Solution().backspaceCompare(a, b) << endl;
  }
}
