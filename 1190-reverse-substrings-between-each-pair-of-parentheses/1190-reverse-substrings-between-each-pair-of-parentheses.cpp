class Solution {
public:
    string reverseParentheses(string s) {
        string st, p;
        for(char &c : s){
            if(c != ')'){
                st.push_back(c);
            }
            else{
                while(st.back() != '('){
                    p += st.back();
                    st.pop_back();
                } st.pop_back();
                st.append(p);
                p = "";
            }
        }
        return st;
    }
};