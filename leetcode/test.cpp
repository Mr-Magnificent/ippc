#include <iostream>
using namespace std;
#include <vector>

bool print();

vector<vector<char>> board{{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

vector<string> words = {"agra", "norway", "england", "gwalior"};

bool canPlaceH(int r, int c, string &word) {
  for (int i = 0; i < word.length(); i++) {
    if ((c + i) < board[0].size() && board[r][c + i] != '-' &&
        board[r][c + i] != word[i]) {
      return false;
    }
  }
  return true;
}
// 9013369678
vector<bool> placeH(int r, int c, string &word) {
  vector<bool> mark(word.length(), false);
  for (int i = 0; i < word.length(); i++) {
    if (board[r][c + i] == '-') {
      mark[i] = true; // idhar apne == kar rakha tha
      board[r][c + i] = word[i];
    }
  }
  return mark;
}

void unPlaceH(int r, int c, string &word, vector<bool> &mark) {
  for (int i = 0; i < word.length(); i++) {
    if (mark[i]) {
      board[r][c + i] = '-';
    }
  }
}

bool canPlaceV(int r, int c, string &word) {
  for (int i = 0; i < word.length(); i++) {
    if ((r + i) < board.size() && board[r + i][c] != '-' &&
        board[r + i][c] != word[i]) {
      return false;
    }
  }
  return true;
}

vector<bool> placeV(int r, int c, string &word) {
  vector<bool> mark(word.length(), false);
  for (int i = 0; i < word.length(); i++) {
    if (board[r + i][c] == '-') {
      mark[i] = true;
      board[r + i][c] = word[i]; // idhar apne == kar rakha tha
    }
  }
  return mark;
}

void unPlaceV(int r, int c, string word, vector<bool> &mark) {

  for (int i = 0; i < word.length(); i++) {
    if (mark[i]) {
      board[r + i][c] = '-';
    }
  }
}

bool print() {
  for (vector<char> &ar : board) {
    for (char ch : ar)
      cout << ch << " ";
    cout << endl;
  }
  return true;
}

bool crossWord_(int idx) {
  if (idx == words.size()) {
    return print();
    return true;
  }

  string word = words[idx];
  bool res = false;

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '-' || board[i][j] == word[0]) {
        if (canPlaceH(i, j, word)) {
          vector<bool> mark = placeH(i, j, word);

          res = res || crossWord_(idx + 1);
          unPlaceH(i, j, word, mark);
        }

        if (canPlaceV(i, j, word)) {
          vector<bool> mark = placeV(i, j, word);
          res = res || crossWord_(idx + 1);
          unPlaceV(i, j, word, mark);
        }
      }
    }
  }

  return res;
}

int main() {
  cout << crossWord_(0) << endl;
  return 0;
}
