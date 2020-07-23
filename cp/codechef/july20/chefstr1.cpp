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

#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n;
        cin >> n;
        long count = 0;
        
        int fir;
        cin >> fir;
        for(int i = 0; i < n - 1; ++i) {
            int temp; 
            cin >> temp;
            count += abs(temp - fir) - 1;
            fir = temp;
        }
        
        cout << count << "\n";
    }
}
