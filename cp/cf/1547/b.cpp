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

string solve() {
    string s;
    cin >> s;

    int i = 0, j = 0;
    for(int k = 0; k < s.length() && s[k] != 'a';++k, ++i, ++j);
    if (i == s.length()) return "No";
    --i, ++j;

    for(char k = 'b'; k <= 'z' && (i >= 0 || j < s.length()); ++k) {
        bool found = false;
        if (i>= 0 && s[i] == k) {
            found = true;
            --i;
        } else if (j < s.length() && s[j] == k) {
            found = true;
            ++j;
        }

        if (!found) return "No";
    }
    return "Yes";
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        cout << solve() << "\n";
    }
}