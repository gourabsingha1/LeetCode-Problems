class Solution {
public:
    int countHomogenous(string s) {
        int cnt = 1, res = 1, M = 1e9 + 7;
        for (int i = 1; i < s.size(); i++)
        {
            if(s[i - 1] == s[i]) cnt++;
            else cnt = 1;
            res = (res + cnt) % M;
        }
        return res;
    }
};