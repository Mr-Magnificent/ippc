#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr) {
      fast = fast->next;
      while (fast != nullptr && fast->val == slow->val) {
        // ListNode *t = fast;
        fast = fast->next;
        // delete t;
      }

      slow->next = fast;
      slow = fast;
    }
    return head;
  }
};