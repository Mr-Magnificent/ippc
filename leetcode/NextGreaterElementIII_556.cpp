#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        long rev = 0;
        bool found = false;
        for(long div = 1; n / div > 0; div *= 10) {
            int dig = ((n % (div * 10)) / div);
            if (dig < (rev % 10)) {
                found = true;
                for(int mul = 1; mul < div; mul *= 10) {
                    int dig2 = ((n % (mul * 10)) / mul);
                    if (dig < dig2) {
                        n -= ((dig * div) + (dig2 * mul));
                        n += (dig2 * div);
                        rev = rev - (dig2 * mul) + (dig * mul);
                        n = (n / div) * div + rev;
                        break;
                    }
                }
                break;
            }
            rev = rev * 10 + dig;
        }
        if (!found) return -1;
        return n;
    }
};

class Solution {
public:
    int nextGreaterElement(int n) {

    }
};