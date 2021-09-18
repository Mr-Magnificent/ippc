#include <bits/stdc++.h>
using namespace std;

// class MinStack {
//     stack<int> stk;
//     stack<int> mstk;
// public:
//     /** initialize your data structure here. */
//     MinStack() {
//         mstk.push(INT_MAX);
//     }
    
//     void push(int val) {
//         stk.push(val);

//         if (mstk.top() >= val) {
//             mstk.push(val);
//         }
//     }
    
//     void pop() {
//         if (mstk.top() == stk.top()) {
//             mstk.pop();
//         }
//         stk.pop();
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return mstk.top();
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
public:
    /** initialize your data structure here. */
    int min;
    stack<int> stk;
    MinStack() {
        this->min = INT_MAX;
        stk.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val - min);
        if (val < min) {
            min = val;
        }
    }
    
    void pop() {
        int temp = stk.top();
        stk.pop();

        if (temp < 0) {
            min = min - temp;
        }
    }
    
    int top() {
        if (stk.top() < 0) {
            return min;
        }
        return min + stk.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */