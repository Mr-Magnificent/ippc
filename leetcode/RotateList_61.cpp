#include <bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    int getLength(ListNode *head) {
        int len = 0;
        for(ListNode *curr = head; curr != nullptr; curr = curr->next, len++);
        return len;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        
        int length = getLength(head);
        int tk = k % length;

        ListNode *fp = head;
        ListNode *tail = head;
        for(int i = 1; i < length - tk; ++i, fp = fp->next);
        for(; tail->next != nullptr; tail = tail->next);

        tail->next = head;
        head = fp->next;
        
        fp->next = nullptr;

        return head;
    }
};