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

//~ int main() {
    //~ boost;
    //~ int t;
    //~ cin >> t;
    //~ cin.ignore(32767, '\n');
    //~ while (t--) {
        //~ ll ts;
        //~ cin >> ts;
        //~ ll tfb = (ts ^ (ts - 1));
        //~ ll count = 0;
        //~ for(int i = 1; i <= ts; ++i) {
            //~ ll jfb = (i ^ (i - 1));

            //~ if (jfb > tfb) {
                //~ // jerry wins the game
                //~ cout << i << endl;
                //~ count++;
            //~ } else if (jfb < tfb) {
                //~ // tom wins
            //~ } else {
                //~ //tie
            //~ }
        //~ }

        //~ // cout << count << "\n";
    //~ }
//~ }

int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        ll ts;
        cin >> ts;
        //~ if ((ts & (ts - 1)) == 0) {
            //~ continue;
        //~ }
        ll tfb = ((ts & -ts) << 1);
        ll count = 0;
        count = ts/tfb - (tfb+1)/tfb + 1;
        cout << count << "\n";
    }
}

