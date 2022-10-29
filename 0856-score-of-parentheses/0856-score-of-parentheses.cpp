class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(i < s.size()-1 && s.substr(i,2) == "()"){
                if(st.size() && st.top() != '('){
                    st.top()++;
                    sum = 0;
                }
                else{
                    sum++;
                }
                i++;
            }
            else if(s[i] == '('){
                if(sum){
                    st.push(sum);
                    sum = 0;
                }
                st.push('(');
            }
            else if(s[i] == ')'){
                while(st.size() && st.top() != '('){
                    sum += st.top();
                    st.pop();
                }
                if(sum){
                    st.push(sum);
                }
                sum = 0;
                if(st.size() > 1){
                    int x = st.top()*2;
                    st.pop();
                    st.pop();
                    st.push(x);
                }
            }
        }
        while(st.size()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};