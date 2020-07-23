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
#define MOD (1000*1000*1000+7)

#define REP(i,a,b) for (int i = a; i <= b; i++)

int getsum(int n) {
    int count = 0;
    while (n != 0) {
        count += n % 10;
        n /= 10;
    }
    return count;
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n;
        cin >> n;
        
        int cw = 0, mw = 0;
        for(int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            
            int asum = getsum(a);
            int bsum = getsum(b);
            
            if (asum > bsum) {
                cw++;
            } else if (asum < bsum) {
                mw++;
            } else {
                cw++;
                mw++;
            }
        }
        
        if (cw > mw) {
            cout << 0 << " " << cw << "\n";
        } else if (cw < mw) {
            cout << 1 << " " << mw << "\n";
        } else {
            cout << 2 << " " << mw << "\n";
        }
    }
}
