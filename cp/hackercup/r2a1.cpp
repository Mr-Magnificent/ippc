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

struct box {
    int l;
    int h;
};

int solve() {
    int n, k, w;
    cin >> n >> k >> w;
    vector<box> boxes;

    boxes.resize(n);

    for(int i = 0; i < k; ++i) {
        cin >> boxes[i].l;
    }

    ul al, bl, cl, dl;
    cin >> al >> bl >> cl >> dl;

    for(int i = 0; i < k; ++i) {
        cin >> boxes[i].h;
    }

    ul ah, bh, ch, dh;
    cin >> ah >> bh >> ch >> dh;

    for(int i = k; i < n; ++i) {
        int val = (int)(((al * boxes[i - 2].l % dl) + (bl * boxes[i - 1].l % dl) + cl) % dl);
        boxes[i].l = val;
    }

    for(int i = k; i < n; ++i) {
        int val = (int)(((ah * boxes[i - 2].h % dh) + (bh * boxes[i - 1].h % dh) + ch) % dh);
        boxes[i].h = val;
    }

    vector<box> prevBoxes;

    ulong ans = 1;
    ulong peri = 0;
    for(int i = 0; i < n; ++i) {
        // remove any dead boxes
        if (!prevBoxes.empty()) {
            if (prevBoxes.back().l + w < boxes[i].l) prevBoxes = {};
        }

        // calculate the perimeter
        if (prevBoxes.empty()) {
            peri = (peri % MOD + (2 * w + 2 * boxes[i].h) % MOD) % MOD;
            ans = ((ans % MOD) * peri) % MOD; 
        } else {
            if (prevBoxes.back().h <= boxes[i].h) {

            } else {

            }
        }

        // add this box and remove smaller boxes
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
