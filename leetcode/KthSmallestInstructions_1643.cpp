#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        vector<vector<int>> dp(destination[0] + 1, vector<int>(destination[1] + 1, 1));
        dp[dp.size() - 1][dp[0].size() - 1] = 0;

        for(int i = dp.size() - 2; i >= 0; --i) {
            for(int j = dp[0].size() - 2; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        
        for(int i = 0; i < dp.size(); ++i) {
            for(int j = 0; j < dp[0].size(); ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        string ans = "";
        int i = 0, j = 0;
        while (i != destination[0] || j != destination[1]) {
            if (i == dp.size() - 1) {
                j += 1;
                ans = ans + "H";
                continue;
            }
            if (j == dp[1].size() - 1) {
                i += 1;
                ans = ans + "V";
                continue;
            }

            if (k <= dp[i][j + 1]) {
                j += 1;
                ans += "H";
            } else {
                k -= dp[i][j + 1];
                i += 1;
                ans += "V";
            }
        }
        return ans;
    }
};

int main() {
    vector<int> dest(2);
    int k;
    cin >> dest[0] >> dest[1];
    cin >> k;
    cout << Solution().kthSmallestPath(dest, k) << endl;
}