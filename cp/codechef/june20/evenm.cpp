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
        
        int n;
        cin >> n;
        
        int lim = n * n;
        ll e = 1;
        ll o = 0;
        bool toggle = false;
        
        for(ll i = 1; i <= lim; ++i) {
            if (toggle) {
                cout << (e * 2) << " ";
                e++;
            } else {
                cout << (o * 2 + 1) << " ";
                o++;
            }
            
            toggle = !toggle;
            if (i % n == 0) {
                cout << "\n";
                if ((n & 1) == 0) {
                    toggle = !toggle;
                }
            }
        }
    }
}
