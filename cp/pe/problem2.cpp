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


int main() {
    boost;
    ul a = 2;
    ul b = 8;
    ul sum = 0;
    
    while (a < 4000000) {
        ui c = 4 * b + a;
        sum += a;
        a = b;
        b = c;
    }
    
    cout << sum << endl;
    return 0;
}
