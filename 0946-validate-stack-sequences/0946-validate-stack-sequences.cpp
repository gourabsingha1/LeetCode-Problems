class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size(), j = 0;
        for (int i = 0; i < n && j < n; i++)
        {
            st.push(pushed[i]);
            while(st.size() && j < n && st.top() == popped[j]) {
                st.pop(), j++;
            }
        }
        return st.empty() && j == n;
    }
};