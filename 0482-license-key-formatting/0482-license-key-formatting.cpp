class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for (int i = s.size() - 1, cnt = 0; i >= 0; i--)
        {
            if(isalnum(s[i])) {
                char ch = s[i];
                if(islower(ch)) {
                    ch = toupper(ch);
                }
                if(cnt == k) {
                    res += '-';
                    cnt = 0;
                }
                res += ch;
                cnt++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};