#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         return intToLL(llToNumber(l1) + llToNumber(l2));
//     }

//     int llToNumber(ListNode* head) {
//         int num = 0;
//         for(int mul = 1; head != nullptr; head = head->next, mul *= 10) {
//             num = num + head->val * mul;
//         }
//         return num;
//     }

//     ListNode* intToLL(int num) {
//         ListNode* head = new ListNode();
//         if (num == 0) return head;

//         ListNode* ptr = head;
//         for(; num != 0; num /= 10, ptr = ptr->next;) {
//             int temp = num % 10;
//             ptr->next = new ListNode(temp);
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* ptr = head;

        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ptr->next = new ListNode(sum % 10);
            carry = sum / 10;
            ptr = ptr->next;
        }

        if (carry) {
            ptr->next = new ListNode(1);
        }
        
        return head;
    }
};