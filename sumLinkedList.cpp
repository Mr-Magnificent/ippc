#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int ele, ListNode *next): val(ele), next(next){}
};

class Solution {
    ListNode* itr;
    int k = 0;
    int itrCount = 0;
    public:
    void sumList(ListNode *head) {
        itr = head;
        helper(head);
        // cout << k << " " << itrCount;
    }

    void helper(ListNode *node) {
        if (node == nullptr) {
            return;
        }
        k++;
        helper(node->next);

        if (itrCount >= (k / 2)) return;

        int sum = itr->val + node->val;
        node->val = sum;
        itr->val = sum;
        itr = itr->next;
        itrCount++;
    }
};

ListNode *createList(vector<int>& arr) {
    ListNode *head = nullptr;
    ListNode *itr = nullptr;
    for(int i = 0; i < arr.size(); ++i) {
        ListNode* temp = new ListNode(arr[i], nullptr);
        if (i == 0) itr = head = temp;
        else {
            itr->next = temp;
            itr = itr->next;
        }
    }

    return head;
}

void showList(ListNode* head) {
    for(; head != nullptr; head = head->next)
        cout << head->val << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3};
    ListNode *head = createList(arr);
    Solution().sumList(head);
    showList(head);
}