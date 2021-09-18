#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* ptr;
public:
    bool isPalindrome(ListNode* head) {
        ptr = head;
        return helperPalindrome(head);
    }

    bool helperPalindrome(ListNode* node) {
        if (!node) {
            return true;
        }
        
        bool ans = helperPalindrome(node->next);
        if (!ans) return false;

        if (ptr->val != node->val) ans = false;
        ptr = ptr->next;
        return ans;
    }
};