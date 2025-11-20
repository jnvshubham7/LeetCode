/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:

  stack<int> st1;
    stack<int> st2;
    MinStack() {




        
    }
    
    void push(int val) {

        st1.push(val);
        if(st2.empty() || val <= st2.top()){
            st2.push(val);
        }
        
    }
    
    void pop() {
        
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
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
// @lc code=end

