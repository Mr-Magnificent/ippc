#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1) return "";

        if (palindrome[0] == 'a') palindrome[len - 1] = 'b';
        else palindrome[0] = 'a';

        return palindrome;
    }
};