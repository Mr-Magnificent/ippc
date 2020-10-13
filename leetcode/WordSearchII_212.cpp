#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool isWordContained(vector<vector<char>>& board, int idx, const string &word, int i, int j) {
        if (idx == word.size() - 1) {
            return board[i][j] == word[word.size() - 1];
        }

        const int dir[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        board[i][j] -= 27;
        for(int k = 0; k < 4; ++k) {
            int r = i + dir[k][0];
            int c = j + dir[k][1];

            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) continue;
            if (board[r][c] == word[idx + 1]) {
                bool res = isWordContained(board, idx + 1, word, r, c);
                if (res) return res;
            }
        }

        board[i][j] += 27;
        return false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        unordered_map<char, vector<pair<int, int>>> coord;

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                char ch = board[i][j];
                coord[ch].emplace_back(make_pair(i, j));
            }
        }

        for(int i = 0; i < words.size(); ++i) {
            char ch = words[i][0];
            for(int j = 0; j < coord[ch].size(); ++j) {
                bool ret = isWordContained(board, 0, words[i], coord[ch][j].first, coord[ch][j].second);
                if (ret) {
                    sol.push_back(words[i]);
                    break;
                }
            }
        }
        return sol;
    }
};