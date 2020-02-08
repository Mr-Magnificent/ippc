#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0;

        int currentSum = 0;
        int negSum = 0;
        int pos = 0;
        int size = gas.size();
        for (int i = 0; i < size; i++) {
            totalgas += gas[i];
            totalcost += cost[i];

            currentSum += (gas[i] - cost[i]);
            if (currentSum < 0) {
                pos = i + 1;
                negSum -= currentSum;
                currentSum = 0;
            }
        }
        if (negSum <= currentSum && pos < gas.size()) {
            return pos;
        } else {
            return -1;
        }
    }
};

int main(int argc, char** argv){
    Solution *sol = new Solution();
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << sol->canCompleteCircuit(gas, cost) << "\n";
    gas = {2,3,4};
    cost = {3,4,3};
    cout << sol->canCompleteCircuit(gas, cost) << "\n";
}