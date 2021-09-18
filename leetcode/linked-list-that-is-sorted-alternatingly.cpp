#include <bits/stdc++.h>
using namespace std;

// Structure of Node of the linked list is as
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

// your task is to complete this function
void sort(Node **head) {
  Node *head1 = new Node(0);
  Node *tail1 = head1;
  // Code here
  while (*head != nullptr && (*head)->next != nullptr) {
    tail1->next = *head;
    *head = (*head)->next;
  }

  tail1->next = *head;
  *head = head1->next;
}
