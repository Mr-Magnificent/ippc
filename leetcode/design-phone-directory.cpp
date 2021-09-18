#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char ch;
    unordered_map<char, TrieNode *> m;
    vector<string> words;
    bool isWord;

    TrieNode(char ch) {
        this->ch = ch;
        m = unordered_map<char, TrieNode *>();
        isWord = false;
    }
};

TrieNode *constructTrie(string contact[], int idx, int n) {
    if (idx == n) {
        return new TrieNode(0);
    }
    
    TrieNode *root = constructTrie(contact, idx + 1, n);
    string word = contact[idx];

    TrieNode *ptr = root;
    for(char ch: word) {
        if (ptr->m.find(ch) == ptr->m.end()) {
            TrieNode *node = new TrieNode(ch);
            ptr->m[ch] = node;
        }
        ptr->words.push_back(word);
        ptr = ptr->m[ch];
    }

    ptr->isWord = true;
    return root;
}

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode *root = constructTrie(contact, 0, n);
        TrieNode *ptr = root;
        vector<vector<string>> ans;

        for(char ch: s) {
            if (ptr->m.find(ch) == ptr->m.end()) {
                break;
            }

            ptr = ptr->m[ch];
            ans.push_back(ptr->words);
        }

        while (ans.size() != s.length()) {
            vector<string> s{"0"};
            ans.push_back(s);
        }

        return ans;
    }
};