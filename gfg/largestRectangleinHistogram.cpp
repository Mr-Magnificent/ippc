/**
 * TIME: O(n)
 * SPACE: O(n)
 * COMMENTS: Iterate over the complete histogram and try to create
 * the maximum area with heights[i] for 0 <= i <= heights.size().
 * Find the nextSmallerElement and the prevSmallerElement and the
 * window within that contains the largest Area for that height.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> stk;
    heights.push_back(0);
    int len = heights.size();
    int maxArea = 0;

    for (int i = 0; i < len; i++) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        int height = heights[stk.top()];
        stk.pop();
        int areaLength = stk.empty() ? -1 : stk.top();
        maxArea = max(maxArea, height * (i - areaLength - 1));
      }
      stk.push(i);
    }
    return maxArea;
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  vector<int> lsr = {4, 2, 3};
  int ans = sol->largestRectangleArea(lsr);
  cout << ans << endl;
}