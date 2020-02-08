#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;

  Node(int val, Node *ptr = nullptr) : value(val), next(ptr) {}
};

Node *createLL(vector<int> &arr) {
    Node *head, *ptr;
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

Node *findNode(Node *head, int k) {
  Node *temp = nullptr, *ptr = head;

  while (ptr) {
    if (ptr->value %  k == 0) {
      temp = ptr;
    }
    ptr = ptr->next;
  }
  return temp;
}

int main(int argc, char **argv) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = createLL(arr);

  Node* node = findNode(head, 3);

  cout << node->value << endl;
}