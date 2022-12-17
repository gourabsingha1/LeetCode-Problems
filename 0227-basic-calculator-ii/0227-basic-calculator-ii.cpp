class Solution {
public:
    int calculate(string s) {
        int res = 0, i = 0;
        stack<string> st;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ') i++;
            string temp;
            while(i<s.size() && isdigit(s[i])){
                temp += s[i++];
            }

            if(st.size() && st.top() == "*" || st.size() && st.top() == "/"){
                int into = 0;
                if(st.top() == "*") into = 1;
                st.pop();
                int x = stoi(st.top());
                if(into) x *= stoi(temp);
                else x /= stoi(temp);
                st.top() = to_string(x);
            }
            else if(temp.size()){
                st.push(temp);
            }
            
            if(i<s.size() && s[i] != ' '){
                string p(1, s[i++]);
                st.push(p);
            }
        }
        stack<string> p;
        while(st.size()){
            p.push(st.top());
            st.pop();
        }
        while(p.size() > 1){
            int x = stoi(p.top()), add = 0;
            p.pop();
            if(p.top() == "+") add = 1;
            p.pop();
            if(add) p.top() = to_string(x + stoi(p.top()));
            else p.top() = to_string(x - stoi(p.top()));
        }
        return stoi(p.top());
    }
};