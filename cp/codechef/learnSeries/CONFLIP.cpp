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

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int g;
        cin >> g; 
        while (g--) {
            int n, i, q;
            cin >> i >> n >> q;

            if (n % 2 == 0) {
                cout << n / 2 << "\n";
            } else {
                if (i == q) cout << n / 2 << "\n";
                else cout << (int)ceil(n / 2.0) << "\n";
            }
        }
    }
}