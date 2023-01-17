class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), one = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '1'){
                one++;
            }
            else{
                res = min(res + 1, one);
            }
        }
        return res;
    }
};