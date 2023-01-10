class FreqStack {
public:
    unordered_map<int, int> m;
    unordered_map<int, stack<int>> mStack;
    int maxFreq = 0;
    
    void push(int val) {
        m[val]++;
        maxFreq = max(maxFreq, m[val]);
        mStack[m[val]].push(val);
    }
    
    int pop() {
        int x = mStack[maxFreq].top();
        mStack[maxFreq].pop();
        m[x]--;
        if(!mStack[maxFreq].size()){
            maxFreq--;
        }
        return x;
    }
};