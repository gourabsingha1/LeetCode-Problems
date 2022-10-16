class Solution {
public:
    int myAtoi(string s) {
        string p;
        int sign = 0, zero = 0, neg = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i])){
                if(p == "" && s[i] == '0'){
                    zero = 1;
                }
                else{
                    p += s[i];
                }
            }
            else if(p == "" && !zero && s[i] == '-' || p == "" && !zero && s[i] == '+' || p == "" && i+1 < s.size() && s[i+1] == '0'){
                sign++;
                if(s[i] == '-'){
                    neg++;
                }
            }
            else if(p == "" && !sign && !zero && s[i] == ' '){
                continue;
            }
            else{
                break;
            }
        }
        if(p == "" || sign > 1){
            return 0;
        }

        // if p >= INT_MAX
        int res = INT_MIN, flagmax = 0, flagmin = 0;
        if(p.size() == 10){
            long long temp = stoll(p);
            if(temp > INT_MAX){
                flagmax = 1;
            }
        }
        else if(p.size() > 10){
            flagmax = 1;
        }

        // if p < INT_MIN
        if(p.size() <= 10){
            long long temp = stoll(p);
            if(temp > INT_MIN){
                flagmin = 1;
            }
        }

        if(flagmax){
            if(!neg){
                res = INT_MAX;
            }
        }
        else if(flagmin){
            res = stoi(p);
            if(neg){
                res *= (-1);
            }
        }
        return res;
    }
};