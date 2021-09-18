#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

Node *mergeLL(Node *l1, Node *l2) {
    Node *head = new Node(0);
    Node *tail = head;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 == nullptr) {
        tail->next = l2;
    } else {
        tail->next = l1;
    }

    return head->next;
}

void sort(Node **head)
{
    Node *head1 = new Node (0);
    Node *tail1 = head1;
    Node *head2 = new Node(0);
    Node *tail2 = head2;

    Node *ptr = *head;
    bool toggle = true;
    while (ptr != nullptr) {
        if (toggle) {
            tail1->next = ptr;
            tail1 = tail1->next;
        } else {
            tail2->next = ptr;
            tail2 = tail2->next;
        }
        ptr = ptr->next;
        toggle = !toggle;
    }

    tail1->next = tail2->next = nullptr;
    ptr = mergeLL(head1->next, head2->next);
    head = &ptr;
}