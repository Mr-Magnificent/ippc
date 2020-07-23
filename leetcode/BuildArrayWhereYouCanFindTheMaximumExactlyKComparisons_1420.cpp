#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD 1000000007
using namespace std;

class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<int>> prev(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> curr(n + 1, vector<int>(n + 1, 0));
    
    prev[0][0] = 1;
    
    for(int val = 1; val <= m; ++i) {
        for(int diff = 1; dff <= k; ++diff) {
            for(int place = 1; place <= n; ++place) {
                if (diff == 1) {
                    //~ sum of all the previous rows because new row added
                } else {
                    curr[diff][place] = curr[diff][place - 1] * val + prev[diff - 1][place - 1];
                }
            }
        }
        
        for(int diff = 1; dff <= k; ++diff) {
            for(int place = 1; place <= n; ++place) {
                prev[diff][place] += curr[diff][place];
            }
        }
    }
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    int n = stoi(line);
    getline(cin, line);
    int m = stoi(line);
    getline(cin, line);
    int k = stoi(line);
    cout << Solution().numOfArrays(n, m, k) << endl;
  }
}
