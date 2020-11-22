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
        string line;
        int arr[26] {};
        getline(cin, line);
        int len = line.length();
        for(int i = 0; i < len / 2; ++i) ++arr[line[i] - 'a'];
        for(int i = len % 2 == 0 ? len / 2 : len / 2 + 1; i < len; ++i) --arr[line[i] - 'a'];
        bool isLapin = true;
        for(int i = 0; isLapin && i < 26; ++i) isLapin = (arr[i] == 0);
        cout << (isLapin ? "YES\n" : "NO\n");
    }
}