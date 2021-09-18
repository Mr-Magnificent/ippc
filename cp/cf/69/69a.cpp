#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define boost ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007

#define REP(i,a,b) for (int i = a; i <= b; i++)

void solve() {
    
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    int x, y, z;
    x = y = z = 0;
    while (t--) {
        // solve();
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        x += t1, y += t2, z += t3;
    }
    if ((x | y | z) == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}