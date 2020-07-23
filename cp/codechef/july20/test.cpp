#include <bits/stdc++.h>
using namespace std;

unsigned long long ans = ULLONG_MAX;

void getMinPairSum(vector<int> &arr1, vector<int> &arr2, unsigned int idx, unsigned long long asf) {
    if (idx == arr1.size()) {
        if (asf < ans) {
            ans = asf;
        }
        return;
    }
    
    for(unsigned int i = 0; i < arr2.size(); ++i) {
        if (arr2[i] < 0) continue;
        
        arr2[i] = -arr2[i];
        getMinPairSum(arr1, arr2, idx + 1, asf + min(arr1[idx], -arr2[i]));
        arr2[i] = -arr2[i];
    }
}

int main() {
    vector<int> arr1 {14048768, 461196098, 395330879, 74830732, 548487562, 824319621, 32299487, 304472800, 318263782, 311030529};
    vector<int> arr2 {251002109, 627870613, 565155569, 282236017, 772475516, 909314524, 803282036, 115738860, 938612645, 940344780};
    
    getMinPairSum(arr1, arr2, 0, 0);
    cout << ans << endl;
    
    
    assert(arr1.size() == arr2.size());
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());
    
    int ans = 0;
    for(unsigned int i = 0; i < arr1.size(); ++i) {
        ans += min(arr1[i], arr2[i]);
    }
    
    cout << ans << endl;
}
