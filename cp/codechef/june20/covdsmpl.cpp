#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

#define boost ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (1000*1000*1000+7)

#define REP(i,a,b) for (int i = a; i <= b; i++)

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n, p;
        cin >> n >> p;
        vvi arr(n, vi(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << 1 << i << " " << j << " " << i << " " << j;
                int temp;
                cin >> temp;
                if (temp == -1) return 0;
                arr[i][j] = temp;
            }
        }
        
        cout << 2 << "\n";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
