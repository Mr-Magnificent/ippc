#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        {
            lock_guard<mutex> lg(m);
            index[val].insert(arr.size());
            arr.push_back(val);
        }
        return index[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (index[val].size() == 0) return false;

        {
            lock_guard<mutex> lg(m);
            // remove the key from the key -> position index
            int idx = *(index[val].begin());
            index[val].erase(idx);
            if (idx != arr.size() - 1) {
                // replace with the last element
                arr[idx] = arr[arr.size() - 1];
                // overwrite the position for element at the last index
                index[arr[idx]].erase(arr.size() - 1);
                index[arr[idx]].insert(idx);
            }
            // remove the element at last
            arr.pop_back();
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
private:
    unordered_map<int, unordered_set<int>> index;
    vector<int> arr;
    mutex m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */