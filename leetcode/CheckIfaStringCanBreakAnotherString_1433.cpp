#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(string s1, string s2) {
        for(int i = 0; i < s1.length(); ++i) {
                if (s2[i] < s1[i]) return false;
            }
        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 < s2) {
            return helper(s1, s2);
        } else {
            return helper(s2, s1);
        }
        return true;
    }
};