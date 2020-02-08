#include <bits/stdc++.h>
using namespace std;

class Solution {
  static bool comp(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) {
      return a[1] < b[1];
    } else
      return a[0] < b[0];
  }

public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(), comp);

    int courseCount = 0, currTime = 0;
    for (vector<int> &course : courses) {
      if (currTime + course[0] <= course[1]) {
        cout << course[0] << " " << course[1] << endl;
        courseCount++;
        currTime += course[0];
      }
    }
    return courseCount;
  }
};

int main(int argc, char **argv) {
  vector<vector<int>> arr = {{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
  Solution *sol = new Solution();
  cout << sol->scheduleCourse(arr) << endl;
}