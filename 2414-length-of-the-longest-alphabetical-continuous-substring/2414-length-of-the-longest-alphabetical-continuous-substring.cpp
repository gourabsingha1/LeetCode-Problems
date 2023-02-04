class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1, cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if(s[i] - s[i - 1] == 1){
                cnt++;
            }
            else{
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};