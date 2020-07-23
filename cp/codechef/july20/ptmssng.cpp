#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi; 

#define boost ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EM emplace
#define EB emplace_back
#define x first
#define y second
#define MOD (1000*1000*1000+7)

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

pair<int, int> getPair(pair<int, int> &point, unordered_set<pi, pair_hash> &cord) {
    for(auto it = cord.begin(); it != cord.end(); ++it) {
        if (*it != point) {
            return *it;
        }
    }
    
    return pi{0, 0};
}

#define REP(i,a,b) for (int i = a; i <= b; i++)

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n;
        cin >> n;
        
        int x = 0;
        int y = 0;
        
        for(int i = 0; i < (n << 2) - 1; ++i) {
            int a, b;
            cin >> a >> b;
            x ^= a;
            y ^= b;
        }
        
        cout << x << " " << y << "\n";
    }
}
