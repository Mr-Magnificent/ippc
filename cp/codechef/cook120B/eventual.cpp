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

int solve() {
    int n;
    cin >> n;

    cin.ignore(1000, '\n');
    string str;
    getline(cin, str);
    
    vector<int> freq(26, 0);
    
    for(int i = 0; i < n; ++i) {
        freq[str[i] - 'a']++;
    }
    
    bool ans = true;
    for(int i = 0; i < 26; ++i) {
        if ((freq[i] & 1) == 1) {
            ans = false;
            break;
        }
    }
    
    if (ans == true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
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
