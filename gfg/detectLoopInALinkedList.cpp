#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

int detectloop(Node *head) {
  // your code here
  Node *slow, *fast;
  slow = fast = head;

  while(fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
          return true;
      }
  }
  return false;
}

int main(int argc, char **argv) {}