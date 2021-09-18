#include "../lib/createList.hpp"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *tail1 = dummy1;

        ListNode *dummy2 = new ListNode(-1);
        ListNode *tail2 = dummy2;

        ListNode *itr = head;
        while (itr != nullptr) {
            // save
            // ListNode *next = itr->next;

            // link
            if (itr->val % 2 == 0) {
                tail1->next = itr;
                tail1 = itr;
            } else {
                tail2->next = itr;
                tail2 = itr;
            }

            // move
            itr = itr->next;
        }

        tail1->next = tail2->next = nullptr;

        tail1->next = dummy2->next;
        ListNode *t = dummy1->next;
        delete dummy1;
        delete dummy2;

        return t;
    }
};