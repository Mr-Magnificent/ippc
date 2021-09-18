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
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n + m);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    bool possible = true;
    for (int l = 0; l < c.size(); ++l) {
        if (i < a.size() && a[i] == 0) {
            c[l] = a[i];
            i++;
            k++;
        } else if (j < b.size() && b[j] == 0) {
            c[l] = b[j];
            j++;
            k++;
        } else {
            if (i < a.size() && a[i] <= k) {
                c[l] = a[i];
                i++;
            } else if (j < b.size() && b[j] <= k) {
                c[l] = b[j];
                j++;
            } else {
                possible = false;
                break;
            }
        }
    }

    if (!possible) {
        cout << -1 << "\n";
    } else {
        for(int l = 0; l < c.size(); ++l) {
            cout << c[l] << " ";
        }
        cout << "\n";
    }
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