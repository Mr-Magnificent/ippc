#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> comp;
        for(int i = 0; i < favoriteCompanies.size(); ++i) {
            for(int j = 0; j < favoriteCompanies[i].size(); ++j) {
                if (comp.find(favoriteCompanies[i][j]) == comp.end()) {
                    comp[favoriteCompanies[i][j]] = i;
                } else {
                    comp.erase(favoriteCompanies[i][j]);
                }
            }
        }

        unordered_set<int> indxes
    }
};