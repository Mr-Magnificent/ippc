#include <bits/stdc++.h>
using namespace std;

class TimeMap {
  unordered_map<string, vector<pair<int, string>>> tmap;

public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    tmap[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {
    if (tmap.find(key) == tmap.end())
      return "";

    vector<pair<int, string>> &timeStamps = tmap[key];
    int lo = 0, hi = timeStamps.size() - 1;

    int idx = -1;
    while (lo <= hi) {
      int mid = hi - (hi - lo) / 2;
      if (timeStamps[mid].first > timestamp) {
        hi = mid - 1;
      } else if (timeStamps[mid].first < timestamp) {
        idx = mid;
        lo = mid + 1;
      } else {
        idx = mid;
        break;
      }
    }

    if (idx == -1)
      return "";
    return timeStamps[idx].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */