class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int res = 0;
        for(char &c : s){
            if(c == '('){
                st.push(res);
                res = 0;
            }
            else{
                int x = st.top();
                st.pop();
                res = x + max(2*res, 1);
            }
        }
        return res;
    }
};