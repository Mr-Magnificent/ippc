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

#define REP(i,a,b) for (int i = a; i <= b; i++)

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n;
        cin >> n;
        int c5, c10;
        c5 = c10 = 0;
        bool found = false;

        for(int i = 0;  i < n; ++i) {
            int c;
            cin >> c;

            int ch = c - 5;
            if (ch == 0) {
                c5++;
            } else if (ch == 5) {
                c10++;
                c5--;
            } else if (ch == 10) {
                if (c10 >= 1) {
                    c10--;
                } else {
                    c5 -= 2;
                }
            }

            if (!found && (c5 | c10) < 0) {
                cout << "NO\n";
                found = true;
            }
        }

        if (!found) {
            cout << "YES\n";
        }
    }
}