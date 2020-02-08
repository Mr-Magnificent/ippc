#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    queue<string> q;
    q.push("1");
    int n;
    cin >> n;
    while (n--) {
        string s = q.front();
        q.pop();
        q.push(s + "0");
        q.push(s + "1");
        cout << s << "\n";
    }
}