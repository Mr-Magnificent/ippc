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
    int n;
    cin >> n;
    cin.ignore(32767, '\n');
    vector<int> arr;
    arr.resize(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long gans = 0, ans = 0;
    int len = arr.size();

    for(int i = 0; i < len; ++i) {
        ans = (long long)(len - i) * arr[i];
        gans = max(gans, ans);
    }

    cout << gans << endl;
}