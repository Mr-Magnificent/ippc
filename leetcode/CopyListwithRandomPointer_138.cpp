#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node *ptr = head;

    while (ptr != nullptr) {
      Node *t = new Node(ptr->val);
      t->next = ptr->next;
      ptr->next = t;
      ptr = ptr->next->next;
    }

    ptr = head;
    while (ptr != nullptr) {
      if (ptr->random != nullptr) {
        ptr->next->random = ptr->random->next;
      } else {
        ptr->next->random = nullptr;
      }
    }

    Node *newhead = head;
    Node *tail = newhead;
    ptr = head;
    while (ptr != nullptr) {
    }
  }
};