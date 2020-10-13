#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int counter = 0;

        for(int i = 0; i < s.length(); ++i) {
            count += 1 * (s[i] == 'R') - 1 * (s[i] == 'L');
            counter += count == 0;
        }

        return counter;
    }
};