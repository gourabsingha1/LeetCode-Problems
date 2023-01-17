class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), zero = 0, curr = 0, res = INT_MAX;
        for (int i = 0; i < n; i++) if(s[i] == '0') zero++;
        for (int i = 0; i < n; i++)
        {
            res = min(res, zero);
            if(s[i] == '1'){
                zero++;
            }
            else{
                zero--;
            }
            res = min(res, zero);
        }
        return res;
    }
};