#include "../lib/createList.hpp"
using namespace std;

class Solution {
    int lenLL(ListNode *head) {
        int count = 0;
        for(; head != nullptr; head = head->next, ++count);
        return count;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = lenLL(root);

        int slen = len / k;
        int mdk = len % k;
        vector<ListNode *> nodes(k, nullptr);

        ListNode **ptr = &root;
        int j = 0;
        while (len != 0) {
            nodes[j] = *ptr;
            for(int i = 1; i <= slen; ++i, ptr = &(*ptr)->next, len--);

            if (mdk > 0) {
                ptr = &(*ptr)->next;
                len--; mdk--;
            }
            
            root = *ptr;
            *ptr = nullptr;
            ptr = &root;
            j++;
        }

        return nodes;
    }
};
