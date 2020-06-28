#include "../lib/createVector.hpp"

#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  int getGCD(int a, int b) {
    while (b != 0) {
      int rem = a % b;
      a = b;
      b = rem;
    }

    return a;
  }

  bool isDuplicate(vector<int> &x, vector<int> &y) {
    return (x[0] == y[0] && x[1] == y[1]);
  }

public:
  int maxPoints(vector<vector<int>> &points) {
    if (points.size() == 0) {
      return 0;
    }

    unordered_map<string, int> sc; // slopeCount;
    int maxCount = 0;
    for (int i = 0; i < points.size(); ++i) {
      sc.clear();
      int duplicates = 0;
      // count duplicates of the same point in the points array
      for (int j = i + 1; j < points.size(); ++j) {
        if (isDuplicate(points[i], points[j]))
          duplicates++;
      }

      maxCount = max(maxCount, duplicates);

      for (int j = i + 1; j < points.size(); ++j) {
        if (isDuplicate(points[i], points[j]))
          continue;
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];

        int gcd = getGCD(abs(dx), abs(dy));
        if (gcd > 1) {
          dx /= gcd;
          dy /= gcd;
        }

        int sign = (dx ^ dy) < 0 ? -1 : 1;
        string slope;
        if (dx == 0)
          slope = to_string(dx) + "*";
        else if (dy == 0)
          slope = "*" + to_string(dy);
        else
          slope = to_string(sign * abs(dx)) + "*" + to_string(abs(dy));
        // cout << points[i][0] << " " << points[i][1] << ", " << points[j][0]
        //      << " " << points[j][1] << "; ";
        // cout << slope << endl;
        sc[slope]++;
        maxCount = max(maxCount, sc[slope] + duplicates);
      }
    }

    return maxCount + 1;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<vector<int>> points = stringToIntegerVectorVector(line);
    cout << Solution().maxPoints(points) << endl;
  }
}