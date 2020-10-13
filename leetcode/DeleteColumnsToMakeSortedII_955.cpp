#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rangeDeletion(vector<string>& a, int si, int ei, int ci, vector<bool>& mark) {
        if (ci == a[0].length()) return 0;

        int count = 0;
        bool validPos = true;
        char ch = a[si][ci];
        for(int i = si; i <= ei; ++i) {
            if (a[i][ci] < ch) {
                validPos = false;
                break;
            }
            ch = a[i][ci];
        }

        if (!validPos) {
            mark[ci] = true;
            return 1 + rangeDeletion(a, si, ei, ci + 1, mark);
        }

        ch = a[si][ci];
        int len = 1;
        for(int i = si + 1; i <= ei; ++i) {
            if (a[i][ci] == ch) {
                len++;
            } else {
                count += (len > 1)? rangeDeletion(a, i - len, i - 1, ci + 1, mark): 0;
                ch = a[i][ci];
                len = 1;
            }
        }
        count += (len > 1) ? rangeDeletion(a, ei - len + 1, ei, ci + 1, mark): 0;
        return count;
    }

public:
    int minDeletionSize(vector<string>& A) {
        vector<bool> mark(A.size(), false);
        rangeDeletion(A, 0, A.size() - 1, 0, mark);
        int count = 0;
        for(int i = 0; i < mark.size(); ++i) {
            count += mark[i];
        }
        return count;
    }
};