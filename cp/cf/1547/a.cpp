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

bool isFWithinRange(int x, int a, int b) {
    if (x >= a && x <= b) return true;
    if (x >= b && x <= a) return true;
    return false;
}

void solve() {
    int a1, a2, b1, b2, f1, f2;
    cin >> a1 >> a2 >> b1 >> b2 >> f1 >> f2;
    // cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << f1 << " " << f2 << " " << endl;

    int ans = 0;
    if (a1 == b1 && b1 == f1) {
        if (isFWithinRange(f2, a2, b2)) {
            ans = abs(a2 - b2) + 2;
        } else {
            ans = abs(a2 - b2);
        }
    } else if (a2 == b2 && b2 == f2) {
        if (isFWithinRange(f1, a1, b1)) {
            ans = abs(a1 - b1) + 2;
        } else {
            ans = abs(a1 - b1);
        }
    } else {
        ans = abs(a1 - b1) + abs(a2 - b2);
    }
    cout << ans << "\n";
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