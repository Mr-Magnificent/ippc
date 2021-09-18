#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> stk;

        int sum = 0;
        for(int idx = 0; idx < arr.size(); ++idx) {
            while (!stk.empty() && arr[stk.back()] > arr[idx]) {
                stk.pop_back();
            }

            stk.push_back(idx);

            for(int i = stk.size() - 1; i >= 0; --i) {
                if (i == 0) {
                    sum = sum + (stk[i] + 1) * arr[stk[i]];
                } else {
                    sum = sum + (stk[i] - stk[i - 1]) * arr[stk[i]];
                }
            }
        }

        return sum;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        stack<int> stk;
        vector<int> left(arr.size(), -1);
        
        for(int i = 0; i < arr.size(); ++i) {
            if (!stk.empty() && arr[stk.top()] < arr[i])
                stk.pop();
            
            left[i] = stk.empty() ? -1 : stk.top();
            cout << left[i] << " ";
            stk.push(i);
        }
        cout << endl;
        stk = stack<int>();
        vector<int> right(arr.size(), arr.size());

        for(int i = arr.size() - 1; i >= 0; --i) {
            if (!stk.empty() && arr[stk.top()] <= arr[i])
                stk.pop();
            
            right[i] = stk.empty() ? arr.size() : stk.top();
            stk.push(i);
        }

        int count = 0;
        for(int i = 0; i < arr.size(); ++i) {
            count = (count + ((i - left[i]) * (right[i] - i) * arr[i])) % MOD;
        }

        return count;
    }
};
