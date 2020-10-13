#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int arr[52] = {};
        int mask = ~(1 << 5);
        for(int i = 0; i < s.length(); ++i) {
            int idx = ((s[i] & mask) - 'A') + ((s[i] & ~mask) != 0) * 26;
            arr[idx]++;
        }

        bool single = false;
        int count = 0;
        for(int i = 0; i < 52; ++i) {;
            single = 1 * (arr[i] % 2 == 1) + single;
            count += (arr[i] / 2) * 2;
        }

        return count + single;
    }
};