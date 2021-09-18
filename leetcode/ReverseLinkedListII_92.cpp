#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode **slow = &head;
        ListNode *fast = head;

        for (int i = 1; i < left; ++i) {
            slow = &(*slow)->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = *slow;
        ListNode *next = *slow;

        for(int i = left; i <= right; ++i) {
            next = next->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        ListNode *t = *slow;
        *slow = prev;
        t->next = curr;

        return head;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToIntLinkedList(line);
        int l, r;
        getline(cin, line);
        l = stoi(line);
        getline(cin, line);
        r = stoi(line);
        cout << linkedListToString(Solution().reverseBetween(head, l, r)) << endl;
    }
}