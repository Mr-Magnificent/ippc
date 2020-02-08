#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;

  Node(int val) : value(val) {}
};

Node *createLL(vector<int> &arr) {
  Node *head = nullptr;
  Node *ptr = nullptr;

  for (int i = 0; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    if (i == 0) {
      head = ptr = temp;
    } else {
      ptr->next = temp;
      ptr = temp;
    }
  }
  return head;
}

Node *mergeLL(Node **head1, Node **head2) {
  Node *ptr = *head1;

  while (ptr != nullptr) {
    if (*head2 == nullptr)
      break;
    Node *temp = ptr->next;
    ptr->next = *head2;
    *head2 = (*head2)->next;
    ptr->next->next = temp;
    ptr = temp;
  }

  return *head1;
}

void display(Node *head) {
  while (head) {
    cout << head->value << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char **argv) {
  vector<int> LL1 = {1, 2, 3, 4};
  vector<int> LL2 = {4, 5, 6, 7, 8};

  Node *head1 = createLL(LL1);
  Node *head2 = createLL(LL2);

  Node *res = mergeLL(&head1, &head2);
  display(head2);
}