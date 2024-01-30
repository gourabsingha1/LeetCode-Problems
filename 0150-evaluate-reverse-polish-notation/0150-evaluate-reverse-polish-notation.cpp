// brute force stack

class Solution {
public:
    stack<long long> st;
    
    void operation(string& s) {
        long long x = st.top();
        st.pop();
        if(s == "+") {
            st.top() += x;
        }
        else if(s == "-") {
            st.top() -= x;
        }
        else if(s == "*") {
            st.top() *= x;
        }
        else {
            st.top() /= x;
        }
    }

    int evalRPN(vector<string>& tokens) {
        for(string& s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                operation(s);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};