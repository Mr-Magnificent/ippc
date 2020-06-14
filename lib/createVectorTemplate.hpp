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

#ifndef LIST_NODE
#define LIST_NODE
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

template<class T>
vector<T> stringToTypeVector(string input) {
    vector<T> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(getFromType<T>(item));
    }
    return output;
}

template<class T>
T getFromType(string item) {
  if (is_same_v(T, int)) return stoi(item);
  else if (is_same_v(T, char)) return item;
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

template<class T>
vector<vector<T>> stringToTypeVectorVector(string line) {
  vector<vector<T>> output;
  trimLeftTrailingSpaces(line);
  trimRightTrailingSpaces(line);

  string input = line.substr(1, line.length() - 2);
  stringstream ss;
  ss.str(input);
  char delim = ']';
  string row;
  while(getline(ss, row, delim)) {
    vector<T> v = stringToTypeVector<T>(row + "]");
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}
