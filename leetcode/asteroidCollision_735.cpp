#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> stk;
    for (int asteroid : asteroids) {
      while (!stk.empty() && asteroid < 0 && stk.back() > 0 &&
             abs(asteroid) > stk.back())
        stk.pop_back();
      if (!stk.empty() && stk.back() > 0 && asteroid < 0 &&
          stk.back() == abs(asteroid)) {
        stk.pop_back();
        continue;
      }
      if (!stk.empty() && stk.back() > 0 && asteroid < 0 &&
          abs(asteroid) < stk.back())
        continue;
      stk.push_back(asteroid);
    }
    return stk;
  }
};

int main(int argc, char **argv) {
  Solution *sol = new Solution();
  vector<int> asteroids = {8, -8};
  vector<int> remAsteroids = sol->asteroidCollision(asteroids);

  for (int asteroid : remAsteroids) {
    cout << asteroid << " ";
  }
  cout << endl;
}