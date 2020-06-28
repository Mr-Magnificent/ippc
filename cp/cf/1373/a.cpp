#include <bits/stdc++.h>
using namespace std;

int getGCD(int a, int b) {
  while (a != 0) {
    int rem = b % a;
    b = a;
    a = rem;
  }
  return b;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    int gcd = getGCD(a, c);
    int lcm = (a * c) / gcd;
    int lim1 = lcm / a;
    int lim2 = lcm / b;

    // cout << lim1 << " " << lim2 << endl;

    int ansA = -1;
    int ansB = -1;

    for (int i = 1; i <= lim1 + 10001; ++i) {
      int b2c = ceil(i * 1.0 / b);
      if (a * i < b2c * c) {
        ansA = i;
        break;
      }
    }

    for (int i = 1; i <= lim2 + 10001; ++i) {
      int b2c = ceil(i * 1.0 / b);
      if (a * i > b2c * c) {
        ansB = b2c * b;
        break;
      }
    }

    cout << ansA << " " << ansB << "\n";
  }
}