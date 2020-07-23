#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<string, vector<pair<string, double>>> graph;

public:
  void addEdge(vector<string> &equation, double value) {
    graph[equation[0]].push_back(make_pair(equation[1], value));
    graph[equation[1]].push_back(make_pair(equation[0], 1/value));
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    graph.reserve(equations.size());

    for (int i = 0; i < equations.size(); ++i) {
      addEdge(equations[i], values[i]);
    }

    unordered_set<string> visited;
    visited.reserve(graph.size());

    vector<double> soln;
    soln.reserve(queries.size());

    for (auto &query : queries) {
      if (query[0] == query[1]) {
        if (graph.count(query[0]) == 0) soln.push_back(-1);
        else soln.push_back(1);
        continue;
      }

      auto ans = dfs(query[0], query[1], visited);
      soln.push_back(ans.first * ans.second + !ans.first * ans.second);
    }
    return soln;
  }

  pair<bool, double> dfs(string src, string &dest,
                         unordered_set<string> &visited) {
    if (src == dest) {
      return make_pair(true, 1);
    }

    visited.insert(src);
    for (auto &edge : graph[src]) {
      if (visited.count(edge.first) == 1)
        continue;

      auto result = dfs(edge.first, dest, visited);

      if (result.first == true) {
        visited.erase(src);
        return make_pair(true, result.second * edge.second);
      }
    }
    visited.erase(src);

    return make_pair(false, -1);
  }
};

