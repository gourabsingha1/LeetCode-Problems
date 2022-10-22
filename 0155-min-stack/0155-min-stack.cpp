class MinStack {
public:
    stack<int> s1, s2;
    
    void push(int val) {
        int x = val;
        if(s2.size()){
            x = min(x, getMin());
        }
        s2.push(x);
        s1.push(val);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};