#include "../lib/createList.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
  ListNode *findMid(ListNode *node) {
    ListNode **slow = &node, *fast = node;
    while (fast && fast->next) {
      slow = &(*slow)->next;
      fast = fast->next->next;
    }

    ListNode *t = *slow;
    *slow = nullptr;
    return t;
  }

  ListNode *mergeList(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (l1 && l2) {
      // save
      // link
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      // move
      tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    ListNode *t = dummy->next;
    delete dummy;
    return t;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *mid = findMid(head);
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(mid);

    return mergeList(l1, l2);
  }
};

int main() {
  string line;
  while(getline(cin, line)) {
    ListNode *head = stringToIntLinkedList(line);
    cout << linkedListToString(Solution().sortList(head)) << endl;
  }
}