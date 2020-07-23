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
#define R reserve
#define MOD (1000*1000*1000+7)

#define REP(i,a,b) for (int i = a; i <= b; i++)

vvi dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

/*
int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        long n;
        cin >> n;
        umapii fmap;
        fmap.R(n);
        umapii f1;
        umapii f2;
        
        f1.R(n);
        f2.R(n);
        
        for(int i = 0; i < n; ++i) {
            int temp; 
            cin >> temp;
            f1[temp]++;
            fmap[temp]++;
        }
        
        for(int i = 0; i < n; ++i) {
            long temp;
            cin >> temp;
            f2[temp]++;
            fmap[temp]--;
        }
        
        for(auto iter = f1.begin(); iter != f1.end(); ++iter) {
            int val = iter->first;
            f1[val] = f1[val] - f2[val];
        }
        
        bool flag1 = true;
        
        vi t1;
        vi t2;
        t1.R(n);
        t2.R(n);
        
        for(auto iter = f1.begin(); iter != f1.end(); ++iter) {
            if ((abs(iter->S) % 2) == 1) {
                flag1 = false;
                break;
            }
            
            if ( iter->S > 0) {
                for(int i = 0; i < iter->S / 2; ++i) {
                    t1.PB(iter->F);
                } 
            } else if (iter->S < 0) {
                for(int i = 0; i < abs(iter->S) / 2; ++i) {
                    t2.PB(iter->F);
                }
            }
        }
        
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end(), greater<int>());
        
        vi a1;
        vi a2;
        a1.R(n / 2);
        a2.R(n / 2);
        
        bool flag = true;
        for(auto &num: fmap) {
            int temp = abs(num.S);
            if ((temp % 2) == 1) {
                flag = false;
                break;
            } else {
                int count = temp / 2;
                if (num.S > 0) {
                    for(int i = 0; i < count; ++i) {
                        a1.PB(num.F);
                    }
                } else if (num.S < 0) {
                    for(int i = 0; i < count; ++i) {
                        a2.PB(num.F);
                    }
                }
            }
        }
        
        if (!flag) {
            assert(flag1 == flag);
            //~ cout << -1 << "\n";
            continue;
        }
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), greater<long>());
        
        assert(a1.size() == a2.size());
        for(ui i = 0; i < a1.size(); ++i) {
            cout << a1[i] << " " << t1[i] << endl;
        }
        
        assert(a1.size() == t1.size());
        
        for(ui i = 0; i < a2.size(); ++i) {
            cout << a2[i] << " " << t2[i] << endl;
        }
        //~ assert(a2 == t2);
        
        

        ull ans = 0;
        for(ui i = 0; i < a1.size(); ++i) {
            ans += min(a1[i], a2[i]);
        }
        
        cout << endl;
     
        //~ cout << ans << "\n";
    }
}
*/


int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        long n;
        cin >> n;
        umapll fmap;
        fmap.reserve(n);
        
        long minVal = INT_MAX;
        
        for(int i = 0; i < n; ++i) {
            long temp; 
            cin >> temp;
            if (temp < minVal) {
                minVal = temp;
            }
            
            fmap[temp]++;
        }
        
        for(int i = 0; i < n; ++i) {
            long temp;
            cin >> temp;
            if (temp < minVal) {
                minVal = temp;
            }
            
            fmap[temp]--;
        }
        
        vl a1;
        vl a2;
        a1.reserve(n / 2);
        a2.reserve(n / 2);
        
        bool flag = true;
        for(auto &num: fmap) {
            int temp = abs(num.S);
            if ((temp % 2) == 1) {
                flag = false;
                break;
            } else {
                int count = temp / 2;
                if (num.S > 0) {
                    for(int i = 0; i < count; ++i) {
                        a1.PB(num.F);
                    }
                } else if (num.S < 0) {
                    for(int i = 0; i < count; ++i) {
                        a2.PB(num.F);
                    }
                }
            }
        }
        
        if (!flag) {
            cout << -1 << "\n";
            continue;
        }
        
        assert(a1.size() == a2.size());
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end(), greater<long>());
        

        ull ans = 0;
        for(ui i = 0; i < a1.size(); ++i) {
            //~ ans += min(a1[i], a2[i]);
            if (a1[i] < a2[i]) {
                ans += min(a1[i], minVal * 2);
            } else {
                ans += min(a2[i], minVal * 2);
            }
        }
     
        cout << ans << "\n";
    }
}

/*
int main() {
    boost;
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr1;
        vector<int> arr2;
        arr1.reserve(n);
        arr2.reserve(n);
        
        unordered_map<int, int> fmap;
        fmap.reserve(n);
        
        
        for(int i = 0; i < n; ++i) {
            int inp;
            cin >> inp;
            fmap[inp]++;
            arr1.PB(inp);
        }
        
        for(int i = 0; i < n; ++i) {
            int inp;
            cin >> inp;
            fmap[inp]++;
            arr2.PB(inp);
        }
        
        bool flag = true;
        for(auto &f: fmap) {
            if ((f.second & 1) == 1) {
                flag = false;
                break;
            }
        }
        
        if (!flag) {
            cout << -1 << "\n";
            continue;
        }
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            if (arr1[i] == arr2[i]) continue;
            
            if (arr1[i] != arr1[i + 1] && arr2[i] != arr2[i + 1]) {
                abort();
            }
            
            if (arr1[i] > arr2[i]) {
                ans += arr2[i];
                int swp = arr2[i + 1];
                //~ assert(arr2[i] == arr2[i + 1]);
                arr2[i + 1] = arr1[i];
                arr1[i] = swp;
            } else {
                ans += arr1[i];
                int swp = arr1[i + 1];
                //~ assert(arr1[i] == arr1[i + 1]);
                arr1[i + 1] = arr2[i];
                arr2[i] = swp;
            }
        }
        
        cout << ans << "\n";
    }
}

*/
