#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line)) {
        if (line == "42") return 0;
        cout << line << "\n";
    }
}