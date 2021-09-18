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

bool solve() {
    int d0, d1;
    ulong k;
    cin >> k >> d0 >> d1;
    unordered_set<int> mp;
    vector<bool> divBy3;
    for(int i = 0, sum = 0; i <= k; ++i) {
        int temp = sum * 10 + (d0 % 3);
        cout << temp << endl;
        if (mp.find(temp) != mp.end()) {
            int remainingIdx = k - i;
            // cout << remainingIdx << "; ";
            // for(int i = 0; i < divBy3.size(); ++i) cout << divBy3[i] << ", ";
            cout << " : ";
            return divBy3[remainingIdx % divBy3.size()];
        }
        mp.insert(temp);
        sum = (sum + d0) % 3;
        divBy3.push_back(sum % 3 == 0);
        temp = (sum + d1) % 3;
        d0 = d1 % 3;
        d1 = temp;
    }
    for(int i = 0; i < divBy3.size(); ++i) cout << divBy3[i] << ", ";
    cout << " : ";
    return divBy3[divBy3.size() - 1];
}

int main() {
    boost;
    int t;
    cin >> t;
    cout << t << endl;
    cin.ignore(32767, '\n');
    while (t--) {
        cout << solve() << endl;     
    }
}