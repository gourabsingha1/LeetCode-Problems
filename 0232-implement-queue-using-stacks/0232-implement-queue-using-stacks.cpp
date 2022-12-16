class MyQueue {
public:
    stack<int> p, q;
    MyQueue() {
        
    }
    void push(int x) {
        while(p.size()){
            q.push(pop());
        }
        p.push(x);
        while(q.size()){
            p.push(q.top());
            q.pop();
        }
        return;
    }
    int pop() {
        int a = p.top();
        p.pop();
        return a;
    }
    int peek() {
        return p.top();
    }
    bool empty() {
        return p.empty();
    }
};