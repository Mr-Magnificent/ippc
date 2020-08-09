#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long>> vvl;
typedef unordered_map<int, int> umapii;
typedef unordered_map<long, long> umapll;
typedef pair<int, int> pi;
typedef unsigned int ui;
typedef unsigned long ul;
typedef unsigned long long ull;

#define boost ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (1000*1000*1000+7)
#define OFST (1000*1000*1000)

#define REP(i,a,b) for (int i = a; i <= b; i++)

vvi dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void solve() {
    unordered_map<uint, uint> inter; // end => start
    vector<pair<uint, uint>> inp; // MP(start, height)
    
    int n;
    cin >> n;
    
    inp.reserve(n);
    
    for(int i = 0; i < n; ++i) {
        int p, h;
        cin >> p >> h;
        p += OFST;
        inp.emplace_back(p, h);
    }
    
    sort(inp.begin(), inp.end());
    
    for(uint i = 0; i < inp.size(); ++i) {
        //~ falls to the right
        uint front = inp[i].F + inp[i].S;
        //~ contention for forward
        if (inter.find(inp[i].F) != inter.end()) { // * extend forward
            uint dist = front - inter[inp[i].F];
            if (inter.find(front) != inter.end()) { // * check contention
                if (dist > (front - inter[front])) {
                    inter[front] = inter[inp[i].F];
                }
            } else {
                inter[front] = inter[inp[i].F];
            }
        } else if (inter.find(front) == inter.end()) {
            inter[front] = inp[i].F;
        }
        
        //~ falls to the left
        // check if forward falling reaches inp[i].F
        uint back = inp[i].F - inp[i].S;
        if (inter.find(back) != inter.end()) { // * extend prev interval
            if (inter.find(inp[i].F) != inter.end()) { // * check contention
                uint dist = inp[i].F - inter[back];
                if (dist > (inp[i].S + inp[i].F - inter[inp[i].F])) {
                    inter[inp[i].F] = inter[back];
                }
            } else {
                inter[inp[i].F] = inter[back];
            }
        } else { // * create new interval
            if (inter.find(inp[i].F) != inter.end()) { // * check contention
                if (back < inter[inp[i].F]) {
                    inter[inp[i].F] = back;
                }
            } else {
                inter[inp[i].F] = back;
            }
        }
    }
    
    uint maxDist = 0;
    for(auto &interval: inter) {
        uint dist = interval.first - interval.second;
        if (dist > maxDist) {
            maxDist = dist;
        }
    }
    
    cout << maxDist << "\n";
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();    
    }
}
