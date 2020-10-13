#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string comb = A + " " + B;
        istringstream sc(comb);

        unordered_map<string, int> uniqSet;
        vector<string> ans;
        string str;

        while (sc >> str) {
            uniqSet[str]++;
        }

        for(auto &temp: uniqSet) {
            if (temp.second == 1) ans.push_back(temp.first);
        }

        return ans;
    }
};