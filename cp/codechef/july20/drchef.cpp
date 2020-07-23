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

vvi dir {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int days(int pop, ll &x) {
    int ci = pop; //current infected = population
    
    int prvi = ci; // previous infected
    ci = max(ci - x, 0ll);
    int cured = prvi - ci;
    x = cured << 1;
    ci = min(ci * 2, pop);
    
    return ci;
}
        

int solve() {
    int n;
    ll x;
    
    cin >> n >> x;
    multiset<int> es; // element set


    for(int i = 0; i < n; ++i) {
        int pop;
        cin >> pop;
        es.insert(pop);
    }
    
    
    ll totalDays = 0;
    while (!es.empty()) {
        auto inf = es.lower_bound(x);
        if (inf == es.end()) {
            --inf;
        }
        int ci = days(*inf, x);
        es.erase(inf);
        if (ci != 0) es.insert(ci);
        totalDays++;
    }
        
    
    cout << totalDays << "\n";
    return totalDays;
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        solve();    
    }
}
