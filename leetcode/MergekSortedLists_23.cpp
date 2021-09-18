#include "../lib/createList.hpp"
using namespace std;

// class Solution {
//   struct comp {
//     bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
//   };

// public:
//   ListNode *mergeKLists(vector<ListNode *> &lists) {
//     priority_queue<ListNode *, vector<ListNode *>, comp> q;

//     for (ListNode *node : lists) {
//       if (node != nullptr)
//         q.emplace(node);
//     }

//     ListNode *dummy = new ListNode(-1);
//     ListNode *tail = dummy;

//     while (!q.empty()) {
//       ListNode *t = q.top();
//       q.pop();

//       tail->next = t;
//       tail = t;

//       if (t->next != nullptr) {
//         q.push(t->next);
//       }
//     }

//     ListNode *t = dummy->next;
//     delete dummy;
//     return t;
//   }
// };

class Solution {
  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (l1 != nullptr && l2 != nullptr) {
      // link
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }

      // move
      tail = tail->next;
    }

    tail->next = (l1 == nullptr) ? l2 : l1;
    ListNode *t = dummy->next;
    delete dummy;
    return t;
  }

  ListNode *mergeHelper(vector<ListNode *> &lists, int a, int b) {
    if (a == b) {
      return lists[a];
    }

    int mid = (a + b) / 2;
    ListNode *l1 = mergeHelper(lists, a, mid);
    ListNode *l2 = mergeHelper(lists, mid + 1, b);

    return mergeLists(l1, l2);
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    return mergeHelper(lists, 0, lists.size() - 1);
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<vector<int>> v = stringToIntegerVectorVector(line);
    vector<ListNode *> ans;
    ans.reserve(v.size());
    for (vector<int> &t : v) {
      ans.push_back(vectorToIntLinkedList(t));
    }

    cout << linkedListToString(Solution().mergeKLists(ans)) << endl;
  }
}