#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char **argv) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll sum = 0;
        for (int i = arr.size() - 2; i >= 0; i--) {
            ll temp = arr[i] + arr[i + 1];
            sum = max(temp, sum);
        }
        cout << sum << "\n";
    }
}