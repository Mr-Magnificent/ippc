#include "../lib/createList.hpp"
using namespace std;

class Solution {
  ListNode *reverseNodes(ListNode *head, ListNode *limit) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head;

    while (curr != limit) {
      next = next->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode **slow = &head;
    ListNode *fast = head;

    while (fast != nullptr) {
      // move fast
      int i;
      for (i = 1; i <= k && fast != nullptr; ++i, fast = fast->next);
      if (i != k + 1) break;

      // link
      ListNode *t = *slow;
      *slow = reverseNodes(*slow, fast);
      t->next = fast;

      // set slow
      slow = &t->next;
    }
    return head;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    ListNode *head = stringToIntLinkedList(line);
    getline(cin, line);
    int k = stoi(line);
    cout << linkedListToString(Solution().reverseKGroup(head, k)) << endl;
  }
}