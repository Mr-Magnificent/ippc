#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  bool isSeen = false;
  unordered_map<char, TrieNode *> children;

  TrieNode() { isSeen = false; }

  TrieNode(bool seen) { this->isSeen = seen; }
};

class WordDictionary {
  TrieNode *root;

public:
  /** Initialize your data structure here. */
  WordDictionary() { root = new TrieNode(); }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode *ptr = this->root;

    int strLen = word.length();

    // * add the nodes for all characters except the last character
    for (int i = 0; i < strLen - 1; i++) {

      char ch = word[i];
      // * check if the child node exists for 'ch', update ptr incase yes
      if (ptr->children.find(ch) != ptr->children.end()) {
        ptr = ptr->children[ch];
      }
      // * create a trieNode and set that as the child and update ptr
      else {
        TrieNode *temp = new TrieNode();
        ptr->children[ch] = temp;
        ptr = temp;
      }
    }

    char ch = word[word.length() - 1];
    // * now set for the last character of the string
    if (ptr->children.find(ch) != ptr->children.end()) {
      ptr = ptr->children[ch];
      ptr->isSeen = true;
    } else {
      TrieNode *temp = new TrieNode(true);
      ptr->children[ch] = temp;
    }
  }

  /** Returns if the word is in the data structure.
   * A word could contain the dot character '.' to represent any one letter.
   */
  bool search(string word) { return dfs(root, word); }

private:
  bool dfs(const TrieNode *node, string word) {
    // * if node is present and we have reached the end of word
    if (node && word.length() == 0) {
      return node->isSeen;
    } else if (!node) {
      return false;
    }

    char ch = word[0];
    string ros = word.substr(1);

    if (ch == '.') {

      bool find = false;
      for (auto it = node->children.begin(); it != node->children.end(); it++) {
        find |= dfs(it->second, ros);
      }
      return find;

    } else {

      if (node->children.find(ch) != node->children.end()) {
        return dfs(node->children.at(ch), ros);
      }
    }

    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char **argv) {
  WordDictionary wd;
  wd.addWord("bad");
  wd.addWord("dad");
  wd.addWord("mad");

  cout << wd.search(".ad") << endl;
  cout << wd.search("sda") << endl;
  cout << wd.search("ba.") << endl;
  cout << wd.search("dad") << endl;
  cout << wd.search("dada") << endl;
}