#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long unsigned int lui;

#define boost ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (1000*1000*1000+7)

#define REP(i,a,b) for (int i = a; i < b; i++)

vvi dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int bfs(vvi &board, int k) {
    queue<int> que;
    que.push(0);
    
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        
        int r = idx / 8;
        int c = idx % 8;
        
        if (board[r][c] == 1 || board[r][c] == 2) {
            continue;
        }
        
        if (k == 0) {
            board[r][c] = 2;
            continue;
        } else {
            board[r][c] = 1;
        }
        
        k--;
        
        for(lui i = 0; i < dir.size(); ++i) {
            int tr = r + dir[i][0];
            int tc = c + dir[i][1];
            
            if (tr < 0 || tr >= 8 || tc < 0 || tc >= 8 || board[tr][tc] == 1 || board[tr][tc] == 2) {
                continue;
            }
            
            que.push(tr * 8 + tc);
        }
    }
    return k;
}

void display(vvi &board) {
    for(lui i = 0; i < board.size(); ++i) {
        for(lui j = 0; j < board[0].size(); ++j) {
            if (i == 0 && j == 0) {
                cout << 'O';
            } else if (board[i][j] == 1 || board[i][j] == 0) {
                cout << '.';
            } else  {
                cout << 'X';
            }
        }
        cout << "\n";
    }
}

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        vvi board(8, vi(8, 0));
        int k;
        cin >> k;
        
        bfs(board, k);
        display(board);
        //~ cout << "\n";
    }
}
