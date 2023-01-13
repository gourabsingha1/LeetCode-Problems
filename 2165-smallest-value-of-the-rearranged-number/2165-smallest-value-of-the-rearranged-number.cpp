class Solution {
public:
    long long smallestNumber(long long num) {
        long long res = 0;
        string s = to_string(num);
        sort(s.begin(), s.end());
        if(num >= 0){
            if(s[0] == '0' && num){
                int j = 1;
                while(s[j] == '0') j++;
                s[0] = s[j], s[j] = '0';
            }
            for (int i = 0; i < s.size(); i++)
            {
                res = res*10 + s[i] - '0';
            }
        }
        else{
            for (int i = 0; i < s.size() - 1; i++)
            {
                res = res*10 + s[s.size() - 1 - i] - '0';
            }
            res *= -1;
        }
        return res;
    }
};