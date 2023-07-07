class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            int cnt = 0;
            for (int i = 0, j = 0; i < s.size(); i++)
            {
                if(s[i] != ch) {
                    cnt++;
                }
                while(cnt > k) {
                    if(s[j] != ch) {
                        cnt--;
                    }
                    j++;
                }
                int size = i - j + 1;
                res = max(res, size);
            }
        }
        return res;
    }
};