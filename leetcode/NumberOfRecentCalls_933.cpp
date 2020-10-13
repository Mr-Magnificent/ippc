#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    queue<int> time;
public:
    RecentCounter() {
        time = queue<int>();
    }
    
    int ping(int t) {
        time.push(t);
        while(!time.empty() && t - time.front() > 3000) time.pop();
        return time.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
