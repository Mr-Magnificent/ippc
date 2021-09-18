#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *reverse(ListNode *node) {
    ListNode *prev, *curr, *next;

    prev = nullptr, curr = node, next = node;
    while(curr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void fold(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head, *prev;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    if (!head->next) return;
    
    if (fast) {
        slow = slow->next;
        prev = prev->next;
    }

    prev->next = nullptr;

    slow = reverse(slow);

    ListNode *ptr = head;
    while(ptr && slow) {
        ListNode *next = ptr->next;
        ListNode *temp = slow->next;
        ptr->next = slow;
        slow->next = next;

        ptr = next, slow = temp;
    }
    
    return;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}