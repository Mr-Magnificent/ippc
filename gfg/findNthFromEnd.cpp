#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;

  Node(int value, Node *ptr = nullptr) : value(value), next(ptr) {}
};

Node *createLL(vector<int> &arr) {
  Node *head = nullptr, *ptr = nullptr;
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

Node *findNthNode(Node *head, int k) {
  Node *fast = head;
  for (int i = 0; i < k; i++) {
    if (fast == nullptr)
      return nullptr;
    fast = fast->next;
  }

  Node *slow = head;
  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

int main(int argc, char **argv) {
  vector<int> arr = {1, 2, 3};
  Node *head = createLL(arr);
  Node *node = findNthNode(head, 3);
  if (!node) { 
    cout << 0 << endl;
    return 0;
  }
  cout << node->value << endl;
}
