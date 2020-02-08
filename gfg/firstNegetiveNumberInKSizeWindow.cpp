#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  vector<int> arr = {-8, 2, 3, -6, 10};
  int k = 2;
  int ptr = -1;

  for (int i = arr.size() - 1; i > arr.size() - k; i--) {
    if (arr[i] < 0)
      ptr = i;
  }

  for (int i = arr.size() - 1 - k; i >= 0; i--) {
    if (arr[i] < 0)
      ptr = i;

    if (ptr == -1)
      cout << 0 << " ";

    if (ptr - i < k)
      
  }
  cout << endl;
}