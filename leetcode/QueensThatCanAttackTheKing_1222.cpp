#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<vector<int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<string> queenSet;
        queenSet.reserve(queens.size());

        for(vector<int> &v: queens) {
            string hash = to_string(v[0]) + to_string(v[1]);
            queenSet.emplace(hash);
        }

        vector<vector<int>> ans;
        ans.reserve(8);

        for(int i = 0; i < dir.size(); ++i) {
            int r = king[0];
            int c = king[1];

            while (r <= 8 && c <= 8 && r >= 0 && c >= 0) {
                string hash = to_string(r) + to_string(c);
                if (queenSet.count(hash) == 1) {
                    vector<int> temp {r, c};
                    ans.emplace_back(temp);
                    break;
                }

                r += dir[i][0];
                c += dir[i][1];
            }
        }

        return ans;
    }
};
