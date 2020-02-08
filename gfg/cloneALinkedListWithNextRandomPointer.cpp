#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;
  Node *rand;

  Node(int val, Node *next = nullptr, Node *rand = nullptr)
      : value(val), next(next), rand(rand) {}
};

Node *createCopy(Node **head) {
  Node *ptr = *head;

  while (ptr != nullptr) {
    Node *temp = new Node(ptr->value, ptr->next);
    ptr->next = temp;
    ptr = ptr->next->next;
  }

  ptr = *head;

  while (ptr != nullptr) {
    ptr->next->rand = ptr->rand->next;
    ptr = ptr->next->next;
  }

  ptr = *head;
  Node *head2 = ptr->next;
  ptr->next = ptr->next->next;
  Node *ptr2 = head2;

  while (ptr2->next != nullptr) {
    ptr->next = ptr2->next;
    ptr = ptr->next;
    ptr2->next = ptr->next;
    ptr2 = ptr2->next;
  }

  ptr->next = nullptr;
  ptr2->next = nullptr;
  return head2;
}

Node *createLL(vector<pair<int, int>> &arr) {
  Node *head = nullptr;
  Node *ptr = nullptr;

  unordered_map<int, Node *> umap;
  for (int i = arr.size() - 1; i >= 0; i--) {
    Node *temp = new Node(arr[i].first);
    umap.insert(make_pair(i, temp));
  }
  umap.insert(make_pair(arr.size(), nullptr));

  for (int i = 0; i < arr.size(); i++) {
    if (i == 0) {
      head = ptr = umap[i];
    }
    ptr->next = umap[i + 1];
    ptr->rand = umap[arr[i].second];
    ptr = ptr->next;
  }
  return head;
}

void display(Node *head) {
  while (head) {
    cout << head->value << ", " << head->rand->value << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char **argv) {
  vector<pair<int, int>> arr = {{1, 2}, {2, 0}, {3, 4}, {4, 2}, {5, 1}};

  Node *head = createLL(arr);
  display(head);
  Node *head2 = createCopy(&head);
  display(head);
  display(head2);
}