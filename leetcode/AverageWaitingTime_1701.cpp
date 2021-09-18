#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long scount = 0;

        long ctime = 0;
        for(vector<int> &cust: customers) {
            long temp = ((ctime > cust[0]) ? ctime - cust[0] : 0);
            scount += temp + cust[1];
            ctime = cust[0] + cust[1] + temp;
        }
        return scount / (double)customers.size();
    }
};