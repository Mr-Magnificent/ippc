#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;

  node(int x) {
    data = x;
    next = NULL;
  }
} * head;

struct node *reverse(struct node *head, int k) {
  // Complete this method
  if (head == NULL) {
    return NULL;
  }

  struct node *temp = head;
  struct node *curr = head, *prev = NULL;

  for (int i = 0; i < k && curr != NULL; i++) {
    struct node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  temp->next = reverse(curr, k);
  return prev;
}

void createLL(vector<int> &ll) {
  if (ll.empty()) {
    head = NULL;
    return;
  }
  struct node *itr = head = new struct node(ll[0]);

  for (int i = 1; i < ll.size(); i++, itr = itr->next) {
    itr->next = new struct node(ll[i]);
  }
}

void printLL() {
  struct node *ptr = head;
  while (ptr != NULL) {
    cout << ptr->data << " -> ";
    ptr = ptr->next;
  }
  cout << endl;
}

int main(int argc, char **argv) {
  vector<int> ll = {1, 2, 3, 4, 5, 6, 7, 8};
  createLL(ll);

  printLL();
  head = reverse(head, 3);
  printLL();
}