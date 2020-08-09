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

void dfs(vector<vector<int>> &graph, int src, int dest, vector<vector<char>> &vis) {
    if (vis[src][dest] == 'Y') return;

    vis[src][dest] = 'Y';

    for(int &nbr: graph[dest]) {
        dfs(graph, src, nbr, vis);
    }
}

void solve() {
    int n;
    cin >> n;
    
    unordered_set<int> ib; // inbound blocked
    unordered_set<int> ob; // outbound blocked

    string inp;
    
    cin.ignore(32767, '\n');
    getline(cin, inp);

    for(int i = 0; i < n; ++i) {
        if (inp[i] == 'N') ib.insert(i);
    }

    getline(cin, inp);
    for(int i = 0; i < n; ++i) {
        if (inp[i] == 'N') ob.insert(i);
    }

    vector<vector<int>> graph(n, vector<int>());
    for(int i = 1; i < n - 1; ++i) {
        if (ob.find(i) != ob.end()) continue;

        if (ib.find(i - 1) == ib.end()) {
            graph[i].push_back(i - 1);
        }

        if (ib.find(i + 1) == ib.end()) {
            graph[i].push_back(i + 1);
        }
    }

    if (ob.find(0) == ob.end() && ib.find(1) == ib.end()) {
        graph[0].push_back(1);
    }

    if (ob.find(n - 1) == ob.end() && ib.find(n - 2) == ib.end()) {
        graph[n - 1].push_back(n - 2);
    }

    vector<vector<char>> vis(n, vector<char>(n, 'N'));

    for(int i = 0; i < n; ++i) {
        dfs(graph, i, i, vis);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << vis[i][j];
        }
        cout << '\n';
    }
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":\n";
        solve();    
    }
}
