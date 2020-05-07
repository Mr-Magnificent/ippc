#pragma once
#include <bits/stdc++.h>
using namespace std;

#ifndef TRAILING_SPACE
#define TRAILING_SPACE
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
#endif

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(const vector<int> &list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

vector<vector<int>> stringToIntegerVectorVector(string line) {
  vector<vector<int>> output;
  trimLeftTrailingSpaces(line);
  trimRightTrailingSpaces(line);

  string input = line.substr(1, line.length() - 2);
  stringstream ss;
  ss.str(input);
  char delim = ']';
  string row;
  while(getline(ss, row, delim)) {
    vector<int> v = stringToIntegerVector(row + "]");
    getline(ss, row, ',');
    output.push_back(v);
  }

  return output;
}

string integerVectorOfVectorToString(vector<vector<int>> &list) {
  int length = list.size();

  if (length == 0) {
    return "[]";
  }

  string result;

  for(int i = 0; i < length; i++) {
    string ret = integerVectorToString(list[i]);
    result += ret + ", ";
  }

  return "[" + result.substr(0, result.length() - 2) + "]";
}