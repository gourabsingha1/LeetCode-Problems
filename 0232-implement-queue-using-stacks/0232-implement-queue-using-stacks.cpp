class MyQueue {
public:
    stack<int> p, q;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        p.push(x);
        return;
    }
    
    int pop() {
        int x = peek();
        q.pop();
        return x;
    }
    
    int peek() {
        if(!q.size()) {
            while(p.size()) {
                q.push(p.top());
                p.pop();
            }
        }
        return q.top();
    }
    
    bool empty() {
        return !p.size() && !q.size();
    }
};