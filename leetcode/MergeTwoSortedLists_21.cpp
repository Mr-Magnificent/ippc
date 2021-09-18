#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val = 0;
  ListNode *next = nullptr;

  ListNode(int val) { this->val = val; }
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (l1 || l2) {
        // save

        // link
      if (l1->val < l2->val) {
          tail->next = l1;
          l1 = l1->next;
      } else {
          tail->next = l2;
          l2 = l2->next;
      }

    //   move
    tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    ListNode *t = dummy->next;
    delete dummy;
    return t;
  }
};