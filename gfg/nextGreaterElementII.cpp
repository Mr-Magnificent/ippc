// https://leetcode.com/problems/next-greater-element-ii/solution/
// NEXT GREATER ELEMENT (NGE)
// TIME: O(n)
// SPACE: O(n)
// COMMENTS: Use stack and solve the problem of next element

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> stk;
    vector<int> sol(nums.size(), -1);
    int totlen = nums.size();
    for (int i = 0; i < totlen * 2; i++) {
      while (!stk.empty() && nums[i % totlen] > nums[stk.top()]) {
        sol[stk.top()] = nums[i % totlen];
        stk.pop();
      }
      stk.push(i % totlen);
    }
    return sol;
  }
};


int main(int argc, char** argv) {
  Solution *sol = new Solution();
  vector<int> arr = {1, 2, 1};
  vector<int> ans = sol->nextGreaterElements(arr);

  for (int el: ans) {
    cout << el << " ";
  }
  cout << endl;
}