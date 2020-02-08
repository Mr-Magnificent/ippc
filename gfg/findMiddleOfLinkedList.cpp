#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;

  Node(int value, Node *ptr = nullptr) : value(value), next(ptr) {}
};

Node *createLL(vector<int> &arr) {
  Node *head = nullptr, *ptr;

  for (int i = 0; i < arr.size(); i++) {
    if (i == 0) {
      head = ptr = new Node(arr[0]);
    } else {
      ptr->next = new Node(arr[i]);
      ptr = ptr->next;
    }
  }
  return head;
}

Node *findMidNode(Node *head) {
  Node *fast = head, *slow = head;

  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}

int main(int argc, char **argv) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = createLL(arr);
  Node *node = findMidNode(head);
  cout << node->value << endl;
}