#include "../lib/createList.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode **ptr = &head;
    ListNode **fwd;

    while (*ptr != nullptr) {
      // save
      // process
      fwd = &head;
      while (*fwd != *ptr && (*fwd)->val <= (*ptr)->val) {
        fwd = &(*fwd)->next;
      }

      // link
      ListNode *t = *ptr;
      *ptr = (*ptr)->next;

      t->next = *fwd;
      *fwd = t;

      // move
      if (*ptr == *fwd) {
          ptr = &(*ptr)->next;
      }
    }

    return head;
  }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToIntLinkedList(line);
        cout << linkedListToString(Solution().insertionSortList(head)) << endl;
    }
}