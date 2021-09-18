#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head;
    for (int i = 0; i < n; i++, fast = fast->next)
      ;

    ListNode **slow = &head;
    for(;fast != nullptr; fast = fast->next, slow = &(*slow)->next);

    ListNode *ptr = *slow;
    delete ptr;
    *slow = (*slow)->next;

    return head;
  }
};