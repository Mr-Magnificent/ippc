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
    multimap<ulong, ulong> inter;
    vector<pair<uint, uint>> trees;
    
    uint n;
    cin >> n;
    
    trees.reserve(n);
    
    for(uint i = 0; i < n; ++i) {
        uint p, h;
        cin >> p >> h;
        p += OFST;
        trees.emplace_back(p, h);
    }
    
    sort(trees.begin(), trees.end());
    
    //~ tree can swing both ways
    //~ for each side choose largest combined interval
    //~ and then mark that as the interval for the current trees
    //~ better greedy to have a larger interval with same start/end
    for(uint i = 0; i < n; ++i) {
        //~ tree falling right
        //~ end := pi + hi (pi != end, hi >= 1)
        ulong start = trees[i].F;
        ulong minStart = trees[i].F;
        auto itr1 = inter.lower_bound(start);
        auto itr2 = inter.upper_bound(start);
        
        while (itr1 != itr2) {
            if (itr1->second < minStart) {
                minStart = itr1->second;
            }
            itr1++;
        }
        
        ulong end = trees[i].F + trees[i].S;
        //~ inter[end] = (ulong)minStart;
        inter.insert(MP(end, minStart));

        //~ tree falling left
        //~ end := pi (start != end)
        start = trees[i].F - trees[i].S;
        // find minimum start among those which end at start
        minStart = start;
        itr1 = inter.lower_bound(start);
        itr2 = inter.upper_bound(start);
        
        while (itr1 != itr2) {
            if (itr1->second < minStart) {
                minStart = itr1->second;
            }
            itr1++;
        }
        
        end = (ulong)trees[i].F;
        //~ inter[(ulong)trees[i].F] = minStart;
        inter.insert(MP(end, minStart));
    }
    
    ulong maxti = 0;
    for(auto &range: inter) {
        ulong ti = range.F - range.S;
        if (ti > maxti) {
            maxti = ti;
        }
    }
    
    cout << maxti << "\n";
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
