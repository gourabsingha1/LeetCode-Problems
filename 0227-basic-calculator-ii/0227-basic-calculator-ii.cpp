class Solution {
public:
    int calculate(string s) {
        int i = 0;
        deque<int> dq;
        deque<char> ch;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ') i++;
            int temp = 0;
            while(i<s.size() && isdigit(s[i])){
                temp = temp*10 + (s[i++] - '0');
            }

            if(ch.size() && ch.back() == '*' || ch.size() && ch.back() == '/'){
                int into = 0;
                if(ch.back() == '*') into = 1;
                ch.pop_back();
                if(into) dq.back() *= temp;
                else dq.back() /= temp;
            }
            else if(temp || s[i-1] == '0') dq.push_back(temp);
            
            if(i<s.size() && s[i] != ' '){
                ch.push_back(s[i++]);
            }
        }
        for (i = 1; i < dq.size(); i++)
        {
            if(ch.front() == '+'){
                dq[i] += dq[i-1];
            }
            else{
                dq[i] = dq[i-1] - dq[i];
            }
            ch.pop_front();
        }
        return dq[dq.size()-1];
    }
};