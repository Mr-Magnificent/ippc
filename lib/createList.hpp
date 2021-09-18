#pragma once
#include "./createVector.hpp"
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vectorToIntLinkedList(vector<int> &v) {
  ListNode *dummy = new ListNode(-1);
  ListNode *tail = dummy;

  for (int x : v) {
    ListNode *t = new ListNode(x);
    tail->next = t;
    tail = t;
  }

  ListNode *t = dummy->next;
  delete dummy;
  return t;
}

ListNode *stringToIntLinkedList(string inp) {
  vector<int> list = stringToIntegerVector(inp);
  return vectorToIntLinkedList(list);
}


string linkedListToString(ListNode *head) {
  string ans = "[";

  ListNode *ptr = head;
  while (ptr) {
    ans = ans + " " + to_string(ptr->val) + ",";
    // move
    ptr = ptr->next;
  }
  ans += "]";
  return ans;
}