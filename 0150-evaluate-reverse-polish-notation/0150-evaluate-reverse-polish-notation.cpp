class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(string &s : tokens){
            if(s == "+"){
                long long int x = st.top();
                st.pop();
                st.top() += x;
            }
            else if(s == "-"){
                long long int x = st.top();
                st.pop();
                st.top() -= x;
            }
            else if(s == "*"){
                long long int x = st.top();
                st.pop();
                st.top() *= x;
            }
            else if(s == "/"){
                long long int x = st.top();
                st.pop();
                st.top() /= x;
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};