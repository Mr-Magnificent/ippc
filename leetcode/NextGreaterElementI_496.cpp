#include "../lib/createVector.hpp"
#include "../lib/createTree.hpp"
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> sol(nums1.size());
    unordered_map<int, int> umap;

    // map the values of array to their index of those that we are trying to find
    for(int i = 0; i < nums1.size(); i++) {
      umap[nums1[i]] = i;
    }

    // do the nge algorithm over the remaining array of nums2 
    // and when the element to be popped is present within the 
    // hashmap then, corresponding to the hashmap value store is in sol

    // stack contains indices of element in  |biggest -> bigger -> smallest

    stack<int> stk;
    for(int i = 0; i < nums2.size(); i++) {
      while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
        if (umap.find(nums2[stk.top()]) != umap.end()) {
          sol[umap[nums2[stk.top()]]] = nums2[i];
        }

        stk.pop();
      }

      stk.push(i);
    }

    while (!stk.empty()) {
      if (umap.find(nums2[stk.top()]) != umap.end()) {
        sol[umap[nums2[stk.top()]]] = -1;
      }
      stk.pop();
    }

    return sol;
  }
};

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    vector<int> nums1 = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> nums2 = stringToIntegerVector(line);

    vector<int> sol = Solution().nextGreaterElement(nums1, nums2);
    cout << integerVectorToString(sol) << endl;
  }
}