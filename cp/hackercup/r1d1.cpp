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

#define REP(i,a,b) for (int i = a; i <= b; i++)

vvi dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void solve() {
    int n, m;
    cin >> n >> m;
    
    auto cmp = [](pair<double, int> &left, pair<double, int> &right) {
        if (left.first != right.first)
            return left.first < right.first;
        else
            return left.second > right.second;
    };
    priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> ratios(cmp);
    long totcost = 0;
    
    bool possible = true;
    for(int i = 1; i < n; ++i, --m) {
        long ci;
        cin >> ci;
        if (ci != 0) {
            double ratio = (i * 1.0) / ci;
            ratios.emplace(ratio, i);
        }
        
        while (m <= 0) {
            if (ratios.empty()) {
                possible = false;
                m = n;
                break;
            }
            pair<double, int> top = ratios.top();
            ratios.pop();
            
            long cost = lround(top.S / top.F);
            m = i - top.S;
            if (m > 0) totcost += cost;
        }
    }
    
    if (!possible) {
        cout << -1 << "\n";
    } else {
        cout << totcost << "\n";
    }
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
